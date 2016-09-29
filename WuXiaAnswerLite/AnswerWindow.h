#ifndef ANSWERWINDOW_H
#define ANSWERWINDOW_H

#include <QWidget>

namespace Ui {
class AnswerWindow;
}

class AnswerWindow : public QWidget
{
    Q_OBJECT

public:
    explicit AnswerWindow(QWidget *parent = 0);
    ~AnswerWindow();

private:
    Ui::AnswerWindow *ui;
};

#endif // ANSWERWINDOW_H
