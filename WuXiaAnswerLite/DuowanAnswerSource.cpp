#include "DuowanAnswerSource.h"

#include "Global.h"

#include <atomic>

#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkReply>
#include <QtNetwork/QNetworkRequest>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>
#include <QJsonValue>
#include <QTime>

#include "JsonpHelper.h"
#include "DuowanAnswerResponse.h"


const char* DuowanAnswerSource::kSourceUri = "http://huodong.duowan.com/wxdatiqi/backend/index.php";
const char* DuowanAnswerSource::kUriAppendParam = "r=index/GetQuestionByKeyword&callback=jsonpReturn&keyword=%1";
const int DuowanAnswerSource::kRequestMiniIntervalMs = 500;

DuowanAnswerSource::DuowanAnswerSource(QObject *parent)
    : AnswerSource(parent)
{

}

void DuowanAnswerSource::RequestAnswerFromPinyin(const QString &pinyin)
{
#if 0
    static QTime lastRequestTime = QTime::currentTime();
    static std::atomic_bool isFirstRequest = true;
    QTime currentTime = QTime::currentTime();
    if (!isFirstRequest && lastRequestTime.msecsTo(currentTime) < kRequestMiniIntervalMs)
    {
        qDebug().nospace() << "DuowanAnswerSource::RequestAnswerFromPinyin: "
                 << "Request Ingored because too fast. The min interval is "
                 << kRequestMiniIntervalMs << "ms";

        return;
    }


    lastRequestTime = currentTime;
    isFirstRequest = false;
#endif

    qDebug() << "request:" << pinyin;
    static QString sourceUri = QString(kSourceUri);
    static QString uriAppendParam = QString(kUriAppendParam);

    QNetworkAccessManager *mgr = new QNetworkAccessManager(this);

    connect(mgr, SIGNAL(finished(QNetworkReply*)), this, SLOT(onNetReplyFinished(QNetworkReply*)));
    QString getString = sourceUri + '?' + uriAppendParam.arg(pinyin);
    mgr->get(QNetworkRequest(QUrl(getString)));
}

void DuowanAnswerSource::onNetReplyFinished(QNetworkReply *reply)
{
    if (reply->error() != QNetworkReply::NoError)
    {
        qDebug() << "QNetwork error";
        emit answerReady(AnswerResponse::ResponseForNetworkFailed());
        reply->deleteLater();
        return;
    }

    QJsonParseError jsonParseError;
    QJsonDocument jsonDoc = JsonpHelper::DuowanJsonp(reply->readAll(), &jsonParseError);
    if (jsonParseError.error != QJsonParseError::NoError)
    {
        qDebug() << jsonParseError.errorString();
        emit answerReady(AnswerResponse::ResponseForJsonParseError());
        return;
    }

    QJsonArray answersJson = jsonDoc.array();
    AnswerResponse *response = new DuowanAnswerResponse;
    QJsonValue jsonValue;
    Q_FOREACH(jsonValue, answersJson)
    {
        if (!jsonValue.isObject())
            continue;

        response->AddItemFromJsonObject(jsonValue.toObject());
    }

    emit answerReady(response);
    reply->deleteLater();
}

void DuowanAnswerSource::RequestAnswer(const AnswerRequest &request)
{
    Q_UNUSED(request)
}
