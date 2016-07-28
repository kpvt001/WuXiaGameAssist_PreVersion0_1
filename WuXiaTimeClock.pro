#-------------------------------------------------
#
# Project created by QtCreator 2016-06-28T21:38:53
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

PRECOMPILED_HEADER += src/pretable.h

TARGET = WuXiaTimeClock
TEMPLATE = app


SOURCES += src/gametime.cpp \
    src/gametimeserver.cpp \
    src/gametimeserverres.cpp \
    src/gstring.cpp \
    src/gstringhelper.cpp \
    src/gtime.cpp \
    src/gtimehelper.cpp \
    src/main.cpp \
    src/mainwindow.cpp \
    src/projtest.cpp \
    src/wuxiatimeclockpanel.cpp

HEADERS += src/baseconfig.h \
    src/gametime.h \
    src/gametimeserver.h \
    src/gametimeserverres.h \
    src/gstring.h \
    src/gstringhelper.h \
    src/gtime.h \
    src/gtimehelper.h \
    src/mainwindow.h \
    src/projtest.h \
    src/wuxiatimeclockpanel.h \
    src/projcommon.h

FORMS    += src/mainwindow.ui \
    src/wuxiatimeclockpanel.ui

RESOURCES += \
    client_resources.qrc
