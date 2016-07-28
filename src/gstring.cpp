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

QString GString::ToQString() const
{
    return GStringHelper::ToQString(*this);
}

