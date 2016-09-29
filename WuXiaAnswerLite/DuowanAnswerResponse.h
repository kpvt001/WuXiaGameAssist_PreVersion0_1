#ifndef DUOWANANSWERRESPONSE_H
#define DUOWANANSWERRESPONSE_H

#include "AnswerResponse.h"
class DuowanAnswerResponse : public AnswerResponse
{
public:
    DuowanAnswerResponse();

    virtual void AddItemFromJsonObject(const QJsonObject &jsonObject);

    static const char* kJsonKeyQuestion;
    static const char* kJsonKeyAnswer;
};

#endif // DUOWANANSWERRESPONSE_H
