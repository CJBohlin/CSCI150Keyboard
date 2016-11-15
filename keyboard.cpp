#include "keyboard.h"

#ifdef Q_OS_WIN
#define WINVER 0x0500
#include <iostream>
#include "Windows.h"
#include "WinUser.h"
#endif
#include <QGridLayout>
#include <QSignalMapper>
#include <QPushButton>
#include <QApplication>
#include <QToolButton>
#include "globals.h"

#define NEXT_ROW_MARKER 0

struct KeyboardLayoutEntry{
    int key;
    const char *label;
};

KeyboardLayoutEntry keyboardLayoutLower[] = {
    { Qt::Key_Escape, "Esc"},
    { Qt::Key_F1,"F1"},
    { Qt::Key_F2,"F2"},
    { Qt::Key_F3,"F3"},
    { Qt::Key_F4,"F4"},
    { Qt::Key_F5,"F5"},
    { Qt::Key_F6,"F6"},
    { Qt::Key_F7,"F7"},
    { Qt::Key_F8,"F8"},
    { Qt::Key_F9,"F9"},
    //{ Qt::Key_F1,"F10"},
    //{ Qt::Key_F1,"F11"},
    //{ Qt::Key_F1,"F12"},
    //{ Qt::Key_PowerOff,"Power"},
    { Qt::Key_Backspace, "<-" },
    { NEXT_ROW_MARKER, 0 },
    { Qt::Key_1, "1" },
    { Qt::Key_2, "2" },
    { Qt::Key_3, "3" },
    { Qt::Key_4, "4" },
    { Qt::Key_5, "5" },
    { Qt::Key_6, "6" },
    { Qt::Key_7, "7" },
    { Qt::Key_8, "8" },
    { Qt::Key_9, "9" },
    { Qt::Key_0, "0" },
    { Qt::Key_Tab, "Tab"},
    { NEXT_ROW_MARKER, 0 },
    { Qt::Key_Q, "q" },
    { Qt::Key_W, "w" },
    { Qt::Key_E, "e" },
    { Qt::Key_R, "r" },
    { Qt::Key_T, "t" },
    { Qt::Key_Y, "y" },
    { Qt::Key_U, "u" },
    { Qt::Key_I, "i" },
    { Qt::Key_O, "o" },
    { Qt::Key_P, "p" },
    { Qt::Key_Shift, "Shift" },
    { NEXT_ROW_MARKER, 0 },
    { Qt::Key_A, "a" },
    { Qt::Key_S, "s" },
    { Qt::Key_D, "d" },
    { Qt::Key_F, "f" },
    { Qt::Key_G, "g" },
    { Qt::Key_H, "h" },
    { Qt::Key_J, "j" },
    { Qt::Key_K, "k" },
    { Qt::Key_L, "l" },
    { Qt::Key_CapsLock, "Caps" },
    { NEXT_ROW_MARKER, 0 },
    { Qt::Key_Z, "z" },
    { Qt::Key_X, "x" },
    { Qt::Key_C, "c" },
    { Qt::Key_V, "v" },
    { Qt::Key_B, "b" },
    { Qt::Key_N, "n" },
    { Qt::Key_M, "m" },
    { Qt::Key_Enter, "Enter" },
    { Qt::Key_Space, "Space" }
};

const static int layoutSize = (sizeof(keyboardLayoutLower) / sizeof(KeyboardLayoutEntry));

static QString keyToCharacter(int key)
{
    for (int i = 0; i < layoutSize; ++i) {
        if (keyboardLayoutLower[i].key == key)
            return QString::fromLatin1(keyboardLayoutLower[i].label);
    }

    return QString();
}

