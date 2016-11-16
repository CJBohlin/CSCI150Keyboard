#include <QtWidgets>
#include "mainwindow.h"
#include <QGridLayout>
#include <iostream>
#include "Windows.h"
#include "WinUser.h"
#include <QGridLayout>
#include <QSignalMapper>
#include <QPushButton>
#include <QApplication>
#include <QToolButton>
#include "keyboard.h"
#include <QDebug>
#include "globals.h"

MainWindow::MainWindow()
{

    setWindowFlags(Qt::WindowDoesNotAcceptFocus | Qt::Tool | Qt::WindowStaysOnTopHint | Qt::BypassWindowManagerHint);
    QWidget *widget = new QWidget;

    this->setCentralWidget( widget );
    gridLayout = new QGridLayout( widget );

    QWidget *topFiller = new QWidget;
    topFiller->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);


    QWidget *bottomFiller = new QWidget;
    bottomFiller->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    createActions();
    createMenus();

    setWindowTitle(tr("Virtual Keyboard"));
}

#ifndef QT_NO_CONTEXTMENU
void MainWindow::contextMenuEvent(QContextMenuEvent *event)
{
    QMenu menu(this);
    menu.exec(event->globalPos());

}
#endif // QT_NO_CONTEXTMENU

void MainWindow::pickRandomTheme()
{
    int temp = g_theme;
    while (temp==g_theme){
        g_theme = qrand() % 4;
    }

    Keyboard* keyboard = new Keyboard;
    setCentralWidget(keyboard);
    switch(g_theme){
    case(0):
        this->setStyleSheet("background-color: gray;");
        break;
    case(1):
        this->setStyleSheet("background-color: black;");
        break;
    case(2):
        this->setStyleSheet("background-color: white;");
        break;
    case(3):
        this->setStyleSheet("background-color: black;");
        break;
    }
}

void MainWindow::pickDefaultTheme()
{
    g_theme = 0;
    Keyboard* keyboard = new Keyboard;
    setCentralWidget(keyboard);
    this->setStyleSheet("background-color: gray;");
}

void MainWindow::pickBlackTheme()
{
    g_theme = 1;
    Keyboard* keyboard = new Keyboard;
    setCentralWidget(keyboard);
    this->setStyleSheet("background-color: black;");
}

void MainWindow::pickWhiteTheme()
{
    g_theme = 2;
    Keyboard* keyboard = new Keyboard;
    setCentralWidget(keyboard);
    this->setStyleSheet("background-color: white;");
}

void MainWindow::pickHackerTheme()
{
    g_theme = 3;
    Keyboard* keyboard = new Keyboard;
    setCentralWidget(keyboard);
    this->setStyleSheet("background-color: black;");
}

void MainWindow::createActions()
{
    randomTheme = new QAction(tr("&Random"), this);
    randomTheme->setShortcuts(QKeySequence::New);
    randomTheme->setStatusTip(tr("Change to random theme"));
    connect(randomTheme, &QAction::triggered, this, &MainWindow::pickRandomTheme);

    defaultTheme = new QAction(tr("&Defualt"), this);
    defaultTheme->setStatusTip(tr("Change to random theme"));
    connect(defaultTheme, &QAction::triggered, this, &MainWindow::pickDefaultTheme);

    blackTheme = new QAction(tr("&Black"), this);
    blackTheme->setStatusTip(tr("Change to random theme"));
    connect(blackTheme, &QAction::triggered, this, &MainWindow::pickBlackTheme);

    whiteTheme = new QAction(tr("&White"), this);
    whiteTheme->setStatusTip(tr("Change to random theme"));
    connect(whiteTheme, &QAction::triggered, this, &MainWindow::pickWhiteTheme);

    hackerTheme = new QAction(tr("&Hacker"), this);
    hackerTheme->setStatusTip(tr("Change to random theme"));
    connect(hackerTheme, &QAction::triggered, this, &MainWindow::pickHackerTheme);

}

void MainWindow::createMenus()
{
    menuBar()->setStyleSheet("background-color: gray;");
    themeMenu = menuBar()->addMenu(tr("&Themes"));
    themeMenu->addAction(randomTheme);
    themeMenu->addAction(defaultTheme);
    themeMenu->addAction(blackTheme);
    themeMenu->addAction(whiteTheme);
    themeMenu->addAction(hackerTheme);
}
