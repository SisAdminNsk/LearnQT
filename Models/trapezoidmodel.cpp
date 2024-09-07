
#include "trapezoidmodel.h"

TrapezoidModel::TrapezoidModel()
{

}

double TrapezoidModel::calcSquare(){

    return (this->baseA + this->baseB) * (this->height / 2);
}

