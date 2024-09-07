
#ifndef PARALLELOGRAMMVIEWMODEL_H
#define PARALLELOGRAMMVIEWMODEL_H

#include "basefigureviewmodel.h"
#include <QLineEdit>
#include <Models/parallelogrammodel.h>

class ParallelogrammViewModel : public BaseFigureViewModel
{
public:
    virtual void ClearInputForms() override;
    ~ParallelogrammViewModel();
    ParallelogrammViewModel(QWidget *parent = nullptr);

protected:
    virtual void SetImagePath() override;
    virtual void SetupInputForms() override;

protected slots:
    virtual void ProvideCalculateLogicFromModel() override;

private:
    QLineEdit *inputParallelogramBase = nullptr;
    QLineEdit *inputParallelogramHeight = nullptr;
    ParallelogramModel *parallelogramModel = nullptr;
};

#endif // PARALLELOGRAMMVIEWMODEL_H
