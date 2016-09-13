#include "mainwindow.h"
#include <QApplication>
#include <QDebug>

#include "Settings.h"
#include "ArgsOpt.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    ArgsOpt argsOpt(QApplication::arguments());
    if (argsOpt.Mode() == ArgsOpt::kModeTest)
        Settings::Global().SetTestMode();

    qDebug() << "test mode is " << Settings::Global().IsTestMode();

    MainWindow w;
    w.show();

    return a.exec();
}
