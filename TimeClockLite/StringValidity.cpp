#include "StringValidity.h"

#include <QString>

StringValidity::StringValidity()
{

}

bool StringValidity::IsValidInt(const QString &text, int min, int max)
{
    int textInt = text.toInt();

    if (text != QString("%1").arg(textInt))
        return false;

    if (textInt < min || max < textInt)
        return false;

    return true;
}
