#include "gametimeserverres.h"
namespace wuxia {
GameTimeServerRes::GameTimeServerRes()
{

}

GameTimeServerRes::~GameTimeServerRes()
{

}

GameTimeServerRes& GameTimeServerRes::Instance()
{
    static GameTimeServerRes instance;
    return instance;
}

void GameTimeServerRes::LoadTimeNames()
{
    static bool isInit = false;
    if (!isInit)
    {

        // put lock function here if need thread safty;

        if (!isInit)
        {
            isInit = true;

            time_names_.push_back(QString("子时"));
            time_names_.push_back(QString("丑时"));
            time_names_.push_back(QString("寅时"));
            time_names_.push_back(QString("卯时"));
            time_names_.push_back(QString("辰时"));
            time_names_.push_back(QString("巳时"));
            time_names_.push_back(QString("午时"));
            time_names_.push_back(QString("未时"));
            time_names_.push_back(QString("申时"));
            time_names_.push_back(QString("酉时"));
            time_names_.push_back(QString("戌时"));
            time_names_.push_back(QString("亥时"));
        }
    }
}

} // namespace wuxia
