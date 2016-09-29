#include "AnswerWindow.h"
#include "ui_AnswerWindow.h"

AnswerWindow::AnswerWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AnswerWindow)
{
    ui->setupUi(this);
}

AnswerWindow::~AnswerWindow()
{
    delete ui;
}
