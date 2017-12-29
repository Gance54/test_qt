#-------------------------------------------------
#
# Project created by QtCreator 2017-09-02T21:09:36
#
#-------------------------------------------------

QT       += core gui
QT       += sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = testqt
TEMPLATE = app

CONFIG += c++11

SOURCES += main.cpp\
        mainwindow.cpp \
    calendar.cpp \
    database.cpp \
    exception.cpp \
    listview.cpp \
    fileoperations.cpp \
    main_db/maindatabase.cpp

HEADERS  += mainwindow.h \
    ui_mainwindow.h \
    ui_calendar.h \
    calendar.h \
    database.h \
    exception.h \
    ui_listview.h \
    listview.h \
    fileoperations.h \
    main_db/maindatabase.h

FORMS    += mainwindow.ui \
    calendar.ui \
    listview.ui

DISTFILES += \
    testqt
