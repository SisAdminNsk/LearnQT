
#ifndef TRAPEZOIDVIEWMODEL_H
#define TRAPEZOIDVIEWMODEL_H

#include "basefigureviewmodel.h"
#include "Models/trapezoidmodel.h"
#include <QLineEdit>

class TrapezoidViewModel : public BaseFigureViewModel
{
public:
    TrapezoidViewModel(QWidget *parent = nullptr);
    ~TrapezoidViewModel();
     virtual void ClearInputForms() override;
protected:
    virtual void SetImagePath() override;
    virtual void SetupInputForms() override;

protected slots:
    virtual void ProvideCalculateLogicFromModel() override;

private:
    QLineEdit* inputBaseAField = nullptr;
    QLineEdit* inputBaseBField = nullptr;
    QLineEdit* inputHeightField = nullptr;

    TrapezoidModel* trapezoidModel = nullptr;
};

#endif // TRAPEZOIDVIEWMODEL_H
