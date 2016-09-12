#ifndef STRINGVALIDITY_H
#define STRINGVALIDITY_H

class QString;

class StringValidity
{
public:
    StringValidity();

    static bool IsValidInt(const QString &text, int min, int max);
};

#endif // STRINGVALIDITY_H
