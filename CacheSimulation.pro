#-------------------------------------------------
#
# Project created by QtCreator 2016-11-29T12:20:01
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = CacheSimulation
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    fullyassociative.cpp \
    directmapped.cpp \
    setassoc.cpp

HEADERS  += mainwindow.h \
    fullyassociative.h \
    directmapped.h \
    setassoc.h

FORMS    += mainwindow.ui
