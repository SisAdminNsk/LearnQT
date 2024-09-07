
#ifndef CIRCLEMODEL_H
#define CIRCLEMODEL_H

#include "basefiguremodel.h"



class CircleModel : public BaseFigureModel
{
public:
    CircleModel();

    double radious = 0.0;

    virtual double calcSquare() override;
};

#endif // CIRCLEMODEL_H
