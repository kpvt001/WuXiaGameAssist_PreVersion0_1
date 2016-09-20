/* Copyright (c) 2016, %{Owner}%.
 * All rights reserved.

 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice, this
 *    list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR
 * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

 * The views and conclusions contained in the software and documentation are those
 * of the authors and should not be interpreted as representing official policies,
 * either expressed or implied, of the FreeBSD Project.
 */

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
#include "Version.h"

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
    ui->versionStringLabel->setText(VersionString_1());
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
