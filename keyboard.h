#ifndef KEYBOARD_H
#define KEYBOARD_H
#include <QGridLayout>
#include <QPushButton>

#include <QWidget>

#define AAA 1

class Keyboard : public QWidget
{
    Q_OBJECT

public:
    QPushButton *buttons [56] = {};
    explicit Keyboard(QWidget *parent = Q_NULLPTR);
    int offset=0;

public slots:
    void showKeyboard(int globalX, int globalY);
    void themes(QApplication &app, int border, QString &color);
    void hideKeyboard();
    bool keyboardVisible() const;

signals:
    void specialKeyClicked(int key);
    void keyClicked(const QString &text);

private slots:
    void buttonClicked(int key);

private:
    QGridLayout * test;
};

#endif
