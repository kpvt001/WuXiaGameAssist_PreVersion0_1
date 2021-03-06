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
        ret.remove(jsonpTag + '(');
        ret.remove(");");
        return ret;
    }
}

JsonpHelper::JsonpHelper()
{

}

QJsonDocument JsonpHelper::DuowanJsonp(const QByteArray &data, QJsonParseError *error)
{
    QString jsonContent = ByteArray2Utf8String(data);
    QJsonDocument jsonDoc;
    if (jsonContent == "jsonpReturn(null);")
        jsonDoc = QJsonDocument::fromJson("{}", error);
    else
    {
        jsonContent = RemoveJsonpTag(jsonContent, "jsonpReturn");
        jsonDoc = QJsonDocument::fromJson(jsonContent.toUtf8(), error);
    }

    return jsonDoc;
}
