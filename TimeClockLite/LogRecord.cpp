#include "LogRecord.h"
#include "Logger.h"

int LogRecord::kCount = 0;

QString LogRecord::ToLogString()
{
    Tick();
    static const QString stringFormat = "%1 %2:%3, (%4, %5)"; // "level/date time, content"
    return stringFormat
            .arg(kCount)
            .arg(Logger::LevelString(mLevel))
            .arg(mContent)
            .arg(mDate.toString("yyyy-MM-dd"))
            .arg(mTime.toString("hh:mm:ss.zzz"));
}

void LogRecord::Tick()
{
    kCount++;
}
