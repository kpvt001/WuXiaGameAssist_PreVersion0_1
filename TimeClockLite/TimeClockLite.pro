#-------------------------------------------------
#
# Project created by QtCreator 2016-09-08T03:39:32
#
#-------------------------------------------------

QT       += core gui
QT += multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = TimeClockLite
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    Logger.cpp \
    Timer.cpp \
    TimerUiObjectHolder.cpp \
    BeepRingTask.cpp \
    StringValidity.cpp \
    TestPanel.cpp \
    Settings.cpp \
    ArgsOpt.cpp \
    GlobalVariables.cpp \
    Global.cpp \
    WuXiaTimeConfig.cpp

HEADERS  += mainwindow.h \
    Logger.h \
    Timer.h \
    TimerUiObjectHolder.h \
    BeepRingTask.h \
    StringValidity.h \
    TestPanel.h \
    Settings.h \
    ArgsOpt.h \
    GlobalVariables.h \
    Global.h \
    WuXiaTimeConfig.h \
    WuXiaTimeConfigDataSheet.h

FORMS    += mainwindow.ui \
    testpanel.ui

RESOURCES +=