Keyboard::Keyboard(QWidget *parent)
    : QWidget(parent)
{
    setWindowFlags(Qt::WindowDoesNotAcceptFocus | Qt::Tool | Qt::WindowStaysOnTopHint | Qt::BypassWindowManagerHint);

    QGridLayout *gridLayout = new QGridLayout(this);
    this->test = gridLayout;

    QSignalMapper *mapper = new QSignalMapper(this);
    connect(mapper, SIGNAL(mapped(int)), SLOT(buttonClicked(int)));
    int row = 0;
    int column = 0;
    for (int i = 0; i < layoutSize; ++i) {
        if (keyboardLayoutLower[i].key == NEXT_ROW_MARKER) {
            row++;
            column = 0;
            continue;
        }
        QPushButton *button = new QPushButton;
        this->buttons[i] = button;
        switch(g_theme){
        case 0:
            button->setFixedWidth(70);
            button->setText(QString::fromLatin1(keyboardLayoutLower[i].label));
            button->setStyleSheet("QPushButton:hover {background-color:red;border-style: outset;border-width: 2px;border-radius: 10px;border-color: beige; font: bold 18px;min-width: 3em;min-height:2em;padding: 6px;color:white;} QPushButton:!hover { background-color: grey;border-style: outset;border-width: 2px;border-radius: 10px;border-color: beige; font: bold 18px;min-width: 3em;min-height:2em;padding: 6px;color:white; }");
            mapper->setMapping(button, keyboardLayoutLower[i].key);
            break;
        case 1:
            button->setFixedWidth(70);
            button->setText(QString::fromLatin1(keyboardLayoutLower[i].label));
            button->setStyleSheet("QPushButton:hover {background-color: gray;border-style: outset;border-width: 2px;border-radius: 10px;border-color: beige; font: bold 18px;min-width: 3em;min-height:2em;padding: 6px;color:white;} QPushButton:!hover { background-color: black;border-style: outset;border-width: 2px;border-radius: 10px;border-color: beige; font: bold 18px;min-width: 3em;min-height:2em;padding: 6px;color:white;}");
            mapper->setMapping(button, keyboardLayoutLower[i].key);
            break;
        case 2:
            button->setFixedWidth(70);
            button->setText(QString::fromLatin1(keyboardLayoutLower[i].label));
            button->setStyleSheet("QPushButton:hover {background-color: gray;border-style: outset;border-width: 2px;border-radius: 10px;border-color: beige; font: bold 18px;min-width: 3em;min-height:2em;padding: 6px;color:white;} QPushButton:!hover { background-color: white;border-style: outset;border-width: 2px;border-radius: 10px;border-color: gray; font: bold 18px;min-width: 3em;min-height:2em;padding: 6px;color:gray;}");
            mapper->setMapping(button, keyboardLayoutLower[i].key);
            break;
        case 3:
            button->setFixedWidth(70);
            button->setText(QString::fromLatin1(keyboardLayoutLower[i].label));
            button->setStyleSheet("QPushButton:hover {background-color: black;border-style: outset;border-width: 2px;border-radius: 10px;border-color: gray; font: bold 18px;min-width: 3em;min-height:2em;padding: 6px;color:white;} QPushButton:!hover { background-color: black;border-style: outset;border-width: 2px;border-radius: 10px;border-color: gray; font: bold 18px;min-width: 3em;min-height:2em;padding: 6px;color:green;}");
            mapper->setMapping(button, keyboardLayoutLower[i].key);
            break;
        }
        connect(button, SIGNAL(clicked()), mapper, SLOT(map()));

        gridLayout->addWidget(button, row, column);
        column++;

    }
}


void Keyboard::showKeyboard(int globalX, int globalY)
{
    QWidget::move(globalX, globalY);
    QWidget::show();
}

void Keyboard::hideKeyboard()
{
    QWidget::hide();
}

bool Keyboard::keyboardVisible() const
{
    return QWidget::isVisible();
}

void Keyboard::themes(QApplication &app, int border, QString &color)
{
    QString borderString = QString::number(border);
    QPalette pal = app.palette();
    pal.setColor(QPalette::Window, Qt::lightGray);
    app.setPalette(pal);
    QString theme = "#myObject { border: "+borderString+"px solid " + color + "; }";
    app.setStyleSheet("#myObject { border: 5px solid red; }");

}
void Keyboard::buttonClicked(int key)
{
    #ifdef Q_OS_WIN
    INPUT vkey;
    vkey.type = INPUT_KEYBOARD;
    vkey.ki.wScan = 0; // hardware scan code for key
    vkey.ki.time = 0;
    vkey.ki.dwExtraInfo = 0;
    switch(key) {
    case Qt::Key_Enter: vkey.ki.wVk = VK_RETURN;
        break;
    case Qt::Key_Backspace: vkey.ki.wVk = VK_BACK;
        break;
    //case Qt::Key_Any : this->hideKeyboard();
    //    break;
    case Qt::Key_Shift : vkey.ki.wVk = VK_SHIFT;
        break;
    case Qt::Key_CapsLock : vkey.ki.wVk = VK_CAPITAL;
        break;
    case Qt::Key_Space : vkey.ki.wVk = VK_SPACE;
        break;
    case Qt::Key_Tab : vkey.ki.wVk = VK_TAB;
        break;
    case Qt::Key_Escape : vkey.ki.wVk = VK_ESCAPE;
        break;
    case Qt::Key_F1 : vkey.ki.wVk = VK_F1;
        break;
    case Qt::Key_F2 : vkey.ki.wVk = VK_F2;
        break;
    case Qt::Key_F3 : vkey.ki.wVk = VK_F3;
        break;
    case Qt::Key_F4 : vkey.ki.wVk = VK_F4;
        break;
    case Qt::Key_F5 : vkey.ki.wVk = VK_F5;
        break;
    case Qt::Key_F6 : vkey.ki.wVk = VK_F6;
        break;
    case Qt::Key_F7 : vkey.ki.wVk = VK_F7;
        break;
    case Qt::Key_F8 : vkey.ki.wVk = VK_F8;
        break;
    case Qt::Key_F9 : vkey.ki.wVk = VK_F9;
        break;

    default : vkey.ki.wVk = key; // virtual-key code
    }
    vkey.ki.dwFlags = 0; // 0 for key press
    SendInput(1, &vkey, sizeof(INPUT));
    if (key != Qt::Key_Shift) {
        vkey.ki.dwFlags = KEYEVENTF_KEYUP; // KEYEVENTF_KEYUP for key release
        SendInput(1, &vkey, sizeof(INPUT));
        if (GetKeyState(VK_SHIFT)){
            vkey.ki.wVk = VK_SHIFT;
            vkey.ki.dwFlags = KEYEVENTF_KEYUP;
            SendInput(1, &vkey, sizeof(INPUT));
        }
    }
    return;
    #endif
}
