#ifndef BEEPRINGTASK_H
#define BEEPRINGTASK_H

#include <QThread>

class BeepRingTask : public QThread
{
public:
    BeepRingTask(int loopSec = 120);
    virtual ~BeepRingTask();

protected:
    virtual void run();
private:
    int mLoopSec;
    int mBeepIntervalMSec;
};

#endif // BEEPRINGTASK_H
