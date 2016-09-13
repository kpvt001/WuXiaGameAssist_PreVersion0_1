#ifndef TESTPANEL_H
#define TESTPANEL_H

#include <QDialog>

namespace Ui {
    class TestPanel;
}

class TestPanel : public QDialog
{
    Q_OBJECT
public:
    explicit TestPanel(QWidget *parent = 0);
    virtual ~TestPanel();

private:
    void ConnectObjects();
    void ConfigTestOptionUiGroupHolders();
    void EnableCustomCurrentTime(bool enable = true);
    void ConfigUi();

    Ui::TestPanel *ui;

signals:

public slots:
    void OnUseCustomCurrentTimeCheckBoxChecked(bool checked);
    void OnConfirmCustomCurrentTimePushButtonClicked(bool checked);
};

#endif // TESTPANEL_H
