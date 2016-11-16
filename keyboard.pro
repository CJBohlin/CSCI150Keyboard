TEMPLATE = app
TARGET = server
QT += widgets dbus
QT += opengl
INCLUDEPATH += .
LIBS += -luser32

HEADERS += keyboard.h \
    mainwindow.h \
    globals.h
SOURCES += keyboard.cpp \
    main.cpp \
    mainwindow.cpp \
    globals.cpp

#QT += widgets

#HEADERS       = mainwindow.h
#SOURCES       = mainwindow.cpp \
#                main.cpp

# install
target.path = $$[QT_INSTALL_EXAMPLES]/widgets/mainwindows/menus
INSTALLS += target

FORMS += \
    keyboard.ui

DISTFILES += \
    keyboard.pro.user \
    keyboard.pro.user.ffcfcd9
