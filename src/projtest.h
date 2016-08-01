#ifndef PROJTEST
#define PROJTEST

#include "pretable.h"
#include "gametime.h"
#include <QtDebug>


class ProjectTest
{
public:
    ProjectTest();

    static ProjectTest Instance();

    bool RunTest();

private:
    bool TestGTime();
    bool TestGString();

    void Message(bool ok, const QString& fun, const QString& msg = QString()) const;
    void Message(const QString &msg) const;
};

#endif // PROJTEST

