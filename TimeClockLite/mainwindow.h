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
