#ifndef ANSWERRESPONSE_H
#define ANSWERRESPONSE_H

#include "AnswerItem.h"
#include <QList>

class QJsonObject;
class AnswerRequest;

class AnswerResponse
{
public:
    enum ResponseError
    {
        OK = 0,
        NoError = 0,
        ErrorNetworkFailed,
        ErrorJsonParse
    };

public:
    AnswerResponse();
    int Error() const { return mError; }
    int RequestId() const { return mRequestId; }
    void SetRequestId(int id) { mRequestId = id; }
    bool IsError() const { return mError != NoError; }
    void SetRequest(AnswerRequest *request) {mRequest = request;}
    void AddItem(const AnswerItem &item);
    AnswerRequest* Request() const {return mRequest;}
    const QList<AnswerItem>& Items() const { return mItems; }
    virtual void AddItemFromJsonObject(const QJsonObject &jsonObject);

    static AnswerResponse* ResponseForNetworkFailed();
    static AnswerResponse* ResponseForJsonParseError();

private:
    int mError;
    int mRequestId;
    QList<AnswerItem> mItems;
    AnswerRequest *mRequest;
};

#endif // ANSWERRESPONSE_H
