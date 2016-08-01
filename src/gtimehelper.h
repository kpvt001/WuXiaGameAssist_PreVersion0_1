#ifndef GTIMEHELPER_H
#define GTIMEHELPER_H
#include "projcommon.h"

class QTime;

class GTime;

class GTimeHelper
{
public:
    static GTime Make(const QTime& src);
    static GTime CurrentTime();

    static QTime ToQTime(const GTime& src);

private:
    GTimeHelper();

    static GTime CurrentTimeViaQTime();

    DISALLOW_COPY_AND_ASSIGN(GTimeHelper);
};

#endif // GTIMEHELPER_H
