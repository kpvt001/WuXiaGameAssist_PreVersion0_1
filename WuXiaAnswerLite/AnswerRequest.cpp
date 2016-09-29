#include "AnswerRequest.h"

std::atomic_int AnswerRequest::sCurrentId = 0;
AnswerRequest::AnswerRequest(const QString &pinyin, QObject *parent)
    : mId(++sCurrentId), mRequestPinyin(pinyin)
    , QObject(parent)
{
}


void AnswerRequest::onAnswerReady(AnswerResponse *answerResponse)
{
    emit responseReady(answerResponse);
}
