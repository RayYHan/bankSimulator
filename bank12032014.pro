#-------------------------------------------------
#
# Project created by QtCreator 2014-12-03T17:54:44
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = bank12032014
TEMPLATE = app


SOURCES += main.cpp\
        widget.cpp \
    bbQueue.cpp \
    customer.cpp \
    teller.cpp

HEADERS  += widget.h \
    bbQueue.h \
    customer.h \
    teller.h

FORMS    += widget.ui
