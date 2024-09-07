
#include "rhombusviewmodel.h"
#include <QMessageBox>

RhombusViewModel::RhombusViewModel(QWidget *parent) : BaseFigureViewModel(parent)
{
    this->rhombusModel = new RhombusModel();
    this->Setup();
}

RhombusViewModel::~RhombusViewModel(){
    delete this->rhombusModel;
    delete inputDiagonalAField;
    delete inputDiagonalBField;
}

void RhombusViewModel::ClearInputForms(){
    this->inputDiagonalAField->clear();
    this->inputDiagonalBField->clear();
}

void RhombusViewModel::SetImagePath(){
    this->imagePath = ":/resource/Images/rhombus.png";
}

void RhombusViewModel::SetupInputForms(){

    this->inputDiagonalAField = new QLineEdit(this);
    this->inputDiagonalBField = new QLineEdit(this);

    inputDiagonalAField->setPlaceholderText("Введите значение для диагонали A ромба:");
    inputDiagonalAField->setValidator(validator);

    inputDiagonalBField->setPlaceholderText("Введите значение для диагонали B ромба:");
    inputDiagonalBField->setValidator(validator);

    layout->addWidget(inputDiagonalAField);
    layout->addWidget(inputDiagonalBField);
}

void RhombusViewModel::ProvideCalculateLogicFromModel(){

    bool ok;
    auto inputDiagonalAText = inputDiagonalAField->text();
    auto inputDiagonalBText = inputDiagonalBField->text();

    auto rhombusADiagonal = inputDiagonalAText.toDouble(&ok);
    auto rhombusBDiagonal = inputDiagonalBText.toDouble(&ok);

    if(ok){

        this->rhombusModel->diagonalA = rhombusADiagonal;
        this->rhombusModel->diagonalB = rhombusBDiagonal;

        ShowCalcResults(rhombusModel, QString::fromStdString("Результат"),QString::fromStdString("Площадь ромба: "));
    }
}
