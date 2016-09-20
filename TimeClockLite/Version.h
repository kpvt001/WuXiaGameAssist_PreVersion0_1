#ifndef VERSION_H
#define VERSION_H

#include <QString>

static const int version_major = 0;
static const int version_minor = 1;
static const int version_release = 2;
static const int version_build = 
#include "build_number"
        ;

static const char *version_type = "Alpha";

static QString VersionString_1()
{
    return QString("v%1.%2%3 build %4 %5").arg(version_major)
            .arg(version_minor)
            .arg(version_release)
            .arg(version_build)
            .arg(version_type);
}

#endif // !VERSION_H
