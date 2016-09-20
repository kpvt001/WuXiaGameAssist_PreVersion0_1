#ifndef VERSION_H
#define VERSION_H

#include <QString>



static const int version_major = 0;
static const int version_minor = 1;
static const int version_release = 1;
static const int version_build = 
#include "build_number"
        ;

static QString VersionString_1(const QString &version_type)
{
    return QString("Version: %1.%2.%3.%4 %5").arg(version_major)
            .arg(version_minor)
            .arg(version_release)
            .arg(version_build)
            .arg(version_type);
}

#endif // !VERSION_H
