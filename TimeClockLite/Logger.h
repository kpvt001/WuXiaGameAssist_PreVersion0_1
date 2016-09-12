#ifndef LOGGER_H
#define LOGGER_H

#include <QObject>

class QString;
class QTime;

class Logger : public QObject
{
    Q_OBJECT
public:
    enum LogLevel
    {
        LogLevelNone = 0,
        LogLevelError = 1,
        LogLevelWarning = 2,
        LogLevelNotice = 3,
        LogLevelMessage = 4,
        LogLevelLog = 5
    };

public:
    explicit Logger(QObject *parent = 0);
    static QString LevelString(int level);

    Logger& operator <<(const QString &string);
    Logger& operator <<(const QTime &time);
    Logger& operator <<(bool b);
    Logger& operator <<(int i);
    Logger& operator <<(const char *cstr);
signals:

public slots:

private:
};

static Logger& LogInstance()
{
    static Logger logger;
	logger << '\n';
    return logger;
}

#define Log (LogInstance())

#endif // LOGGER_H
