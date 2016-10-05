#ifndef DROPDOWNLISTWIDGET_H
#define DROPDOWNLISTWIDGET_H

#include <QWidget>

namespace Ui {
class DropDownListWidget;
}

class QString;
class AnswerResponse;
class QTimerEvent;

class DropDownListWidget : public QWidget
{
    Q_OBJECT

public:
    explicit DropDownListWidget(QWidget *parent = 0);
    ~DropDownListWidget();

protected:
    virtual void timerEvent(QTimerEvent *event);
    void DoResponseError(int errorCode);

protected slots:
    virtual void onContentListComboBoxEditTextChanged(const QString &text);
    virtual void onAnswerResponseReady(AnswerResponse *response);
    virtual void onGetAnswer(const QString &pinyin);
    virtual void onApplicationStateChanged(Qt::ApplicationState state);
    virtual void OnAppActive();

private:
    void ConnectObjects();
    void ConfigUi();

    int mLastRequestId;
    int mRequestTimerEventId;
    bool mRequestReached;
    static const float kRequestTimerInterval;
    QString mLastRequestPinyin;
    Ui::DropDownListWidget *ui;
};

#endif // DROPDOWNLISTWIDGET_H
