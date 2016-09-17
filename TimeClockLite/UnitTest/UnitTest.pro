TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

PROJECT_DIR = $$PWD

TARGET = "TimeClockLite_UnitTest"
DESTDIR = $$PROJECT_DIR/bin

INCLUDEPATH += ../

SOURCES += \
    WuXiaTimeConfigDatasheet_test.cpp


LIBS += $$PROJECT_DIR/Libs/gtest.lib
LIBS += $$PROJECT_DIR/Libs/gtest_main.lib
