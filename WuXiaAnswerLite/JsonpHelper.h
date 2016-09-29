#ifndef JSONPHELPER_H
#define JSONPHELPER_H

#include <QString>
#include <QJsonDocument>

class JsonpHelper
{
public:
    static QJsonDocument DuowanJsonp(const QByteArray &data, QJsonParseError *error);

private:
    JsonpHelper();
};

#endif // JSONPHELPER_H
