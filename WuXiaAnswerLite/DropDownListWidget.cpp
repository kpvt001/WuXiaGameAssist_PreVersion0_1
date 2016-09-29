#include "DropDownListWidget.h"
#include "ui_DropDownListWidget.h"

#include "Global.h"

#include "DuowanAnswerRequest.h"
#include "AnswerResponse.h"
#include "AnswerItem.h"

DropDownListWidget::DropDownListWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DropDownListWidget)
{
    ui->setupUi(this);

    setWindowFlags(Qt::WindowStaysOnTopHint);

    configUi();
}

DropDownListWidget::~DropDownListWidget()
{
    delete ui;
}

void DropDownListWidget::configUi()
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
    if (response->RequestId() == mLastRequestId
            && response->Error() == AnswerResponse::NoError)
    {
        ui->contentListWidget->clear();
        AnswerItem aItem;
        Q_FOREACH(aItem, response->Items())
        {
            QString itemString = QString("[%1]----%2").arg(aItem.Answer()).arg(aItem.Qustion());
            ui->contentListWidget->addItem(itemString);
        }
    }

    response->Request()->deleteLater();
    delete response;
}
