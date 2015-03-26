#-------------------------------------------------
#
# Project created by QtCreator 2015-03-03T10:21:08
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = triggers
TEMPLATE = app


SOURCES += main.cpp\
    triggermanager.cpp \
    trigger.cpp \
    controller.cpp

HEADERS  += \
    triggermanager.h \
    trigger.h \
    controller.h

FORMS    += mainwindow.ui

QMAKE_CXXFLAGS += -std=c++0x
