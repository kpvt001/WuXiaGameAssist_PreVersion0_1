#include "AnswerWindow.h"
#include <QApplication>

#include "DropDownListWidget.h"

#include "DuowanAnswerSource.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    DropDownListWidget w;
    w.show();

    DuowanAnswerSource duowan;
    duowan.RequestAnswerFromPinyin("cqmygysdss");
    return a.exec();
}
