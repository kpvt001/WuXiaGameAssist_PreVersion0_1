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

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "TestPanel.h"

class QString;
class Timer;
class TimerUiObjectHolder;
class MainWindowPrivateDatas;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

protected:
    void ConfigUI();
    void ConfigTestModeUI();

private:
    void ConnectObjects();
    void ConnectTimer(TimerUiObjectHolder *holder);
    void ConnectUIObjects();

	TestPanel* GetTestPanel() const;
    void InitWuShiTimer();
    void InitZiShiTimer();

    void InitTestMode();
    bool TestMode() const;

    void Attention(const QString &message);

    Ui::MainWindow *ui;

    TimerUiObjectHolder *mZiShiTimerHolder;
    TimerUiObjectHolder *mWuShiTimerHolder;

    MainWindowPrivateDatas *mPrivateDatas;
	TestPanel *mTestPanel;

protected slots:
    void OnLastAlertLineEditEdited(const QString &text);

public slots:
    void OnTimerTriggered(int tag);
    void OnWuShiTimerTriggered(int tag);
    void OnZiShiTimerTriggered(int tag);

    void OnOpenTestPanelClicked(bool checked);
};
#endif // MAINWINDOW_H
