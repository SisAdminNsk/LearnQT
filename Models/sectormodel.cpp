
#include "sectormodel.h"

SectorModel::SectorModel()
{

}

double SectorModel::calcSquare(){

    return 3.141592653589793 * (this->radious * this->radious) * (this->alpha / 360);
}
