#ifndef GAMETIMESERVER_H
#define GAMETIMESERVER_H

#include "projcommon.h"

class GString;


namespace wuxia {

class GameTime;
class PTime;

class P_Class(GameTimeServer);

class GameTimeServer
{
    typedef P_Class(GameTimeServer) PClass;
public:
    GameTimeServer();

    static GameTimeServer& Instance();
    static GameTimeServer* pInstance();

    GameTime CurrentTime();
    const QList<QString>* TimeNames() const;
    GString TimeNameOf(int time_index);
    int TimeIndexsCount() const;
    GameTime GameTimeInPTime(const PTime& ptime);

    virtual ~GameTimeServer();

    // int NextTimeIndexOf(int time_index);
    // int PreviousTimeIndexOf(int time_index);

private:

    PClass *pp_holer;
    DISALLOW_COPY_AND_ASSIGN(GameTimeServer);
};
} // namespace wuxia

#endif // GAMETIMESERVER_H
