#include "Settings.h"
#include "TestPanel.h"

Settings::Settings(QObject *parent)
    : mIsTestMode(false), QObject(parent)
{

}


Settings& Settings::Global()
{
    static Settings global;
    return global;
}
