#include "DropDownListWidget.h"
#include "ui_DropDownListWidget.h"

#include "Global.h"

#include <QApplication>
#include <QFocusEvent>

#include "DuowanAnswerRequest.h"
#include "AnswerResponse.h"
#include "AnswerItem.h"
#include "StringTable.h"

const int DropDownListWidget::kRequestTimerInterval = 400; // ms

const QString sNullStringPlaceHolder = QString("a-null-string").toLower();

DropDownListWidget::DropDownListWidget(QWidget *parent)
    : mLastSuccessedRequestPinyin(sNullStringPlaceHolder.toLower())
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
        DisposeInputPinyin(&inputPinyin);
        ui->inputLineEdit->setText(inputPinyin);

        if (inputPinyin.isEmpty())
        {
            onEmptyInputEdit();
            return;
        }

        if (mRequestingPinyin == inputPinyin)
            return;

        if (mLastSuccessedRequestPinyin == inputPinyin)
            return;

        onGetAnswer(inputPinyin);
    }
}

void DropDownListWidget::ConnectObjects()
{
    connect(qApp, SIGNAL(applicationStateChanged(Qt::ApplicationState)), this, SLOT(onApplicationStateChanged(Qt::ApplicationState)));
}

void DropDownListWidget::ConfigUi()
{
    onResetEmptyListWidget();
}

void DropDownListWidget::onContentListComboBoxEditTextChanged(const QString &text)
{
    onGetAnswer(text);
}

void DropDownListWidget::onGetAnswer(const QString &pinyin)
{
    mRequestingPinyin = pinyin;
    DuowanAnswerRequest *request = new DuowanAnswerRequest(pinyin);
    mLastRequestId = request->Id();
    connect(request, SIGNAL(responseReady(AnswerResponse*)), this, SLOT(onAnswerResponseReady(AnswerResponse*)));
    request->Request();
}

QString DropDownListWidget::AnswerResultMaskString() const
{
    return QString("[%1]----%2");
}

void DropDownListWidget::onAnswerResponseReady(AnswerResponse *response)
{
    ui->contentListWidget->clear();
    mRequestingPinyin.clear();
    if (response->RequestId() == mLastRequestId)
    {
        if (response->Error() == AnswerResponse::NoError)
        {
            mLastSuccessedRequestPinyin = response->Request()->Pinyin();
            if (response->AnswerCount() == 0)
            {
                ui->contentListWidget->addItem(STR(StrCannotFindAnswer));
            }
            else
            {
                AnswerItem aItem;
                Q_FOREACH(aItem, response->Items())
                {
                    QString mask = AnswerResultMaskString();
                    QString itemString = mask.arg(aItem.Answer()).arg(aItem.Qustion());
                    ui->contentListWidget->addItem(itemString);
                }
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
    {
        QString errorString;
        bool needAlert = false;
        bool needNoticeString = true;
        switch (errorCode)
        {
        case AnswerResponse::ErrorNetworkFailed:
            errorString = STR(StrNetworkIuuse);
            needAlert = true;
            break;

        case AnswerResponse::ErrorJsonParse:
        default:
            errorString = STR(StrUnkownErrorFromDuowan);
            break;
        }

        if (needNoticeString)
            ui->contentListWidget->addItem(errorString);

        if (needAlert)
            QApplication::beep();
    }
}

void DropDownListWidget::onEmptyInputEdit()
{
    onResetEmptyListWidget();
    mLastSuccessedRequestPinyin.clear();
}

void DropDownListWidget::onResetEmptyListWidget()
{
    ui->contentListWidget->clear();
    ui->contentListWidget->addItem(STR(StrAnswerIsFromDuowan));
}

void DropDownListWidget::DisposeInputPinyin(QString *pinyin)
{
    *pinyin = pinyin->toLower();
    pinyin->replace(' ', '_');
}
