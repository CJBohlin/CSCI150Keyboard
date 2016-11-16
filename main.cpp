#include <QApplication>
#include <QtDBus/QDBusConnection>
#include <qt_windows.h>
#include "keyboard.h"
#include <QMenuBar>
#include <QMainWindow>
#include <QMenu>
#include <iostream>
#include "mainwindow.h"

int main(int argc, char **argv)
{
    QApplication *app = new QApplication(argc, argv);
    QPalette pal = app->palette();
    pal.setColor(QPalette::Window, Qt::gray);
    app->setPalette(pal);
    RECT desktop;
    const HWND hDesktop = GetDesktopWindow();
    GetWindowRect(hDesktop, &desktop);
    Keyboard* keyboard = new Keyboard;
    MainWindow* window = new MainWindow;

    window->setCentralWidget(keyboard);
    window->show();
    keyboard->showKeyboard(0,0);

    HWND winHandle=(HWND)window->winId();
        ShowWindow(winHandle, SW_HIDE);
        SetWindowLong(winHandle, GWL_EXSTYLE, GetWindowLong(winHandle, GWL_EXSTYLE)
            | WS_EX_NOACTIVATE | WS_EX_APPWINDOW);
    ShowWindow(winHandle, SW_SHOW);
    keyboard->setWindowTitle(" ");


    return app->exec();
}
