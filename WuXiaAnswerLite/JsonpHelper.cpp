#include "JsonpHelper.h"

#include <QDebug>
#include <QTextCodec>

namespace {
    inline QString ByteArray2Utf8String(const QByteArray &data)
    {
        QTextCodec *codec = QTextCodec::codecForName("utf-8");
        return codec->toUnicode(data);
    }

    inline QString RemoveJsonpTag(const QString &string, const QString &jsonpTag)
    {
        QString ret = string;
        ret = ret.remove(jsonpTag + '(');
        return ret.replace("}]);", "}]");
    }
}

JsonpHelper::JsonpHelper()
{

}

QJsonDocument JsonpHelper::DuowanJsonp(const QByteArray &data, QJsonParseError *error)
{
    QString jsonContent = ByteArray2Utf8String(data);

    jsonContent = RemoveJsonpTag(jsonContent, "jsonpReturn");

    QJsonDocument jsonDoc = QJsonDocument::fromJson(jsonContent.toUtf8(), error);

    return jsonDoc;
}
