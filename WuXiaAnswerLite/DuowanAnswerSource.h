#ifndef DUOWANANSWERSOUCE_H
#define DUOWANANSWERSOUCE_H

#include "AnswerSource.h"

class QNetworkReply;

class DuowanAnswerSource : public AnswerSource
{
    Q_OBJECT
public:
    explicit DuowanAnswerSource(QObject *parent = 0);

    virtual void RequestAnswerFromPinyin(const QString &pinyin);
    virtual void RequestAnswer(const AnswerRequest &request);

public slots:
    virtual void onNetReplyFinished(QNetworkReply *reply);

private:
    static const char *kSourceUri;
    static const char *kUriAppendParam;

    static const int kRequestMiniIntervalMs;
};

#endif // DUOWANANSWERSOUCE_H
