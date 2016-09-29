#include "AnswerResponse.h"

AnswerResponse::AnswerResponse()
    : mError(NoError)
{

}

AnswerResponse* AnswerResponse::ResponseForJsonParseError()
{
    AnswerResponse *r = new AnswerResponse;
    r->mError = ErrorJsonParse;
    return r;
}

AnswerResponse* AnswerResponse::ResponseForNetworkFailed()
{
    AnswerResponse *r = new AnswerResponse;
    r->mError = ErrorNetworkFailed;
    return r;
}

void AnswerResponse::AddItem(const AnswerItem &item)
{
    mItems.append(item);
}

void AnswerResponse::AddItemFromJsonObject(const QJsonObject &jsonObject)
{
    Q_UNUSED(jsonObject);
    throw "Cannot call this function.";
}

