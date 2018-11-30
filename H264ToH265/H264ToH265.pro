QT += core
QT -= gui

TARGET = H264ToH265
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

chip=HI3531D
include(../../../LinkLib/Link.pri)

SOURCES += main.cpp \
    Worker.cpp

HEADERS += \
    Worker.h

