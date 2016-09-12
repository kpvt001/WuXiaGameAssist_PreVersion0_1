#include "TimeClockTagContainer.h"


bool TimeTagSortLessThan(const TimeClockTagContainer::TimeTag &tag1,
                         const TimeClockTagContainer::TimeTag &tag2)
{
    return tag1.time < tag2.time;
}


TimeClockTagContainer::TimeClockTagContainer()
    : mAutoSort(true)
{

}

TimeClockTagContainer::TimeTag& TimeClockTagContainer::operator [](int i)
{
    mMutex.lock();
    return mElements[i];
    mMutex.unlock();
}

void TimeClockTagContainer::AddTag(int tag, const QTime &time)
{
    TimeTag timeTag;
    timeTag.tag = tag;
    timeTag.time = time;

    mMutex.lock();
    mElements.append(timeTag);
    if (mAutoSort)
    {
        qSort(mElements.begin(), mElements.end(), TimeTagSortLessThan);
    }
    mMutex.unlock();
}

int TimeClockTagContainer::RemoveTag(int tag)
{
    mMutex.lock();
    int i = 0;
    for(; i < Count(); i++)
    {
        if(mElements[i].tag == tag)
        {
            mElements.remove(i);
            break;
        }
    }
    mMutex.unlock();
    return i;
}

int TimeClockTagContainer::Count() const
{
	return mElements.count();
}
