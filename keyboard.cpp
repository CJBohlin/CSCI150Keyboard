#include "keyboard.h"

#ifdef Q_OS_WIN
#define WINVER 0x0500
#include "Windows.h"
#include "WinUser.h"
#endif

#include <QGridLayout>
#include <QSignalMapper>
#include <QPushButton>
#include <string>

#define NEXT_ROW_MARKER 0

struct KeyboardLayoutEntry{
    int key;
    const char *label;
};


KeyboardLayoutEntry keyboardLayout[] = {
    { Qt::Key_Escape, "Esc" },
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
    { Qt::Key_Backspace, "<-" },
    { NEXT_ROW_MARKER, 0 },
    { Qt::Key_Tab, "Tab" },
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
    { NEXT_ROW_MARKER, 0 },
    { Qt::Key_CapsLock, "Caps" },
    { Qt::Key_A, "a" },
    { Qt::Key_S, "s" },
    { Qt::Key_D, "d" },
    { Qt::Key_F, "f" },
    { Qt::Key_G, "g" },
    { Qt::Key_H, "h" },
    { Qt::Key_J, "j" },
    { Qt::Key_K, "k" },
    { Qt::Key_L, "l" },
    { Qt::Key_Enter, "Enter" },
    { Qt::Key_Up, "Up" },
    { NEXT_ROW_MARKER, 0 },
    { Qt::Key_Shift, "Shift" },
    { Qt::Key_Z, "z" },
    { Qt::Key_X, "x" },
    { Qt::Key_C, "c" },
    { Qt::Key_V, "v" },
    { Qt::Key_B, "b" },
    { Qt::Key_N, "n" },
    { Qt::Key_M, "m" },
    { Qt::SHIFT, "Shift" },
    { Qt::Key_Space, "Space" },
    { Qt::Key_Left, "Left"},
    { Qt::Key_Down, "Down" },
    { Qt::Key_Right, "Right" },
    { NEXT_ROW_MARKER, 0 },
    { Qt::Window,"WINKEY"},
    { Qt::Key_hyphen, "-" },
    { Qt::Key_Plus, "+"},
    { Qt::Key_Comma, ","},
    { Qt::Key_Slash, "/"},
    { Qt::Key_Semicolon,";"},
    { Qt::Key_Apostrophe, "'"},
    { Qt::Key_Period, "."}
};

const static int layoutSize = (sizeof(keyboardLayout) / sizeof(KeyboardLayoutEntry));

static QString keyToCharacter(int key)
{
    for (int i = 0; i < layoutSize; ++i) {
        if (keyboardLayout[i].key == key)
            return QString::fromLatin1(keyboardLayout[i].label);
    }

    return QString();
}

Keyboard::Keyboard(QWidget *parent)
    : QWidget(parent)
{
    setWindowFlags(Qt::WindowDoesNotAcceptFocus | Qt::Tool | Qt::WindowStaysOnTopHint | Qt::BypassWindowManagerHint);

    QGridLayout *gridLayout = new QGridLayout(this);

    QSignalMapper *mapper = new QSignalMapper(this);
    connect(mapper, SIGNAL(mapped(int)), SLOT(buttonClicked(int)));

    int row = 0;
    int column = 0;

    for (int i = 0; i < layoutSize; ++i) {
        if (keyboardLayout[i].key == NEXT_ROW_MARKER) {
            row++;
            column = 0;
            continue;
        }

        QPushButton *button = new QPushButton;
        button->setFixedWidth(70);
        button->setText(QString::fromLatin1(keyboardLayout[i].label));
        button->setStyleSheet("background-color: black; color:white;border-width: 4px;");
        mapper->setMapping(button, keyboardLayout[i].key);
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

void Keyboard::buttonClicked(int key)
{
    #ifdef Q_OS_WIN
    INPUT vkey;
    vkey.type = INPUT_KEYBOARD;
    vkey.ki.wScan = 0; // hardware scan code for key
    vkey.ki.time = 0;
    vkey.ki.dwExtraInfo = 0;

    switch(key) {
    case Qt::Key_Escape: vkey.ki.wVk = VK_ESCAPE;
        break;
    case Qt::Key_Comma: vkey.ki.wVk = 0xBC;
        break;
    case Qt::Key_Exclam: vkey.ki.wVk = 0xBC;
        break;
    case Qt::Key_Up: vkey.ki.wVk = VK_UP;
        break;
    case Qt::Key_Down: vkey.ki.wVk = VK_DOWN;
        break;
    case Qt::Key_Left: vkey.ki.wVk = VK_LEFT;
        break;
    case Qt::Key_Right: vkey.ki.wVk = VK_RIGHT;
        break;
    case Qt::Key_Enter: vkey.ki.wVk = VK_RETURN;
        break;
    case Qt::Key_Backspace: vkey.ki.wVk = VK_BACK;
        break;
    case Qt::Key_Space : vkey.ki.wVk = VK_SPACE;
        break;
    case Qt::Key_Shift : vkey.ki.wVk = VK_SHIFT;
        break;
    case Qt::Key_hyphen : vkey.ki.wVk = 0xBD;
        break;
    case Qt::Key_Slash : vkey.ki.wVk = 0xDC;
        break;
    case Qt::Key_Semicolon : vkey.ki.wVk = VK_OEM_1;
        break;
    case Qt::Key_Apostrophe : vkey.ki.wVk = 0xDE;
        break;
    case Qt::Key_Period : vkey.ki.wVk = 0xBE ;
        break;
    case Qt::Key_Plus: vkey.ki.wVk = VK_OEM_PLUS;
        break;
    case Qt::Window: vkey.ki.wVk = VK_RWIN;
        break;
    case Qt::Key_CapsLock: vkey.ki.wVk = 0x14;
        break;
    case 0 : this->hideKeyboard();
        break;
    default : vkey.ki.wVk = key; // virtual-key code
    }



    if (key == Qt::Key_Shift && GetKeyState(VK_SHIFT)) vkey.ki.dwFlags = KEYEVENTF_KEYUP;
    else vkey.ki.dwFlags = 0; // 0 for key press
    SendInput(1, &vkey, sizeof(INPUT));
    if ((key != Qt::Key_Shift)) {
        vkey.ki.dwFlags = KEYEVENTF_KEYUP; // KEYEVENTF_KEYUP for key release
        SendInput(1, &vkey, sizeof(INPUT));
        if (GetKeyState(VK_SHIFT)) {
            vkey.ki.wVk = VK_SHIFT;
            vkey.ki.dwFlags = KEYEVENTF_KEYUP; // KEYEVENTF_KEYUP for key release
            SendInput(1, &vkey, sizeof(INPUT));
        }
    }
    return;
    #endif
}
//added symbols like ; , . ' and WINKEY
