
#ifndef TRAPEZOIDMODEL_H
#define TRAPEZOIDMODEL_H

#include "basefiguremodel.h"



class TrapezoidModel : public BaseFigureModel
{
public:
    TrapezoidModel();

    double baseA = 0.0;
    double baseB = 0.0;
    double height = 0.0;

    virtual double calcSquare() override;
};

#endif // TRAPEZOIDMODEL_H
