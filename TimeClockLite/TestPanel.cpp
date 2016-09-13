#include "TestPanel.h"
#include "ui_testpanel.h"
#include <QVector>

#include <QDebug>

#include "Settings.h"
#include "GlobalVariables.h"

class TestOptionUiGroupHolder
{
    friend class TestPanel;

    void EnableAll(bool enable = true)
    {
        QWidget *widget;
        Q_FOREACH(widget, mWidgets)
        {
            widget->setEnabled(enable);
        }
    }

    void DisableAll()
    {
        EnableAll(false);
    }

    void Visible(bool show = true)
    {
        QWidget *widget;
        Q_FOREACH(widget, mWidgets)
        {
            widget->setVisible(show);
        }
    }

    void AddWidget(QWidget *widget)
    {
        mWidgets.append(widget);
    }

    QVector<QWidget*> mWidgets;
};

TestPanel::TestPanel(QWidget *parent)
    : ui(new Ui::TestPanel)
    , QDialog(parent)
{
    ui->setupUi(this);
	ConfigUi();
    ConnectObjects();
}

TestPanel::~TestPanel()
{
    delete ui;
}

void TestPanel::ConfigUi()
{
    ui->useCustomCurrentTimeCheckBox->setChecked(false);
    EnableCustomCurrentTime(false);
    Settings::Global().SetUseTestCurrentTime(false);
}

void TestPanel::ConnectObjects()
{
    connect(ui->useCustomCurrentTimeCheckBox, SIGNAL(clicked(bool)), this, SLOT(OnUseCustomCurrentTimeCheckBoxChecked(bool)));
    connect(ui->confirmCustomCurrentTimePushButton, SIGNAL(clicked(bool)), this, SLOT(OnConfirmCustomCurrentTimePushButtonClicked(bool)));
}

void TestPanel::ConfigTestOptionUiGroupHolders()
{
    // custom current time

}

void TestPanel::OnUseCustomCurrentTimeCheckBoxChecked(bool checked)
{
    EnableCustomCurrentTime(checked);
}

void TestPanel::OnConfirmCustomCurrentTimePushButtonClicked(bool checked)
{
    qDebug() << "confirm pressed";
    Q_UNUSED(checked);

    GVar().SetTestCurrentTime(ui->testCurrentTimeEdit->time());
}

void TestPanel::EnableCustomCurrentTime(bool enable)
{
    ui->testCurrentTimeEdit->setEnabled(enable);
    ui->confirmCustomCurrentTimePushButton->setEnabled(enable);
    Settings::Global().SetUseTestCurrentTime(enable);
}
