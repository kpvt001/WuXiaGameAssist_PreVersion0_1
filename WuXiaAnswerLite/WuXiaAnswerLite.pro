#-------------------------------------------------
#
# Project created by QtCreator 2016-09-28T05:48:34
#
#-------------------------------------------------

QT       += core gui
QT      += network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = TDAnswerFinder
TEMPLATE = app


SOURCES += main.cpp\
        AnswerWindow.cpp \
    DropDownListWidget.cpp \
    AnswerSource.cpp \
    AnswerItem.cpp \
    AnswerRequest.cpp \
    AnswerResponse.cpp \
    DuowanAnswerSource.cpp \
    JsonpHelper.cpp \
    DuowanAnswerResponse.cpp \
    DuowanAnswerRequest.cpp \
    StringTable.cpp

HEADERS  += AnswerWindow.h \
    DropDownListWidget.h \
    Global.h \
    AnswerSource.h \
    AnswerItem.h \
    AnswerRequest.h \
    AnswerResponse.h \
    DuowanAnswerSource.h \
    JsonpHelper.h \
    DuowanAnswerResponse.h \
    DuowanAnswerRequest.h \
    Version.h \
    StringTable.h

FORMS    += AnswerWindow.ui \
    DropDownListWidget.ui

RC_FILE += WuXiaAnswerLite.rc
