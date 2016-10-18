#ifndef QUICKCOPYSTRINGWIDGET_H
#define QUICKCOPYSTRINGWIDGET_H

#include <QWidget>

namespace Ui {
class QuickCopyStringWidget;
}

class QuickCopyStringWidget : public QWidget
{
    Q_OBJECT

public:
    explicit QuickCopyStringWidget(QWidget *parent = 0);
    ~QuickCopyStringWidget();

private:
    void ConfigUi();
    Ui::QuickCopyStringWidget *ui;
};

#endif // QUICKCOPYSTRINGWIDGET_H
