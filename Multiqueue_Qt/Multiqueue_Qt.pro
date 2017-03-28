#-------------------------------------------------
#
# Project created by QtCreator 2017-03-28T12:56:02
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Multiqueue_Qt
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    ../MultiQueue/TestWFP/Code/list_controller.cpp \
    ../MultiQueue/TestWFP/Code/MultiQueue.cpp \
    ../MultiQueue/TestWFP/Code/process.cpp

HEADERS  += mainwindow.h \
    ../MultiQueue/TestWFP/Code/list_controller.h \
    ../MultiQueue/TestWFP/Code/MultiQueue.h \
    ../MultiQueue/TestWFP/Code/process.h

FORMS    += mainwindow.ui
