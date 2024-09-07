
#ifndef SECTORMODEL_H
#define SECTORMODEL_H

#include "basefiguremodel.h"



class SectorModel : public BaseFigureModel
{
public:
    SectorModel();

    double alpha = 0.0;
    double radious = 0.0;

    virtual double calcSquare() override;
};

#endif // SECTORMODEL_H
