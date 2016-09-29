#ifndef ANSWERITEM_H
#define ANSWERITEM_H

#include <QString>

class AnswerItem
{
    friend class AnswerSource;

public:
    AnswerItem();
    QString Qustion() const { return mQuestion; }
    QString Answer() const { return mAnswer; }
    QString QustionPinyin() const { return mQuestionPinyin; }

    void SetQustion(const QString &string) { mQuestion = string; }
    void SetAnswer(const QString &string) { mAnswer = string; }

private:
    QString mQuestion;
    QString mAnswer;
    QString mQuestionPinyin;
    QString mQuestionHash;
    QString mQuestionId;
};

#endif // ANSWERITEM_H
