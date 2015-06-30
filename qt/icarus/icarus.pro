#-------------------------------------------------
#
# Project created by QtCreator 2015-06-27T16:30:35
#
#-------------------------------------------------

QT       += core \
            serialport

QT       -= gui

TARGET = icarus
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += \
    communication/LinkLayerIcarus.cpp \
    communication/SerialIcarus.cpp \
    communication/ConfigFile.cpp \
    communication/messages/MsgBase.cpp \
    communication/messages/MsgData.cpp \
    Icarus.cpp

HEADERS += \
    communication/LinkLayerIcarus.h \
    communication/SerialIcarus.h \
    communication/ConfigFile.h \
    communication/messages/MsgBase.h \
    communication/messages/MsgData.h \
    Icarus.h
