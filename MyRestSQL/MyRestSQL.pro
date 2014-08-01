#-------------------------------------------------
#
# Project created by QtCreator 2014-07-25T16:39:41
#
#-------------------------------------------------

QT       += core network xml sql

QT       -= gui

TARGET = MyRestSQL
CONFIG   += console
CONFIG   -= app_bundle

CONFIG += debug

TEMPLATE = app

include(qtservice/src/qtservice.pri)

win32 {
    debug: LIBS += -lqhttpserverd
    else: LIBS += -lqhttpserver
} else {
    LIBS += -lqhttpserver
}

SOURCES += main.cpp \
    myserver.cpp     \
    myservice.cpp     \
    controller.cpp     \
    usercontroller.cpp

HEADERS += \
    myserver.h   \
    myservice.h   \
    controller.h     \
    usercontroller.h

