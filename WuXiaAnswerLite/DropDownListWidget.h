#ifndef DROPDOWNLISTWIDGET_H
#define DROPDOWNLISTWIDGET_H

#include <QWidget>

namespace Ui {
class DropDownListWidget;
}

class QString;
class AnswerResponse;

class DropDownListWidget : public QWidget
{
    Q_OBJECT

public:
    explicit DropDownListWidget(QWidget *parent = 0);
    ~DropDownListWidget();

protected:

protected slots:
    virtual void onContentListComboBoxEditTextChanged(const QString &text);
    virtual void onInputLineEditTextChanged(const QString &text);
    virtual void onAnswerResponseReady(AnswerResponse *response);
    virtual void onGetAnswer(const QString &pinyin);
    virtual void onApplicationStateChanged(Qt::ApplicationState state);
    virtual void OnAppActive();

private:
    void ConnectObjects();
    void ConfigUi();

    int mLastRequestId;
    Ui::DropDownListWidget *ui;
};

#endif // DROPDOWNLISTWIDGET_H
