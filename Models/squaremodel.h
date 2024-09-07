
#ifndef SQUAREMODEL_H
#define SQUAREMODEL_H

#include "basefiguremodel.h"



class SquareModel : public BaseFigureModel
{
public:
    SquareModel();

    double sight = 0.0;

    virtual double calcSquare() override;
};

#endif // SQUAREMODEL_H
