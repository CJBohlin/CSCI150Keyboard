TEMPLATE = app
TARGET = server
QT += widgets dbus
QT += opengl
INCLUDEPATH += .
LIBS += -luser32
CONFIG += console

HEADERS += keyboard.h
SOURCES += keyboard.cpp main.cpp
