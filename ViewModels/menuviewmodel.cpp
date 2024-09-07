
#include <QMenuBar>
#include "menuviewmodel.h"

MenuViewModel::MenuViewModel(QMainWindow* mainWindow, QObject *parent)
    : QObject{parent}
{
    this->mainWindow = mainWindow;
    setup();
}

void MenuViewModel::setup(){

    this->authorsItemAction = new QAction("Авторы", this);
    this->clearItemAction = new QAction("Очистить", this);
    this->exitAction = new QAction("Выход", this);

    auto menu = this->mainWindow->menuBar()->addMenu("Меню"); // Создаем меню

    menu->addAction(authorsItemAction);
    menu->addAction(clearItemAction);
    menu->addAction(exitAction);

    // Подключаем обработчики сигналов
    connect(authorsItemAction, &QAction::triggered, this, &MenuViewModel::onShowAuthorsAction);
    connect(clearItemAction, &QAction::triggered, this, &MenuViewModel::onClearInputAction);
    connect(exitAction, &QAction::triggered, this, &MenuViewModel::onExitAction);
}

void MenuViewModel::onShowAuthorsAction(){
    emit showAuthorsRequested();
}

void MenuViewModel::onClearInputAction(){
    emit clearInputRequested();
}

void MenuViewModel::onExitAction(){
    emit exitRequested();
}
