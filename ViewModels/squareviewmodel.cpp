
#include "squareviewmodel.h"
#include "Models/squaremodel.h"
#include <QMessageBox>
#include <QDoubleValidator>

SquareViewModel::SquareViewModel(QWidget *parent) : BaseFigureViewModel(parent)
{
    this->squareModel = new SquareModel();

    this->Setup();
}

SquareViewModel::~SquareViewModel(){
    delete this->squareModel;
    delete inputSquareSightField;
}

void SquareViewModel::ClearInputForms(){
    this->inputSquareSightField->clear();
}

void SquareViewModel::SetImagePath(){
    this->imagePath = ":/resource/Images/square.jpg";
}

void SquareViewModel::SetupInputForms(){

    inputSquareSightField = new QLineEdit(this);
    inputSquareSightField->setPlaceholderText("Введите значение для стороны квадрата:");
    inputSquareSightField->setValidator(validator);
    layout->addWidget(inputSquareSightField);
}

void SquareViewModel::ProvideCalculateLogicFromModel(){

    bool ok;
    auto inputText = inputSquareSightField->text();
    auto squareSide = inputText.toDouble(&ok);

    if(ok){
        this->squareModel->sight = squareSide;
        ShowCalcResults(squareModel, QString::fromStdString("Результат"),QString::fromStdString("Площадь квадрата: "));
    }
}
