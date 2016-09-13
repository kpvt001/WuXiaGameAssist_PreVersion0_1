/* Copyright (c) 2016, .
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

#include "ArgsOpt.h"
#include <QStringList>
#include <QSet>
#include <QMap>
#include <QString>

class DefaultResource
{
public:
    static DefaultResource& Instance()
    {
        static DefaultResource instance;
        return instance;
    }

private:
    DefaultResource()
    {
        mOptionNames.insert(QString("mode").toLower());
    }
    QSet<QString> mOptionNames;
};

ArgsOpt::ArgsOpt(const QStringList &args)
{
    Parse(args);
}

int ArgsOpt::Mode() const
{
    return mMode;
}

void ArgsOpt::Parse(const QStringList &args)
{
    QString arg;
    Q_FOREACH(arg, args)
    {
        if(arg.toLower().startsWith("--mode="))
        {
            QString option = arg.split('=').last();
            if(option.toLower() == "test")
                mMode = kModeTest;
            else
                mMode = kModeNormal;
        }
    }
}
