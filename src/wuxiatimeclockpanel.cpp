#include "wuxiatimeclockpanel.h"
#include "ui_wuxiatimeclockpanel.h"

WuXiaTimeClockPanel::WuXiaTimeClockPanel(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::WuXiaTimeClockPanel)
{
    ui->setupUi(this);
}

WuXiaTimeClockPanel::~WuXiaTimeClockPanel()
{
    delete ui;
}
