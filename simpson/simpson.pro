#-------------------------------------------------
#
# Project created by QtCreator 2016-12-10T17:33:06
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport

TARGET = simpson
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    matrix.cpp \
    gauss.cpp \
    qcustomplot.cpp \
    simpson.cpp

HEADERS  += mainwindow.h \
    matrix.h \
    gauss.h \
    qcustomplot.h \
    simpson.h

FORMS    += mainwindow.ui
