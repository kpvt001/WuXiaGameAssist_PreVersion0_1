#include "Logger.h"

#include <iostream>
#include <QDebug>

Logger::Logger(QObject *parent) : QObject(parent)
{

}

Logger& Logger::StaticLogger()
{
    static Logger instance;
    instance.SetFilePath("log.log");
    return instance;
}

QString Logger::LevelString(int level)
{
    static QString sLevelStrings[] = {
        QString("None Level"),
        QString("Error"),
        QString("Warning"),
        QString("Notice"),
    };

    QString ret;
    switch(level)
    {
    case 1:
    case 2:
    case 3:
        ret = sLevelStrings[1];
        break;

    default:
        ret = "";
        break;
    }

    return ret;
}

void Logger::SetFilePath(const QString &path)
{
    mPath = path;
}


Logger& Logger::operator <<(const QString &string)
{
    qDebug() << string;
	return *this;
}

Logger& Logger::operator <<(const QTime &time)
{
    qDebug() << time;
    return *this;
}

Logger& Logger::operator <<(bool b)
{
    qDebug() << b;
    return *this;
}

Logger& Logger::operator <<(int i)
{
    qDebug() << i;
    return *this;
}

Logger& Logger::operator <<(const char *cstr)
{
    qDebug() << cstr;
    return *this;
}