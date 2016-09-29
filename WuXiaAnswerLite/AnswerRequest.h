#ifndef ANSWERREQUEST_H
#define ANSWERREQUEST_H

#include <QString>
#include <QObject>
#include <atomic>

class AnswerResponse;

class AnswerRequest : public QObject
{
    Q_OBJECT
public:
    AnswerRequest(const QString &pinyin, QObject *parent = nullptr);
    int Id() const {return mId;}
    virtual void Request() = 0;
    QString Pinyin() const { return mRequestPinyin; }


signals:
    void responseReady(AnswerResponse *response);

protected slots:
    virtual void onAnswerReady(AnswerResponse *answerResponse);

private:
    QString mRequestPinyin;
    int mId;

    static std::atomic_int sCurrentId;
};

#endif // ANSWERREQUEST_H
