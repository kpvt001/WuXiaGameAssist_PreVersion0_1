/* Copyright (c) 2016, .
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

#include "Timer.h"
#include <QTimerEvent>

#include "Logger.h"
#include "Settings.h"
#include "GlobalVariables.h"

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
    QTime curTime = CurrentTime();
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

QTime Timer::CurrentTime()
{
    if (Settings::Global().IsUseTestCurrentTime())
        return TestCurrentTime();
    else
        return QTime::currentTime();
}

QTime Timer::TestCurrentTime()
{
    return GlobalVariables::Global().TestCurrentTime();
}
