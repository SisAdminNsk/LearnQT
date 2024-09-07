
#include "circleviewmodel.h"

CircleViewModel::CircleViewModel(QWidget *parent) : BaseFigureViewModel(parent)
{
    this->circleModel = new CircleModel();
    this->Setup();
}

CircleViewModel::~CircleViewModel(){
    delete this->circleModel;
    delete this->inputCircleRadiousForm;
}

void CircleViewModel::ClearInputForms(){
    this->inputCircleRadiousForm->clear();
}

void CircleViewModel::SetImagePath(){
    this->imagePath = ":/resource/Images/circle.png";
}

void CircleViewModel::SetupInputForms(){

    inputCircleRadiousForm = new QLineEdit(this);
    inputCircleRadiousForm->setPlaceholderText("Введите значение радиуса круга:");
    inputCircleRadiousForm->setValidator(validator);

    layout->addWidget(inputCircleRadiousForm);
}

void CircleViewModel::ProvideCalculateLogicFromModel(){

    bool ok;

    auto inputRadious = inputCircleRadiousForm->text();
    auto radious = inputRadious.toDouble(&ok);

    if(ok){
        this->circleModel->radious = radious;
        ShowCalcResults(circleModel, QString::fromStdString("Результат"), QString::fromStdString("Площадь круга: "));
    }
}


