
#ifndef RHOMBUSMODEL_H
#define RHOMBUSMODEL_H

#include "basefiguremodel.h"

class RhombusModel : public BaseFigureModel
{
public:
    RhombusModel();

    double diagonalA = 0.0;
    double diagonalB = 0.0;

    virtual double calcSquare() override;
};

#endif // RHOMBUSMODEL_H
