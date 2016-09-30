#include "DropDownListWidget.h"
#include "ui_DropDownListWidget.h"

#include "Global.h"

#include <QApplication>
#include <QFocusEvent>

#include "DuowanAnswerRequest.h"
#include "AnswerResponse.h"
#include "AnswerItem.h"

DropDownListWidget::DropDownListWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DropDownListWidget)
{
    ui->setupUi(this);

    setWindowFlags(Qt::WindowStaysOnTopHint);

    ConfigUi();
    ConnectObjects();
}

DropDownListWidget::~DropDownListWidget()
{
    delete ui;
}

void DropDownListWidget::ConnectObjects()
{
    connect(qApp, SIGNAL(applicationStateChanged(Qt::ApplicationState)), this, SLOT(onApplicationStateChanged(Qt::ApplicationState)));
}

void DropDownListWidget::ConfigUi()
{
    connect(ui->inputLineEdit, SIGNAL(textEdited(QString)), this, SLOT(onInputLineEditTextChanged(QString)));
}

void DropDownListWidget::onContentListComboBoxEditTextChanged(const QString &text)
{
    onGetAnswer(text);
}

void DropDownListWidget::onInputLineEditTextChanged(const QString &text)
{
    onGetAnswer(text);
}

void DropDownListWidget::onGetAnswer(const QString &pinyin)
{
    DuowanAnswerRequest *request = new DuowanAnswerRequest(pinyin);
    mLastRequestId = request->Id();
    connect(request, SIGNAL(responseReady(AnswerResponse*)), this, SLOT(onAnswerResponseReady(AnswerResponse*)));
    request->Request();
}

void DropDownListWidget::onAnswerResponseReady(AnswerResponse *response)
{
    ui->contentListWidget->clear();

    if (response->RequestId() == mLastRequestId)
    {
        if (response->Error() == AnswerResponse::NoError)
        {
            AnswerItem aItem;
            Q_FOREACH(aItem, response->Items())
            {
                QString itemString = QString("[%1]----%2").arg(aItem.Answer()).arg(aItem.Qustion());
                ui->contentListWidget->addItem(itemString);
            }
        }
        else
        {
            QString errorString;

            switch (response->Error())
            {
            case AnswerResponse::ErrorJsonParse:
                errorString = "Cannot find the question with this pinyin.";
                break;
            case AnswerResponse::ErrorNetworkFailed:
                errorString = "Network issue.";
                break;

            default:
                errorString = "Unknow error from duowan.com";
                break;
            }

            ui->contentListWidget->addItem(errorString);

            QApplication::beep();
        }
    }

    response->Request()->deleteLater();
    delete response;
}

void DropDownListWidget::onApplicationStateChanged(Qt::ApplicationState state)
{
    switch (state)
    {
    case Qt::ApplicationActive:
        OnAppActive();
        break;
    }
}

void DropDownListWidget::OnAppActive()
{
    ui->inputLineEdit->selectAll();
}
