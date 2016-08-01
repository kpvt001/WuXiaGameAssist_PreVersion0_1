/******************************************************************************
 * License: LGPL (v3.0)
 * Author: 978321000@qq.com
 * Update: 2016/7/20
 * ***************************************************************************/

#ifndef GTIME_H
#define GTIME_H

#include "projcommon.h"

class P_Class(GTime);
class GTimeHelper;

class QTime;
class GTime
{
    typedef P_Class(GTime) PClass;
    friend class GTimeHelper;

public:
    GTime(int h = 0, int m = 0, int s = 0, int ms = 0);
    GTime(const GTime& obj);
    virtual ~GTime();

    static GTime CurrentTime();


    QTime ToQTime() const;


    int h() const { return h_; }
    int m() const { return m_; }
    int s() const { return s_; }
    int ms() const { return ms_; }

private:

    PClass *pp_holder;

    int h_;
    int m_;
    int s_;
    int ms_;

    //DISALLOW_COPY_AND_ASSIGN(GTime);
};

class P_Class(GTime)
{
    friend class GTime;
    friend class GTimeHelper;
};

#endif // GTIME_H
