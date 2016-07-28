#ifndef WXTIME_H
#define WXTIME_H
#include "projcommon.h"

class GTime;
class GString;
class GameTimeServer;

namespace wuxia {

enum {
    kTimeZi,
    kTimeChou,
    kTimeYin,
    kTimeMao,
    kTimeChen,
    kTimeSi,
    kTimeWu,
    kTimeWei,
    kTimeShen,
    kTimeYou,
    kTimeXu,
    kTimeHai
};

class P_Class(GameTime);

class GameTime
{
    typedef P_Class(GameTime) PClass;
    friend class GameTimeServer;
public:
    GameTime();

    int time_index() const { return time_index_; }
    GString& TimeName() const;
    GTime BeginInRealTime() const;
    GTime EndInRealTime() const;
    GTime LastInRealTime() const;
    float Progress() const;

    virtual ~GameTime();

private:
    int time_index_;
    PClass *pp_holer;

    DISALLOW_COPY_AND_ASSIGN(GameTime);
};

} //namespace wuxia
#endif // WXTIME_H
