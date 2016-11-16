/********************************************************************************
** Form generated from reading UI file 'keyboard.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_KEYBOARD_H
#define UI_KEYBOARD_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Keyboard
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *Keyboard)
    {
        if (Keyboard->objectName().isEmpty())
            Keyboard->setObjectName(QStringLiteral("Keyboard"));
        Keyboard->resize(400, 300);
        menuBar = new QMenuBar(Keyboard);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        Keyboard->setMenuBar(menuBar);
        mainToolBar = new QToolBar(Keyboard);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        Keyboard->addToolBar(mainToolBar);
        centralWidget = new QWidget(Keyboard);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        Keyboard->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(Keyboard);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        Keyboard->setStatusBar(statusBar);

        retranslateUi(Keyboard);

        QMetaObject::connectSlotsByName(Keyboard);
    } // setupUi

    void retranslateUi(QMainWindow *Keyboard)
    {
        Keyboard->setWindowTitle(QApplication::translate("Keyboard", "Keyboard", 0));
    } // retranslateUi

};

namespace Ui {
    class Keyboard: public Ui_Keyboard {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_KEYBOARD_H
