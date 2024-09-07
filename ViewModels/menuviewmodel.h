#ifndef MENUVIEWMODEL_H
#define MENUVIEWMODEL_H

#include <QObject>
#include <QMainWindow>

class MenuViewModel : public QObject
{
    Q_OBJECT
private:
    QMainWindow *mainWindow = nullptr;

    QAction *authorsItemAction = nullptr;
    QAction *clearItemAction = nullptr;
    QAction *exitAction = nullptr;

    void setup();

public:
    explicit MenuViewModel(QMainWindow* mainWindow, QObject *parent = nullptr);

signals:
    void exitRequested();
    void showAuthorsRequested();
    void clearInputRequested();

private slots:
    void onShowAuthorsAction(); // Обработчик для меню "Авторы"
    void onClearInputAction(); // Обработчик для меню "Очистить"
    void onExitAction(); // Обработчик для меню "Выход"
};

#endif // MENUVIEWMODEL_H
