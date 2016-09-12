#ifndef TESTPANEL_H
#define TESTPANEL_H

#include <QWidget>

namespace Ui {
    class TestPanel;
}

class TestPanel : public QWidget
{
    Q_OBJECT
public:
    explicit TestPanel(QWidget *parent = 0);

private:
    Ui::TestPanel *ui;

signals:

public slots:
};

#endif // TESTPANEL_H
