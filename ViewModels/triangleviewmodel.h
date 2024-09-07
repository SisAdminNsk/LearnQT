
#ifndef TRIANGLEVIEWMODEL_H
#define TRIANGLEVIEWMODEL_H

#include "basefigureviewmodel.h"
#include "Models/trianglemodel.h"
#include <QLineEdit>


class TriangleViewModel : public BaseFigureViewModel
{
public:
    TriangleViewModel(QWidget *parent = nullptr);
    ~TriangleViewModel();
    virtual void ClearInputForms() override;
protected:
    virtual void SetImagePath() override;
    virtual void SetupInputForms() override;

protected slots:
    virtual void ProvideCalculateLogicFromModel() override;

private:
    QLineEdit* inputTriangleBaseField = nullptr;
    QLineEdit* inputTriangleHeightField = nullptr;
    TriangleModel* triangleModel = nullptr;
};

#endif // TRIANGLEVIEWMODEL_H
