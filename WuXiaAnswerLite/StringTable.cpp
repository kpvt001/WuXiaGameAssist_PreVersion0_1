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
    QString str;
    switch(index)
    {
    case StrNetworkIuuse:
        str = QString::fromLocal8Bit("网络错误");
        break;
    case StrCannotFindAnswer:
        str = QString::fromLocal8Bit("无法找到此答案");
        break;
    case StrUnkownErrorFromDuowan:
        str = QString::fromLocal8Bit("多玩返回错误");
        break;
    case StrAnswerIsFromDuowan:
        str = QString::fromLocal8Bit("题库来自多玩[http://wuxia.duowan.com]");
        break;

    default:
        str = QString("null string");
        break;
    }

    return str;
}
