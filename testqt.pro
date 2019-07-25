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
QT       += concurrent
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = testqt
TEMPLATE = app

CONFIG += c++11

SOURCES += main.cpp\
        mainwindow.cpp \
    labelmapper.cpp \
    marketlistview.cpp \
    product.cpp \
    order.cpp \
    connectivitymanager.cpp \
    productlistwidgetitem.cpp

HEADERS  += mainwindow.h \
    marketlistview.h \
    ui_mainwindow.h \
    ui_listview.h \
    labelmapper.h \
    product.h \
    order.h \
    connectivitymanager.h \
    productlistwidgetitem.h

FORMS    += mainwindow.ui \
    marketlistview.ui
