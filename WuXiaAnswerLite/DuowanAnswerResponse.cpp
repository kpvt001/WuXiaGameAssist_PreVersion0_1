#include "DuowanAnswerResponse.h"

#include <QDebug>
#include <QJsonObject>
#include <QString>
#include <QRegExp>


const char* DuowanAnswerResponse::kJsonKeyAnswer = "answer";
const char* DuowanAnswerResponse::kJsonKeyQuestion = "question";

DuowanAnswerResponse::DuowanAnswerResponse()
    : AnswerResponse()
{

}

void DuowanAnswerResponse::AddItemFromJsonObject(const QJsonObject &jsonObject)
{
    AnswerItem item;

    QString question = jsonObject[kJsonKeyQuestion].toString();
    question.remove(QRegExp("<[^><]*>"));

    item.SetQustion(question);
    item.SetAnswer(jsonObject[kJsonKeyAnswer].toString());

    AddItem(item);
}
