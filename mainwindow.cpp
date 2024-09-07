
#include <QMessageBox>
#include <QVBoxLayout>
#include <QPushButton>

#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "ViewModels/squareviewmodel.h"
#include "ViewModels/rectviewmodel.h"
#include "ViewModels/parallelogrammviewmodel.h"
#include "ViewModels/rhombusviewmodel.h"
#include "ViewModels/triangleviewmodel.h"
#include "ViewModels/trapezoidviewmodel.h"
#include "ViewModels/circleviewmodel.h"
#include "ViewModels/sectorviewmodel.h"


MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , stackedWidget(new QStackedWidget(this))
{
    ui->setupUi(this);
    this->menuViewModel = new MenuViewModel(this);

    this->connectWithMenuSignals();
    this->setupViews();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::addButtonsLayouts(){

    auto buttonWidget = new QWidget(this);
    auto buttonLayout = new QHBoxLayout(buttonWidget);

    auto squareBtn = new QPushButton("Площадь квадрата", this);
    auto rectBtn = new QPushButton("Площадь прямоугольника", this);
    auto parallelogramBtn = new QPushButton("Площадь параллелограмма", this);
    auto rhombusBtn = new QPushButton("Площадь ромба",this);

    buttonLayout->addWidget(squareBtn);
    buttonLayout->addWidget(rectBtn);
    buttonLayout->addWidget(parallelogramBtn);
    buttonLayout->addWidget(rhombusBtn);

    connect(squareBtn, &QPushButton::clicked, this, &MainWindow::showSquare);
    connect(rectBtn, &QPushButton::clicked, this, &MainWindow::showRectangle);
    connect(parallelogramBtn, &QPushButton::clicked, this, &MainWindow::showParallelogram);
    connect(rhombusBtn, &QPushButton::clicked, this, &MainWindow::showRhombus);

    auto buttonWidget1 = new QWidget(this);
    auto buttonLayout1 = new QHBoxLayout(buttonWidget1);

    auto triangleBtn = new QPushButton("Площадь треугольника", this);
    auto trapezoidBtn = new QPushButton("Площадь трапеции", this);
    auto circleBtn = new QPushButton("Площадь круга", this);
    auto sectorBtn = new QPushButton("Площадь сектора", this);

    buttonLayout1->addWidget(triangleBtn);
    buttonLayout1->addWidget(trapezoidBtn);
    buttonLayout1->addWidget(circleBtn);
    buttonLayout1->addWidget(sectorBtn);

    connect(triangleBtn, &QPushButton::clicked, this, &MainWindow::showTriangle);
    connect(trapezoidBtn, &QPushButton::clicked, this, &MainWindow::showTrapezoid);
    connect(circleBtn, &QPushButton::clicked, this, &MainWindow::showCircle);
    connect(sectorBtn, &QPushButton::clicked, this, &MainWindow::showSector);

    // Размещаем панели кнопок в главном окне
    auto mainLayout = new QVBoxLayout();
    mainLayout->addWidget(buttonWidget);
    mainLayout->addWidget(buttonWidget1);
    mainLayout->addWidget(stackedWidget);

    auto centralWidget = new QWidget(this);
    centralWidget->setLayout(mainLayout);
    setCentralWidget(centralWidget);
}

void MainWindow::addViewModels(){

    stackedWidget->addWidget(new SquareViewModel(this));
    stackedWidget->addWidget(new RectViewModel(this));
    stackedWidget->addWidget(new ParallelogrammViewModel(this));
    stackedWidget->addWidget(new RhombusViewModel(this));
    stackedWidget->addWidget(new TriangleViewModel(this));
    stackedWidget->addWidget(new TrapezoidViewModel(this));
    stackedWidget->addWidget(new CircleViewModel(this));
    stackedWidget->addWidget(new SectorViewModel(this));
}

void MainWindow::setupViews(){

    this->addButtonsLayouts();
    this->addViewModels();
}

void MainWindow::showSquare(){
    stackedWidget->setCurrentIndex(0);
}

void MainWindow::showRectangle(){
    stackedWidget->setCurrentIndex(1);
}

void MainWindow::showParallelogram(){
    stackedWidget->setCurrentIndex(2);
}

void MainWindow::showRhombus(){
    stackedWidget->setCurrentIndex(3);
}

void MainWindow::showTriangle(){
    stackedWidget->setCurrentIndex(4);
}

void MainWindow::showTrapezoid(){
    stackedWidget->setCurrentIndex(5);
}

void MainWindow::showCircle(){
    stackedWidget->setCurrentIndex(6);
}

void MainWindow::showSector(){
    stackedWidget->setCurrentIndex(7);
}

void MainWindow::connectWithMenuSignals(){
    connect(menuViewModel, &MenuViewModel::exitRequested, this, &MainWindow::handleExitRequest);
    connect(menuViewModel, &MenuViewModel::clearInputRequested, this, &MainWindow::handleClearInputRequest);
    connect(menuViewModel, &MenuViewModel::showAuthorsRequested, this, &MainWindow::handleShowAuthorsRequest);
}

void MainWindow::handleExitRequest(){
    this->close();
}

void MainWindow::handleShowAuthorsRequest(){
    QMessageBox::information(this, "Авторы", "Раков Артем ИП-211.");
}

void MainWindow::handleClearInputRequest(){

    for(size_t i = 0; i < stackedWidget->count();i++){

        auto widget = stackedWidget->widget(i);
        auto figureViewModel = dynamic_cast<BaseFigureViewModel*>(widget);
        figureViewModel->ClearInputForms();
    }

    QMessageBox::information(this, "Формы для ввода", "Все формы очищены.");
}
