#-------------------------------------------------
#
# Project created by QtCreator 2017-09-02T21:09:36
#
#-------------------------------------------------

QT       += core
QT       += gui
QT       += sql
QT       += network
QT       += widgets
QT       += charts
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = testqt
TEMPLATE = app

CONFIG += c++11

SOURCES += main.cpp\
        mainwindow.cpp \
    listview.cpp \
    labelmapper.cpp \
    product.cpp \
    order.cpp \
    connectivitymanager.cpp

HEADERS  += mainwindow.h \
    ui_mainwindow.h \
    ui_listview.h \
    listview.h \
    labelmapper.h \
    product.h \
    order.h \
    connectivitymanager.h

FORMS    += mainwindow.ui \
    listview.ui
