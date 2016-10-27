TEMPLATE = app
TARGET = server
QT += widgets dbus
INCLUDEPATH += .
LIBS += -luser32

HEADERS += keyboard.h
SOURCES += keyboard.cpp main.cpp
