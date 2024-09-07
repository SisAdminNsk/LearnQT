
#ifndef TRIANGLEMODEL_H
#define TRIANGLEMODEL_H

#include "basefiguremodel.h"



class TriangleModel : public BaseFigureModel
{
public:
    TriangleModel();

    double base = 0.0;
    double height = 0.0;

    virtual double calcSquare() override;
};

#endif // TRIANGLEMODEL_H
