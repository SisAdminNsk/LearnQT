
#include "trapezoidviewmodel.h"
#include <QMessageBox>

TrapezoidViewModel::TrapezoidViewModel(QWidget *parent ) : BaseFigureViewModel(parent)
{
    this->trapezoidModel = new TrapezoidModel();

    this->Setup();
}

TrapezoidViewModel::~TrapezoidViewModel(){
    delete this->trapezoidModel;
    delete inputBaseAField;
    delete inputBaseBField;
    delete inputHeightField;
}

void TrapezoidViewModel::ClearInputForms(){
    this->inputBaseAField->clear();
    this->inputBaseBField->clear();
    this->inputHeightField->clear();
}

void TrapezoidViewModel::SetImagePath(){
    this->imagePath = ":/resource/Images/trapezoid.png";
}

void TrapezoidViewModel::SetupInputForms(){

    inputBaseAField = new QLineEdit(this);
    inputBaseAField->setPlaceholderText("Введите значение для основания A трапеции:");
    inputBaseAField->setValidator(validator);
    layout->addWidget(inputBaseAField);

    inputBaseBField = new QLineEdit(this);
    inputBaseBField->setPlaceholderText("Введите значение для основания B трапеции:");
    inputBaseBField->setValidator(validator);
    layout->addWidget(inputBaseBField);

    inputHeightField = new QLineEdit(this);
    inputHeightField->setPlaceholderText("Введите значение для высоты трапеции:");
    inputHeightField->setValidator(validator);
    layout->addWidget(inputHeightField);

}

void TrapezoidViewModel::ProvideCalculateLogicFromModel(){

    bool ok;
    auto inputBaseA = inputBaseAField->text();
    auto inputBaseB = inputBaseBField->text();
    auto inputHeight = inputHeightField->text();

    auto baseA = inputBaseA.toDouble(&ok);
    auto baseB = inputBaseB.toDouble(&ok);
    auto height = inputHeight.toDouble(&ok);

    if(ok){
        this->trapezoidModel->baseA = baseA;
        this->trapezoidModel->baseB = baseB;
        this->trapezoidModel->height = height;

        ShowCalcResults(trapezoidModel,QString::fromStdString("Результат"),QString::fromStdString("Площадь трапеции: "));
    }
}

