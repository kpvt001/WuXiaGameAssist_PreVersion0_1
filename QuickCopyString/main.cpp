#include "QuickCopyStringWidget.h"
#include <QApplication>
#include <QSplitter>
#include <QListWidget>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QuickCopyStringWidget w;
    w.show();

    return a.exec();
}
