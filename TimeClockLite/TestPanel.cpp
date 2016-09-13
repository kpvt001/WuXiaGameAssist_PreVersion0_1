/* Copyright (c) 2016, .
 * All rights reserved.

 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice, this
 *    list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR
 * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

 * The views and conclusions contained in the software and documentation are those
 * of the authors and should not be interpreted as representing official policies,
 * either expressed or implied, of the FreeBSD Project.
 */

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
