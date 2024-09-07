
#ifndef PARALLELOGRAMMODEL_H
#define PARALLELOGRAMMODEL_H


#include "Models/basefiguremodel.h"

class ParallelogramModel : public BaseFigureModel
{
public:
    ParallelogramModel();

    virtual double calcSquare() override;

    double base = 0.0;
    double height = 0.0;

};

#endif // PARALLELOGRAMMODEL_H
