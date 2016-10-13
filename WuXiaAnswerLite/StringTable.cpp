#include "StringTable.h"


StringTable& StringTable::Instance()
{
    static StringTable instance;
    return instance;
}

StringTable::StringTable()
{

}

QString StringTable::String(StringTableIndex index)
{
    switch(index)
    {
    case StrNetworkIuuse:
        return QString::fromLocal8Bit("网络错误");
    case StrCannotFindAnswer:
        return QString::fromLocal8Bit("无法找到此答案");
    case StrUnkownErrorFromDuowan:
        return QString::fromLocal8Bit("多玩返回错误");
    case StrAnswerIsFromDuowan:
        return QString::fromLocal8Bit("题库来自多玩http://wuxia.duowan.com");

    default:
        return QString("null string");
    }
}
