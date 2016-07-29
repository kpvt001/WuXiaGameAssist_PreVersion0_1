#include "gstring.h"
#include "pretable.h"
#include "gstringhelper.h"

GString::GString()
{
    pp_holder = new PClass;
}

GString::~GString()
{
    delete pp_holder;
}

GString::GString(const GString &obj)
{
    pp_holder = new PClass;
    pp_holder->qstring_ = obj.pp_holder->qstring_;
}

QString GString::ToQString() const
{
    return GStringHelper::ToQString(*this);
}

