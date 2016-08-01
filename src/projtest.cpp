#include "projtest.h"
#include "gtimehelper.h"

ProjectTest::ProjectTest()
{

}

ProjectTest ProjectTest::Instance()
{
    static ProjectTest instance;
    return instance;
}

bool ProjectTest::RunTest()
{
    bool ok = false;
    QString msg = "RunTest ";

    if (ok = TestGString() &&
            TestGTime())
    {
        msg.append("all ok!");
    }
    else
    {
        msg.append("failed!");
    }
    Message(msg);

    return ok;
}

bool ProjectTest::TestGTime()
{
    QString fun_name = "TestGTime";
    QTime qtime = QTime::currentTime();
    GTime gtime = GTimeHelper::Make(qtime);

    bool ok;
    if (ok = qtime.hour() != gtime.h() ||
            qtime.minute() != gtime.m() ||
            qtime.second() != gtime.s() ||
            qtime.msec() != gtime.ms())
    {
        Message(false, fun_name);
    }

    return ok;
}

bool ProjectTest::TestGString()
{
    return true;
}

void ProjectTest::Message(bool ok, const QString &fun, const QString &msg) const
{
    QString ok_string;
    ok_string = ok ? "success" : "failed";
    QString message = QString("Test %1 at function %2, message: %3").arg(ok_string).arg(fun).arg(msg);
    qDebug() << message;
}

void ProjectTest::Message(const QString &msg) const
{
    qDebug() << msg;
}
