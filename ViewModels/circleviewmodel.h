
#ifndef CIRCLEVIEWMODEL_H
#define CIRCLEVIEWMODEL_H

#include "basefigureviewmodel.h"
#include "Models/circlemodel.h"
#include <QLineEdit>

class CircleViewModel : public BaseFigureViewModel
{
public:
    CircleViewModel(QWidget *parent = nullptr);
    virtual void ClearInputForms() override;
    ~CircleViewModel();
protected:
    virtual void SetImagePath() override;
    virtual void SetupInputForms() override;

protected slots:
    virtual void ProvideCalculateLogicFromModel() override;

private:
    QLineEdit *inputCircleRadiousForm = nullptr;
    CircleModel *circleModel = nullptr;
};

#endif // CIRCLEVIEWMODEL_H
