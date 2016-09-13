#ifndef ARGSOPT_H
#define ARGSOPT_H

#include <QMap>

class QString;
class QStringList;

class ArgsOpt
{
public:
    ArgsOpt(const QStringList &args);
    int Mode() const;
    void Parse(const QStringList &args);
    static const int kModeNormal = 0x0;
    static const int kModeTest = 0x1;

private:

    int mMode;
};

#endif // ARGSOPT_H
