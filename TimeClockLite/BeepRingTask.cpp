#include "BeepRingTask.h"
#include <QApplication>
#include "Logger.h"
#include <QDebug>

BeepRingTask::BeepRingTask(int loopSec)
    : mLoopSec(loopSec > 0 ? loopSec : 1), QThread(nullptr)
    , mBeepIntervalMSec(1000)
{
    connect(this, SIGNAL(finished()), this, SLOT(deleteLater()));
}

BeepRingTask::~BeepRingTask()
{
    Log << "beep ring task delete";
}


void BeepRingTask::run()
{
    for (int i = 0; i < mLoopSec * 1000; i += mBeepIntervalMSec)
    {
        QApplication::beep();
        this->msleep(mBeepIntervalMSec);
    }
}
