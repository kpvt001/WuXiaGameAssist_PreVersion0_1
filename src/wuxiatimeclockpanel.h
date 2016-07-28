#ifndef WUXIATIMECLOCKPANEL_H
#define WUXIATIMECLOCKPANEL_H

#include <QWidget>

namespace Ui {
class WuXiaTimeClockPanel;
}

class WuXiaTimeClockPanel : public QWidget
{
    Q_OBJECT

public:
    explicit WuXiaTimeClockPanel(QWidget *parent = 0);
    ~WuXiaTimeClockPanel();

private:
    Ui::WuXiaTimeClockPanel *ui;
};

#endif // WUXIATIMECLOCKPANEL_H
