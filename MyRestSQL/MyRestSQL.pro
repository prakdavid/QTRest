#-------------------------------------------------
#
# Project created by QtCreator 2014-07-25T16:39:41
#
#-------------------------------------------------

QT       += core network

QT       -= gui

TARGET = MyRestSQL
CONFIG   += console
CONFIG   -= app_bundle

CONFIG += debug

TEMPLATE = app

win32 {
    debug: LIBS += -lqhttpserverd
    else: LIBS += -lqhttpserver
} else {
    LIBS += -lqhttpserver
}

SOURCES += main.cpp \
    myserver.cpp    \
    usercontroller.cpp

HEADERS += \
    myserver.h    \
    controller.h \
    factory.h     \
    usercontroller.h

