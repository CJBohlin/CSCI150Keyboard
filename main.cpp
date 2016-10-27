#include <QApplication>
#include <QtDBus/QDBusConnection>
#include <qt_windows.h>

#include "keyboard.h"

using namespace QDBus;

int main(int argc, char **argv)
{
    QApplication app(argc, argv);

    Keyboard keyboard;
    keyboard.setWindowTitle(" ");
    keyboard.showKeyboard(500,600);
    HWND winHandle=(HWND)keyboard.winId();
    SetWindowLong(winHandle, GWL_EXSTYLE, GetWindowLong(winHandle, GWL_EXSTYLE)
        | WS_EX_NOACTIVATE | WS_EX_APPWINDOW);
    ShowWindow(winHandle, SW_SHOW);

    return app.exec();
}
