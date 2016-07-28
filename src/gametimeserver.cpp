#include "gametimeserver.h"

#include "gametimeserverres.h"


namespace wuxia {

class P_Class(GameTimeServer)
{
    friend class GameTimeServer;

};

GameTimeServer::GameTimeServer()
{
    pp_holer = new PClass;
}

GameTimeServer::~GameTimeServer()
{
    delete pp_holer;
}

GameTimeServer& GameTimeServer::Instance()
{
    static GameTimeServer instance;
    return instance;
}

GameTimeServer* GameTimeServer::pInstance()
{
    return &(GameTimeServer::Instance());
}

const QList<QString>* GameTimeServer::TimeNames() const
{
    return GameTimeServerRes::Instance().time_names();
}

} // namespace wuxia
