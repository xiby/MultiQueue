#-------------------------------------------------
#
# Project created by QtCreator 2017-03-28T23:22:22
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Multiqueue_Qt
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    ../Code/list_controller.cpp \
    ../Code/MultiQueue.cpp \
    ../Code/process.cpp \
    mycustomslider.cpp

HEADERS  += mainwindow.h \
    ../Code/list_controller.h \
    ../Code/MultiQueue.h \
    ../Code/process.h \
    mycustomslider.h

FORMS    += mainwindow.ui

RESOURCES += \
    test.qrc
