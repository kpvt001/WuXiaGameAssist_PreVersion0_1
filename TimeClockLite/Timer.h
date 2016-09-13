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

#ifndef TIMER_H
#define TIMER_H

#include <QObject>
#include <QTime>

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
    static QTime CurrentTime();
    static QTime TestCurrentTime();

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
