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
