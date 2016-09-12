#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

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

private:
    void ConnectObjects();
    void ConnectTimer(TimerUiObjectHolder *holder);
    void ConnectUIObjects();

    void InitWuShiTimer();
    void InitZiShiTimer();

    void Attention(const QString &message);

    Ui::MainWindow *ui;

    TimerUiObjectHolder *mZiShiTimerHolder;
    TimerUiObjectHolder *mWuShiTimerHolder;

    MainWindowPrivateDatas *mPrivateDatas;

protected slots:
    void OnLastAlertLineEditEdited(const QString &text);

public slots:
    void OnTimerTriggered(int tag);
    void OnWuShiTimerTriggered(int tag);
    void OnZiShiTimerTriggered(int tag);
};
#endif // MAINWINDOW_H
