#include "GlobalVariables.h"

GlobalVariables::GlobalVariables()
    : mTestCurrentTime(QTime::currentTime())
{

}

GlobalVariables::~GlobalVariables()
{

}

void GlobalVariables::InitTestMode()
{
}

GlobalVariables& GlobalVariables::Global()
{
    // C++11 to ensure thread safe.
    static GlobalVariables global;
    return global;
}

QTime& GlobalVariables::TestCurrentTime()
{
#if THREAD_SAFE
    mMutexTestCurrentTime.lock();
#endif

    return mTestCurrentTime;

#if THREAD_SAFE
    mMutexTestCurrentTime.unlock();
#endif
}

void GlobalVariables::SetTestCurrentTime(const QTime &time)
{
#if THREAD_SAFE
    mMutexTestCurrentTime.lock();
#endif

    mTestCurrentTime = time;

#if THREAD_SAFE
    mMutexTestCurrentTime.unlock();
#endif
}

GlobalVariables& GVar()
{
    return GlobalVariables::Global();
}
