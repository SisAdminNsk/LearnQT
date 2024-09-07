
#ifndef SECTORVIEWMODEL_H
#define SECTORVIEWMODEL_H

#include "basefigureviewmodel.h"
#include "Models/sectormodel.h"
#include <QLineEdit>

class SectorViewModel : public BaseFigureViewModel
{
public:
    SectorViewModel(QWidget *parent = nullptr);
    ~SectorViewModel();
    virtual void ClearInputForms() override;
protected:
    virtual void SetImagePath() override;
    virtual void SetupInputForms() override;

protected slots:
    virtual void ProvideCalculateLogicFromModel() override;

private:
    QLineEdit* inputRadiousForm = nullptr;
    QLineEdit* inputAlphaForm = nullptr;
    SectorModel* sectorModel = nullptr;
};

#endif // SECTORVIEWMODEL_H
