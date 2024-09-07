
#include <QMessageBox>
#include "basefigureviewmodel.h"

BaseFigureViewModel::BaseFigureViewModel(QWidget *parent)
    : QWidget{parent}
{
    this->layout = new QVBoxLayout(this);
    this->pixmap = new QPixmap();
    this->image = new QLabel(this);
}

void BaseFigureViewModel::LoadImage(){
    this->pixmap->load(imagePath);
}

void BaseFigureViewModel::SetImageSize(){
    this->imageWidthPx = 400;
    this->imageHeightPx = 400;
}

void BaseFigureViewModel::SetupImage(){

    this->image->setAlignment(Qt::AlignCenter);
    this->image->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    this->image->setPixmap(this->pixmap->scaled(this->imageWidthPx, this->imageHeightPx, Qt::KeepAspectRatio));

    this->layout->addWidget(this->image); // добавляем в разметку изображение
}

void BaseFigureViewModel::SetupValidator(){

    this->validator = new QDoubleValidator();
    this->validator->setNotation(QDoubleValidator::StandardNotation);
    this->validator->setRange(0.0, 10000.0);
}

void BaseFigureViewModel::Setup(){

    SetImagePath();
    LoadImage();
    SetImageSize();
    SetupImage();
    SetupValidator();
    SetupInputForms();
    SetupCalculateButton();
}

BaseFigureViewModel::~BaseFigureViewModel(){
    delete this->validator;
    delete this->pixmap;
    delete this->image;
    delete this->layout;
}

void BaseFigureViewModel::ShowCalcResults(
    BaseFigureModel* figure,
    const QString& messageHeader,
    const QString& messageBody)
{
    double square = figure->calcSquare();
    auto squareString = QString::number(square, 'f', 2);
    QMessageBox::information(this, messageHeader, messageBody + squareString);
}

void BaseFigureViewModel::SetupCalculateButton(){

    auto *calculateButton = new QPushButton("Посчитать площадь", this);
    this->layout->addWidget(calculateButton);

    connect(calculateButton, &QPushButton::clicked, this, &BaseFigureViewModel::ProvideCalculateLogicFromModel);

}
