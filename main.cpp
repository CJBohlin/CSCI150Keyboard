#include <QApplication>
#include <QtDBus/QDBusConnection>
#include <qt_windows.h>
#include "keyboard.h"
#include <QMenuBar>
#include <QMainWindow>
#include <QMenu>
#include <iostream>
int main(int argc, char **argv)
{
    QApplication app(argc, argv);
    QPalette pal = app.palette();
    pal.setColor(QPalette::Window, Qt::lightGray);
    app.setPalette(pal);
    app.setStyleSheet("#myObject { border: 5px solid black; }");

    RECT desktop;
    const HWND hDesktop = GetDesktopWindow();
    GetWindowRect(hDesktop, &desktop);
    double horizontal = desktop.right;
    double vertical = desktop.bottom;

    Keyboard keyboard;
    keyboard.showKeyboard((horizontal-900)/2,vertical-600);
    HWND winHandle=(HWND)keyboard.winId();
    SetWindowLong(winHandle, GWL_EXSTYLE, GetWindowLong(winHandle, GWL_EXSTYLE)
        | WS_EX_NOACTIVATE | WS_EX_APPWINDOW);
    ShowWindow(winHandle, SW_SHOW);
    keyboard.setWindowTitle(" ");
    return app.exec();
}
