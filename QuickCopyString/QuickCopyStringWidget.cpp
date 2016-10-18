#include "QuickCopyStringWidget.h"
#include "ui_QuickCopyStringWidget.h"

QuickCopyStringWidget::QuickCopyStringWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::QuickCopyStringWidget)
{
    ui->setupUi(this);

    ConfigUi();
}

QuickCopyStringWidget::~QuickCopyStringWidget()
{
    delete ui;
}

void QuickCopyStringWidget::ConfigUi()
{

}
