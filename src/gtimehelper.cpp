#include "gtimehelper.h"

#include "pretable.h"

#include "gtime.h"
#include "gtimehelper.h"

GTimeHelper::GTimeHelper()
{

}

GTime GTimeHelper::Make(const QTime &src)
{
    GTime ret(src.hour(), src.minute(), src.second(), src.msec());

    return ret;
}

QTime GTimeHelper::ToQTime(const GTime &src)
{
    QTime ret(src.h_, src.m_, src.s_, src.ms_);

    return ret;
}

