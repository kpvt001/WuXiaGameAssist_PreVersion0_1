#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QMessageBox>
//#include <QRegExpValidator>

#include "Logger.h"
#include "TimerUiObjectHolder.h"
#include "BeepRingTask.h"
#include "StringValidity.h"


class MainWindowPrivateDatas// : public QObject
{
    friend class MainWindow;

private:
    MainWindowPrivateDatas()
        : ringLastSec(100)
        , ringMaxLastSec(1 * 60 * 60)
        , ringFilePath()
    {}
    int ringLastSec;
    int ringMaxLastSec;
    QString ringFilePath;
};

MainWindow::MainWindow(QWidget *parent)
    : mWuShiTimerHolder(0)
    , mZiShiTimerHolder(0)
    , mPrivateDatas(new MainWindowPrivateDatas)
    , QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ConfigUI();
    InitWuShiTimer();
    InitZiShiTimer();
    ConnectObjects();
}

MainWindow::~MainWindow()
{
    delete ui;
    delete mPrivateDatas;
}

void MainWindow::ConfigUI()
{
//    QRegExp regexp("[0-9]+$");
//    QValidator *validator = new QRegExpValidator(regexp, ui->lastAlertSecLineEdit);
//    ui->lastAlertSecLineEdit->setValidator(validator);

    ui->lastAlertSecLineEdit->setText(QString("%1").arg(mPrivateDatas->ringLastSec));

    // disable widgets
    ui->startPushButton->setVisible(false);
}

void MainWindow::InitWuShiTimer()
{
    mWuShiTimerHolder = new TimerUiObjectHolder(this);
    mWuShiTimerHolder->mCheckBox = ui->wuShiCheckBox;
    for (int i = 0; i < 24 / 4; i++)
    {
        mWuShiTimerHolder->AddTimer(QTime((0 + i * 4) % 24, 5));
    }
}

void MainWindow::InitZiShiTimer()
{
    mZiShiTimerHolder = new TimerUiObjectHolder(this);
    mZiShiTimerHolder->mCheckBox = ui->ziShiCheckBox;
    for (int i = 0; i < 24 / 4; i++)
    {
        mZiShiTimerHolder->AddTimer(QTime((2 + i * 4) % 24, 5));
    }
}

void MainWindow::ConnectObjects()
{
    ConnectTimer(mWuShiTimerHolder);
    ConnectTimer(mZiShiTimerHolder);
    ConnectUIObjects();
}

void MainWindow::ConnectUIObjects()
{
    connect(ui->lastAlertSecLineEdit, SIGNAL(textEdited(QString)), this, SLOT(OnLastAlertLineEditEdited(QString)));
    connect(ui->startPushButton, SIGNAL(clicked(bool)), this, SLOT(OnStartPushButtonClick(bool)));
}

void MainWindow::ConnectTimer(TimerUiObjectHolder *holder)
{
    if (holder == mWuShiTimerHolder)
    {
        Timer *timer;
        Q_FOREACH(timer, mWuShiTimerHolder->mTimers)
        {
            connect(timer, SIGNAL(toTrigger(int)), this, SLOT(OnWuShiTimerTriggered(int)));
        }
    }
    else if (holder == mZiShiTimerHolder)
    {
        Timer *timer;
        Q_FOREACH(timer, mZiShiTimerHolder->mTimers)
        {
            connect(timer, SIGNAL(toTrigger(int)), this, SLOT(OnZiShiTimerTriggered(int)));
        }
    }

    connect(holder->mCheckBox, SIGNAL(clicked(bool)), holder, SLOT(OnCheckBoxChecked(bool)));
}

void MainWindow::OnTimerTriggered(int tag)
{
    qDebug() << "trigger timer " << tag;
}

void MainWindow::EnableTimer(TimerUiObjectHolder *holder, bool enable)
{
    Timer *timer;
    Q_FOREACH(timer, holder->mTimers)
    {
        if(enable)
            timer->Enable();
        else
            timer->Disable();
    }
}

void MainWindow::DisableTimer(TimerUiObjectHolder *holder)
{
    EnableTimer(holder, false);
}

void MainWindow::OnTimeCheckBoxChecked(bool checked)
{
    if (sender() == ui->wuShiCheckBox)
    {
        EnableTimer(mWuShiTimerHolder, checked);
    }
    else if (sender() == ui->ziShiCheckBox)
    {
        EnableTimer(mZiShiTimerHolder, checked);
    }
}

void MainWindow::OnWuShiTimerTriggered(int tag)
{
    Q_UNUSED(tag);
	Attention("午时到了!");
}

void MainWindow::OnZiShiTimerTriggered(int tag)
{
    Q_UNUSED(tag)
	Attention("子时到了!");
}

void MainWindow::Attention(const QString &message)
{
	int lastSec = ui->lastAlertSecLineEdit->text().toInt();
	Log << lastSec;

	BeepRingTask ringTask(lastSec);
	ringTask.start();

    QMessageBox dlg;
    dlg.setText(message);
    dlg.exec();
	ringTask.terminate();
}

void MainWindow::OnStartPushButtonClick(bool checked)
{
	Q_UNUSED(checked);
    int lastSec = ui->lastAlertSecLineEdit->text().toInt();
    Log << lastSec;

    BeepRingTask *ringTask = new BeepRingTask(lastSec);
    ringTask->start();
}

void MainWindow::OnLastAlertLineEditEdited(const QString &text)
{
    if (!StringValidity::IsValidInt(text, 0, mPrivateDatas->ringMaxLastSec))
    {
        QApplication::beep();
        ui->lastAlertSecLineEdit->setText(QString("%1").arg(mPrivateDatas->ringLastSec));;
    }
    else
    {
        mPrivateDatas->ringLastSec = ui->lastAlertSecLineEdit->text().toInt();
    }
}
