#include "mainwindow.h"
#include <QApplication>

#include "Logger.h"
#include <QDebug>

int main(int argc, char *argv[])
{
	Log << 123;
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
