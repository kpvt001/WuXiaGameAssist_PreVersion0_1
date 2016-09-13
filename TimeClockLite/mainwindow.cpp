#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QMessageBox>
#include <QTime>
#include <QStringList>
#include <QDebug>

#include "Logger.h"
#include "TimerUiObjectHolder.h"
#include "BeepRingTask.h"
#include "StringValidity.h"
#include "Timer.h"
#include "TestPanel.h"
#include "Settings.h"

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

    if (TestMode())
        InitTestMode();
}

MainWindow::~MainWindow()
{
    delete ui;
    delete mPrivateDatas;
}

void MainWindow::InitTestMode()
{
    Log << "MainWindow::InitTestMode()";
    mTestPanel = new TestPanel(this);

    connect(ui->openTestPanelPushButton, SIGNAL(clicked(bool)), this, SLOT(OnOpenTestPanelClicked(bool)));
}

TestPanel* MainWindow::GetTestPanel() const
{
    return mTestPanel;
}

bool MainWindow::TestMode() const
{
    return Settings::Global().IsTestMode();
}

void MainWindow::ConfigUI()
{
    ui->lastAlertSecLineEdit->setText(QString("%1").arg(mPrivateDatas->ringLastSec));

    // disable widgets
    ui->startPushButton->setVisible(false);
    ui->openTestPanelPushButton->setVisible(false);

    if (Settings::Global().IsTestMode())
        ConfigTestModeUI();
}

void MainWindow::ConfigTestModeUI()
{
    ui->openTestPanelPushButton->setVisible(true);
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

    connect(ui->openTestPanelPushButton, SIGNAL(clicked(bool)), this, SLOT(OnOpenTestPanelClicked(bool)));
}

void MainWindow::ConnectTimer(TimerUiObjectHolder *holder)
{
    if (holder == mWuShiTimerHolder)
    {
        Timer *timer;
        Q_FOREACH(timer, mWuShiTimerHolder->mTimers)
        {
            connect(timer, SIGNAL(Triggered(int)), this, SLOT(OnWuShiTimerTriggered(int)));
        }
    }
    else if (holder == mZiShiTimerHolder)
    {
        Timer *timer;
        Q_FOREACH(timer, mZiShiTimerHolder->mTimers)
        {
            connect(timer, SIGNAL(Triggered(int)), this, SLOT(OnZiShiTimerTriggered(int)));
        }
    }

    connect(holder->mCheckBox, SIGNAL(clicked(bool)), holder, SLOT(OnCheckBoxChecked(bool)));
}

void MainWindow::OnTimerTriggered(int tag)
{
	Log << QString("trigger timer (tag %1)").arg(tag);
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
    dlg.setWindowFlags(Qt::WindowStaysOnTopHint);
    dlg.exec();
	ringTask.terminate();
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

void MainWindow::OnOpenTestPanelClicked(bool checked)
{
    Q_UNUSED(checked);
    mTestPanel->show();
}
