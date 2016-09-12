#include "Timer.h"
#include <QTimerEvent>

#include "Logger.h"

static const float kDefualtAccuracySec = 10.0f;
static const float kDefualtIntervalSec = kDefualtAccuracySec / 6;

int Timer::kTagCount = 0;

Timer::Timer(QObject *parent)
    : mTriggered(false), mIsEnabled(false), mAccuracySec(kDefualtAccuracySec)
    , mTag(++kTagCount)
    , mIntervalSec(kDefualtIntervalSec), QObject(parent)
{
    // Ensure interval is right
    SetIntervalSec(mIntervalSec);
    SetTime(QTime::currentTime());
}

Timer::~Timer()
{
    Disable();
}

void Timer::SetTime(const QTime &time)
{
    mTime = time;
}

float Timer::SetAccuracySec(float sec)
{
    mAccuracySec = qMax(MinAccuracySec(), sec);
    float tInterval = CalcMaxIntervalWithAccuracy(mAccuracySec);
    if(tInterval < mIntervalSec)
        SetIntervalSec(tInterval);

    return mAccuracySec;
}

void Timer::Enable()
{
    if(mIsEnabled)
        return;

    SetIntervalSec(mIntervalSec);

    mQObjectTimerEventId = startTimer(mIntervalSec);
	mIsEnabled = true;
}

void Timer::Disable()
{
    if (!mIsEnabled)
        return;

    mIsEnabled = false;
    killTimer(mQObjectTimerEventId);
}

float Timer::SetIntervalSec(float sec)
{
    bool isEnabledBefore = mIsEnabled;
    if (isEnabledBefore)
        Disable();

    float t = CalcMaxIntervalWithAccuracy(sec);
    mIntervalSec = qMin(t, sec);

    if (isEnabledBefore)
        Enable();

    return mIntervalSec;
}

float Timer::MinAccuracySec() const
{
    return 0.6f;
}

void Timer::timerEvent(QTimerEvent *event)
{
    if (event->timerId() == mQObjectTimerEventId)
    {
        Process();
    }
}

void Timer::Process(void *param)
{
    QTime curTime = QTime::currentTime();
    if(curTime < mTime)
    {
        Reset();
        return;
    }
    else
    {
        if(mTime.msecsTo(curTime)< mAccuracySec)
            Trigger(param);
    }
}

void Timer::Trigger(void *param)
{
	Log << "in Timer::Trigger(void *param)";
    Q_UNUSED(param);
    if(mTriggered)
        return;

    mTriggered = true;
    emit Triggered(mTag);
}

float Timer::CalcMaxIntervalWithAccuracy(float sec)
{
    static const float kDefualtLargeMax = 1.0f;
    if(sec > 10.0f)
        return 1.0f;
    else if (sec > 1.0f)
        return qMin(kDefualtLargeMax, sec / 6);
    else
        return sec / 10;
}

void Timer::Reset()
{
    mTriggered = false;
}
