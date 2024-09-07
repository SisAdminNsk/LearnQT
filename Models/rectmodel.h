
#ifndef RECTMODEL_H
#define RECTMODEL_H

#include "basefiguremodel.h"



class RectModel : public BaseFigureModel
{
public:
    RectModel();

    double sightA = 0.0;
    double sightB = 0.0;

    virtual double calcSquare() override;
};

#endif // RECTMODEL_H
