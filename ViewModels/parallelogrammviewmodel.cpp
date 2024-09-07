
#include "parallelogrammviewmodel.h"
#include <QMessageBox>

ParallelogrammViewModel::ParallelogrammViewModel(QWidget *parent) : BaseFigureViewModel(parent)
{
    this->parallelogramModel = new ParallelogramModel();
    this->Setup();
}

ParallelogrammViewModel::~ParallelogrammViewModel(){

    delete this->parallelogramModel;
    delete this->inputParallelogramBase;
    delete this->inputParallelogramHeight;
}

void ParallelogrammViewModel::ClearInputForms(){
    this->inputParallelogramBase->clear();
    this->inputParallelogramHeight->clear();
}

void ParallelogrammViewModel::SetImagePath(){
    this->imagePath = ":/resource/Images/parallelogram.png";
}

void ParallelogrammViewModel::SetupInputForms(){
    inputParallelogramBase = new QLineEdit(this);
    inputParallelogramHeight = new QLineEdit(this);

    inputParallelogramBase->setPlaceholderText("Введите значение для основания:");
    inputParallelogramHeight->setPlaceholderText("Введите значение для высоты:");

    inputParallelogramBase->setValidator(validator);
    inputParallelogramHeight->setValidator(validator);

    layout->addWidget(inputParallelogramBase);
    layout->addWidget(inputParallelogramHeight);
}

void ParallelogrammViewModel::ProvideCalculateLogicFromModel(){

    bool ok;
    auto inputTextBase = inputParallelogramBase->text();
    auto inputTextHeight = inputParallelogramHeight->text();

    auto base = inputTextBase.toDouble(&ok);
    auto height = inputTextHeight.toDouble(&ok);

    if(ok){

        this->parallelogramModel->base = base;
        this->parallelogramModel->height = height;

        ShowCalcResults(parallelogramModel,QString::fromStdString("Результат"),QString::fromStdString("Площадь параллелограмма: "));
    }
}
