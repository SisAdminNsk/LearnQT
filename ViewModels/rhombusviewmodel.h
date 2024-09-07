
#ifndef RHOMBUSVIEWMODEL_H
#define RHOMBUSVIEWMODEL_H

#include "basefigureviewmodel.h"
#include "Models/rhombusmodel.h"
#include <QLineEdit>

class RhombusViewModel : public BaseFigureViewModel
{
public:
    RhombusViewModel(QWidget *parent = nullptr);
    ~RhombusViewModel();
    virtual void ClearInputForms() override;
protected:
    virtual void SetImagePath() override;
    virtual void SetupInputForms() override;

protected slots:
    virtual void ProvideCalculateLogicFromModel() override;

private:
    QLineEdit* inputDiagonalAField = nullptr;
    QLineEdit* inputDiagonalBField = nullptr;
    RhombusModel* rhombusModel = nullptr;
};

#endif // RHOMBUSVIEWMODEL_H
