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

#include "TimerUiObjectHolder.h"

#include "Logger.h"
#include "Timer.h"

TimerUiObjectHolder::TimerUiObjectHolder(QObject *parent) : QObject(parent)
{

}


void TimerUiObjectHolder::AddTimer(const QTime &time)
{
	Timer *timer = new Timer(this);
	timer->SetTime(time);
	mTimers.append(timer);
}

void TimerUiObjectHolder::EnableTimers(bool enable)
{
    Log << "Enable Timers";
	Timer *timer;
	Q_FOREACH(timer, mTimers)
	{
		if (enable)
			timer->Enable();
		else
			timer->Disable();
	}
}

void TimerUiObjectHolder::DisableTimers()
{
	EnableTimers(false);
}

void TimerUiObjectHolder::OnCheckBoxChecked(bool checked)
{
	EnableTimers(checked);
}

void TimerUiObjectHolder::AddTimer(const QVector<QTime *> &times)
{
    QTime *time;
    Q_FOREACH(time, times)
    {
        AddTimer(*time);
    }
}
