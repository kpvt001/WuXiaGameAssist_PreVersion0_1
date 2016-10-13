#ifndef DROPDOWNLISTWIDGET_H
#define DROPDOWNLISTWIDGET_H

#include <QWidget>

#include <atomic>

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
    QString AnswerResultMaskString() const;

protected slots:
    virtual void onContentListComboBoxEditTextChanged(const QString &text);
    virtual void onAnswerResponseReady(AnswerResponse *response);
    virtual void onGetAnswer(const QString &pinyin);
    virtual void onApplicationStateChanged(Qt::ApplicationState state);
    virtual void OnAppActive();
    virtual void onEmptyInputEdit();
    virtual void onResetEmptyListWidget();

private:
    void ConnectObjects();
    void ConfigUi();

    std::atomic_int mLastRequestId;
    int mRequestTimerEventId;
    static const int kRequestTimerInterval;
    QString mLastSuccessedRequestPinyin;
    QString mRequestingPinyin;
    Ui::DropDownListWidget *ui;
};

#endif // DROPDOWNLISTWIDGET_H
