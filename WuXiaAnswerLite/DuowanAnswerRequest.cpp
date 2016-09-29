#include "DuowanAnswerRequest.h"
#include "DuowanAnswerSource.h"

DuowanAnswerRequest::DuowanAnswerRequest(const QString &pinyin, QObject *parent)
    : AnswerRequest(pinyin, parent)
{

}

void DuowanAnswerRequest::Request()
{
    DuowanAnswerSource *answerSource = new DuowanAnswerSource(this);
    connect(answerSource, SIGNAL(answerReady(AnswerResponse*)), this, SLOT(onAnswerReady(AnswerResponse*)));
    answerSource->RequestAnswerFromPinyin(Pinyin());
}


void DuowanAnswerRequest::onAnswerReady(AnswerResponse *answerResponse)
{
    answerResponse->SetRequestId(Id());
    answerResponse->SetRequest(this);
    emit responseReady(answerResponse);
}
