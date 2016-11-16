#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "keyboard.h"
#include <QPushButton>
#include <QDebug>
class QAction;
class QActionGroup;
class QLabel;
class QMenu;

class MainWindow : public QMainWindow
{
    Q_OBJECT
    QWidget *centralWidget;
    QGridLayout* gridLayout;
public:
    MainWindow();
    Keyboard keyboard;
    QPushButton *buttons[56] = {};
    void getbuttons(const Keyboard &a) {
        for (int i=0; i<56;i++){
            this->buttons[i] = a.buttons[i];
        }
    }
protected:
#ifndef QT_NO_CONTEXTMENU
    void contextMenuEvent(QContextMenuEvent *event) Q_DECL_OVERRIDE;
#endif // QT_NO_CONTEXTMENU

private slots:
    void pickRandomTheme();
    void pickDefaultTheme();
    void pickBlackTheme();
    void pickWhiteTheme();
    void pickHackerTheme();
private:
    void createActions();
    void createMenus();
    QGridLayout * test;

    QMenu *fileMenu;
    QMenu *editMenu;
    QMenu *themeMenu;
    QMenu *formatMenu;
    QMenu *helpMenu;
    QActionGroup *alignmentGroup;
    QAction *randomTheme;
    QAction *defaultTheme;
    QAction *blackTheme;
    QAction *whiteTheme;
    QAction *hackerTheme;
    QLabel *infoLabel;
};

#endif
