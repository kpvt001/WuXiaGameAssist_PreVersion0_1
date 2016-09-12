#ifndef TIMER_H
#define TIMER_H

#include <QObject>
#include <QTime>
#include <QMutex>

class Timer : public QObject
{
    Q_OBJECT
public:
    explicit Timer(QObject *parent = 0);
    virtual ~Timer();

    void SetTime(const QTime &time);
    void Enable();
    void Disable();
    int Tag() const;

    bool IsEnabled() const;

    void Reset();

protected:
    virtual void timerEvent(QTimerEvent *event);
    virtual void Process(void *param = nullptr);
    virtual void Trigger(void *param);

    Timer(const Timer &other);

private:
    bool IsTriggered() const;
    float SetIntervalSec(float sec);
    float SetAccuracySec(float sec);
    float CalcMaxIntervalWithAccuracy(float sec);
    float MinAccuracySec() const;

	QTime mTime;
    volatile bool mTriggered; // today timer is triggered
	bool mIsEnabled;
    int mTag;
	float mIntervalSec;
	float mAccuracySec;
    int mQObjectTimerEventId;

    static int kTagCount;


signals:
    void Triggered(int tag);


public slots:
};

#endif // TIMER_H
