#ifndef GLOBALVARIABLES_H
#define GLOBALVARIABLES_H
#include "Global.h"

#include <QTime>

#if THREAD_SAFE
#include <QMutex>
#endif

class GlobalVariables
{
public:
    static GlobalVariables& Global();

    void InitTestMode();
    QTime& TestCurrentTime();
    void SetTestCurrentTime(const QTime &time);

private:
    GlobalVariables();
    void operator=(const GlobalVariables* other);
    ~GlobalVariables();

    QTime mTestCurrentTime;

#if THREAD_SAFE
    QMutex mMutexTestCurrentTime;
#endif

};

GlobalVariables& GVar();

#endif // GLOBALVARIABLES_H
