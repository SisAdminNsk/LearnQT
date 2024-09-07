
#ifndef SQUAREVIEWMODEL_H
#define SQUAREVIEWMODEL_H

#include "basefigureviewmodel.h"
#include "Models/squaremodel.h"
#include <QLineEdit>

class SquareViewModel : public BaseFigureViewModel
{
public:
    SquareViewModel(QWidget *parent = nullptr);
    ~SquareViewModel();
    virtual void ClearInputForms() override;
protected:
    virtual void SetImagePath() override;
    virtual void SetupInputForms() override;

protected slots:
    virtual void ProvideCalculateLogicFromModel() override;

private:
    QLineEdit* inputSquareSightField = nullptr;
    SquareModel* squareModel = nullptr;
};

#endif // SQUAREVIEWMODEL_H
