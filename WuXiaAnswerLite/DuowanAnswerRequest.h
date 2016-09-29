#ifndef DUOWANANSWERREQUEST_H
#define DUOWANANSWERREQUEST_H

#include "AnswerRequest.h"
#include <QObject>

class DuowanAnswerRequest : public AnswerRequest
{
    Q_OBJECT
public:
    DuowanAnswerRequest(const QString &pinyin, QObject *parent = nullptr);

    virtual void Request();

protected slots:
    virtual void onAnswerReady(AnswerResponse *response);
};

#endif // DUOWANANSWERREQUEST_H
