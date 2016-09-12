#include "TimerUiObjectHolder.h"

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
