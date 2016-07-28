#ifndef GSTRINGHELPER_H
#define GSTRINGHELPER_H

#include "projcommon.h"

class GString;

class QString;

class GStringHelper
{
public:
    static GString Make(const QString& src);
    static QString ToQString(const GString& src);

    //static GString Make(const char* src);


private:
    GStringHelper();
    DISALLOW_COPY_AND_ASSIGN(GStringHelper);
};

#endif // GSTRINGHELPER_H
