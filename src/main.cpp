#include "mainwindow.h"
#include <QApplication>

#include "projtest.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    ProjectTest test;
    test.RunTest();

    return a.exec();
}
