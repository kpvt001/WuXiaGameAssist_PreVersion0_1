#include "Task.h"

Task::TaskParam::TaskParam(void *param, bool hold)
    : mParam(param), mHoldParam(hold)
{

}

Task::TaskParam::~TaskParam()
{
    if(mHoldParam)
        delete mParam;
}




Task::~Task()
{
    delete mParam;
}
