
#ifndef RECTVIEWMODEL_H
#define RECTVIEWMODEL_H

#include "basefigureviewmodel.h"
#include <QLineEdit>
#include "Models/rectmodel.h"

class RectViewModel : public BaseFigureViewModel
{
public:
    RectViewModel(QWidget *parent = nullptr);
    ~RectViewModel();
    virtual void ClearInputForms() override;
protected:
    virtual void SetImagePath() override;
    virtual void SetupInputForms() override;

protected slots:
    virtual void ProvideCalculateLogicFromModel() override;

private:
    QLineEdit *inputRectSightA = nullptr;
    QLineEdit *inputRectSightB = nullptr;
    RectModel *rectModel = nullptr;
};

#endif // RECTVIEWMODEL_H
