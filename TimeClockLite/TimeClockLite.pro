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
    TimeClockTagContainer.cpp \
    Logger.cpp \
    LogRecord.cpp \
    Timer.cpp \
    TimerUiObjectHolder.cpp \
    Task.cpp \
    BeepRingTask.cpp \
    StringValidity.cpp

HEADERS  += mainwindow.h \
    TimeClockTagContainer.h \
    Logger.h \
    LogRecord.h \
    Timer.h \
    TimerUiObjectHolder.h \
    Task.h \
    BeepRingTask.h \
    StringValidity.h

FORMS    += mainwindow.ui

RESOURCES +=
