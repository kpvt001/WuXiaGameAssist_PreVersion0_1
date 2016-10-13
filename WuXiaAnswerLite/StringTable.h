#ifndef STRINGTABLE_H
#define STRINGTABLE_H
#include <QString>

#define STR(i) (StringTable::Instance().String(i))

enum StringTableIndex
{
    StrNetworkIuuse = 1,
    StrCannotFindAnswer,
    StrUnkownErrorFromDuowan,
    StrAnswerIsFromDuowan,
};

class StringTable
{
public:
    StringTable();
    static StringTable& Instance();

    QString String(StringTableIndex index);
};

#endif
