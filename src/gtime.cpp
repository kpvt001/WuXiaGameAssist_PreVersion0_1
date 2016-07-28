/******************************************************************************
 * License: LGPL (v3.0)
 * Author: 978321000@qq.com
 * Update: 2016/7/20
 * ***************************************************************************/
#include "gtime.h"

#include "pretable.h"
#include "gtimehelper.h"
GTime::GTime(int h, int m, int s, int ms)
    : h_(h), m_(m), s_(s), ms_(ms)
{
   pp_holder = new PClass;
}

GTime::~GTime()
{
    delete pp_holder;
}

QTime GTime::ToQTime() const
{
    return GTimeHelper::ToQTime(*this);
}


