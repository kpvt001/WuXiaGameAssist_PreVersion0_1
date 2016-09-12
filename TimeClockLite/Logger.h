#ifndef LOGGER_H
#define LOGGER_H

#include <QObject>
#include <QString>
#include <QTime>
#include <QDate>
#include <QTextStream>



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
    static Logger& StaticLogger();
    static QString LevelString(int level);

    void SetFilePath(const QString &path);
    void Flush();

    Logger& operator <<(const QString &string);
    Logger& operator <<(const QTime &time);
    Logger& operator <<(bool b);
    Logger& operator <<(int i);
    Logger& operator <<(const char *cstr);
signals:

public slots:

private:
    bool Open();
    void Close();

    QString mPath;


public:

};

static Logger& LogInstance()
{
    static Logger logger;
	logger << '\n';
    return logger;
}

#define Log (LogInstance())

#endif // LOGGER_H
