#include "gstringhelper.h"
#include "pretable.h"
#include "gstring.h"

GString GStringHelper::Make(const QString &src)
{
    GString ret;
    ret.pp_holder->qstring_ = src;
    return ret;
}

QString GStringHelper::ToQString(const GString &src)
{
    return src.pp_holder->qstring_;
}
