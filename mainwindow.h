
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStackedWidget>
#include "ViewModels/menuviewmodel.h"


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow

{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    MenuViewModel *menuViewModel;
    QStackedWidget *stackedWidget; // Для переключения между представлениями

    void connectWithMenuSignals();
    void setupViews();
    void addButtonsLayouts();
    void addViewModels();

private slots:
    void handleExitRequest();
    void handleShowAuthorsRequest();
    void handleClearInputRequest();

    void showSquare();
    void showRectangle();
    void showParallelogram();
    void showRhombus();
    void showTriangle();
    void showTrapezoid();
    void showCircle();
    void showSector();
};

#endif // MAINWINDOW_H
