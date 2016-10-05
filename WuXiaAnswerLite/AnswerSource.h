#ifndef ANSWERSOURCE_H
#define ANSWERSOURCE_H

#include <QObject>
#include <QList>
#include "AnswerItem.h"
#include "AnswerResponse.h"
#include "AnswerRequest.h"

class AnswerSource : public QObject
{
    Q_OBJECT
public:
    explicit AnswerSource(QObject *parent = 0);

    virtual void RequestAnswer(const AnswerRequest &request) = 0;

signals:
    void answerReady(AnswerResponse *answerResponses);

public slots:

};

#endif // ANSWERSOURCE_H
