#include "gametime.h"

#include "gtime.h"
#include "gstring.h"

namespace wuxia {

class P_Class(GameTime)
{
    friend class GameTime;
public:
    P_Class(GameTime)(){}

private:
    GString time_name_;
};


GameTime::GameTime()
{
    pp_holer = new P_Class(GameTime);
}

GameTime::~GameTime()
{
    delete pp_holer;
}

GString& GameTime::TimeName() const
{
    return pp_holer->time_name_;
}
} // namespace wuxia
