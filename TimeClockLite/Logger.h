/* Copyright (c) 2016, %{Owner}%.
 * All rights reserved.

 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice, this
 *    list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR
 * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

 * The views and conclusions contained in the software and documentation are those
 * of the authors and should not be interpreted as representing official policies,
 * either expressed or implied, of the FreeBSD Project.
 */

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
