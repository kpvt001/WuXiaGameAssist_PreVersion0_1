#ifndef LOGRECORD_H
#define LOGRECORD_H

#include <QString>
#include <QDate>
#include <QTime>

class LogRecord
{
public:
    LogRecord(int level, const QString &content)
        : mLevel(level), mContent(content), mTime(QTime::currentTime())
        , mDate(QDate::currentDate())
    {
    }

    LogRecord(const QString &content)
        : mLevel(4), mContent(content), mTime(QTime::currentTime())
        , mDate(QDate::currentDate())
    {
    }

    QString ToLogString();

    static void Tick();

public:
    static int kCount;

private:

    QDate mDate;
    QTime mTime;
    int mLevel;
    QString mContent;
};

#endif // LOGRECORD_H
