#ifndef GSTRING_H
#define GSTRING_H
#include "projcommon.h"

class P_Class(GString);
class GStringHelper;

class QString;

class GString
{
    typedef P_Class(GString) PClass;
    friend class GStringHelper;
public:
    GString();
    virtual ~GString();

    QString ToQString() const;

private:
    PClass *pp_holder;

    DISALLOW_COPY_AND_ASSIGN(GString);
};

class P_Class(GString)
{
    friend class GString;
    friend class GStringHelper;
    QString qstring_;
};

#endif // GSTRING_H
