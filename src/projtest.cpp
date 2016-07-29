#include "projtest.h"
#include "gtimehelper.h"

ProjectTest::ProjectTest()
{

}

bool ProjectTest::RunTest()
{
    return TestGString() &&
            TestGTime();
}

bool ProjectTest::TestGTime()
{
    QString fun_name = "TestGTime";
    QTime qtime = QTime::currentTime();
    GTime gtime = GTimeHelper::Make(qtime);

    if (qtime.hour() != gtime.h() ||
            qtime.minute() != gtime.m() ||
            qtime.second() != gtime.s() ||
            qtime.msec() != gtime.ms())
    {
        Message(false, fun_name);
        return false;
    }
    return true;
}

bool ProjectTest::TestGString()
{
    return true;
}

void ProjectTest::Message(bool ok, const QString &fun, const QString &msg)
{
    QString ok_string;
    ok_string = ok ? "success" : "failed";
    QString message = QString("Test %1 at function %2, message: %3").arg(ok_string).arg(fun).arg(msg);
    qDebug() << message;
}
