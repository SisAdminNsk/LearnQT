
#include "sectorviewmodel.h"

SectorViewModel::SectorViewModel(QWidget *parent) : BaseFigureViewModel(parent)
{
    this->sectorModel = new SectorModel();
    this->Setup();
}

SectorViewModel::~SectorViewModel(){
    delete this->sectorModel;
    delete inputAlphaForm;
    delete inputRadiousForm;
}

void SectorViewModel::ClearInputForms(){
    this->inputAlphaForm->clear();
    this->inputRadiousForm->clear();
}

void SectorViewModel::SetImagePath(){
    this->imagePath = ":/resource/Images/sector.png";
}

void SectorViewModel::SetupInputForms(){

    inputAlphaForm = new QLineEdit(this);
    inputAlphaForm->setPlaceholderText("Введите значение для угла сектора:");
    inputAlphaForm->setValidator(validator);
    layout->addWidget(inputAlphaForm);

    inputRadiousForm = new QLineEdit(this);
    inputRadiousForm->setPlaceholderText("Введите значение для радиуса сектора:");
    inputRadiousForm->setValidator(validator);
    layout->addWidget(inputRadiousForm);
}

void SectorViewModel::ProvideCalculateLogicFromModel(){

    bool ok;
    auto inputRadious = inputRadiousForm->text();
    auto inputAlpha = inputAlphaForm->text();

    auto radious = inputRadious.toDouble(&ok);
    auto alpha = inputAlpha.toDouble(&ok);

    if(ok){
        this->sectorModel->alpha = alpha;
        this->sectorModel->radious = radious;
        ShowCalcResults(sectorModel, QString::fromStdString("Результат"), QString::fromStdString("Площадь сектора: "));
    }
}

