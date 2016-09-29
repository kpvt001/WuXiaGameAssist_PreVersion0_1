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

protected slots:
    virtual void onContentListComboBoxEditTextChanged(const QString &text);
    virtual void onInputLineEditTextChanged(const QString &text);
    virtual void onAnswerResponseReady(AnswerResponse *response);
    virtual void onGetAnswer(const QString &pinyin);

private:
    void connectObjects();
    void configUi();

    int mLastRequestId;
    Ui::DropDownListWidget *ui;
};

#endif // DROPDOWNLISTWIDGET_H
