#include "DropDownListWidget.h"
#include "ui_DropDownListWidget.h"

#include "Global.h"

#include <QApplication>
#include <QFocusEvent>

#include "DuowanAnswerRequest.h"
#include "AnswerResponse.h"
#include "AnswerItem.h"

const float DropDownListWidget::kRequestTimerInterval = 300; // ms

DropDownListWidget::DropDownListWidget(QWidget *parent)
    : mLastRequestPinyin(QString()), mRequestReached(true)
    , QWidget(parent),
    ui(new Ui::DropDownListWidget)
{
    ui->setupUi(this);

    setWindowFlags(Qt::WindowStaysOnTopHint);

    ConfigUi();
    ConnectObjects();

    mRequestTimerEventId = startTimer(kRequestTimerInterval);
}

DropDownListWidget::~DropDownListWidget()
{
    delete ui;
}

void DropDownListWidget::timerEvent(QTimerEvent *event)
{
    if ((event->timerId() == mRequestTimerEventId))
    {
        QString inputPinyin = ui->inputLineEdit->text();
        if (mLastRequestPinyin != inputPinyin)
        {
            onGetAnswer(inputPinyin);
        }
    }
}

void DropDownListWidget::ConnectObjects()
{
    connect(qApp, SIGNAL(applicationStateChanged(Qt::ApplicationState)), this, SLOT(onApplicationStateChanged(Qt::ApplicationState)));
}

void DropDownListWidget::ConfigUi()
{
}

void DropDownListWidget::onContentListComboBoxEditTextChanged(const QString &text)
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
            mLastRequestPinyin = response->Request()->Pinyin();

            AnswerItem aItem;
            Q_FOREACH(aItem, response->Items())
            {
                QString itemString = QString("[%1]----%2").arg(aItem.Answer()).arg(aItem.Qustion());
                ui->contentListWidget->addItem(itemString);
            }
        }
        else
        {
            DoResponseError(response->Error());
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

void DropDownListWidget::DoResponseError(int errorCode)
{
    {   // Error string;
        QString errorString;
        bool needAlert = false;
        bool needNoticeString = true;
        switch (errorCode)
        {
        case AnswerResponse::ErrorJsonParse:
            errorString = "Cannot find the question with this pinyin.";
            break;
        case AnswerResponse::ErrorNetworkFailed:
            errorString = "Network issue.";
            needAlert = true;
            break;

        default:
            errorString = "Unknow error from duowan.";
            break;
        }

        if (needNoticeString)
            ui->contentListWidget->addItem(errorString);

        if (needAlert)
            QApplication::beep();
    }
}
