#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QVector>


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

    void EnableTimer(TimerUiObjectHolder *holder, bool enable = true);
    void DisableTimer(TimerUiObjectHolder *holder);
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
    void OnTimeCheckBoxChecked(bool checked);
    void OnWuShiTimerTriggered(int tag);
    void OnZiShiTimerTriggered(int tag);
    void OnStartPushButtonClick(bool checked);
};
#endif // MAINWINDOW_H
