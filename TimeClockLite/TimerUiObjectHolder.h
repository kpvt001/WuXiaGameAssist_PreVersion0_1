#ifndef TIMERUIOBJECTHOLDER_H
#define TIMERUIOBJECTHOLDER_H

#include <QObject>
#include <QCheckBox>
#include <QVector>
#include <QTime>

#include "Timer.h"

class TimerUiObjectHolder : public QObject
{
    Q_OBJECT

public:
    friend class MainWindow;
    TimerUiObjectHolder(QObject *parent = 0);

    void AddTimer(const QTime &time);

    void EnableTimers(bool enable = true);

    void DisableTimers();

private:
	QCheckBox *mCheckBox;
	QVector<Timer*> mTimers;

public slots:
    void OnCheckBoxChecked(bool checked);
};

#endif // TIMERUIOBJECTHOLDER_H
