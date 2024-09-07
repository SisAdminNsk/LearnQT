
#ifndef BASEFIGUREVIEWMODEL_H
#define BASEFIGUREVIEWMODEL_H

#include "Models/basefiguremodel.h"

#include <QWidget>
#include <QLabel>
#include <QVBoxLayout>
#include <QPushButton>
#include <QDoubleValidator>

class BaseFigureViewModel : public QWidget
{
    Q_OBJECT
public:
    explicit BaseFigureViewModel(QWidget *parent = nullptr);
    ~BaseFigureViewModel();
    virtual void ClearInputForms() = 0;

protected:
    virtual void SetImagePath() = 0;
    virtual void LoadImage();
    virtual void SetImageSize();
    virtual void SetupImage();
    virtual void SetupInputForms() = 0;
    virtual void SetupCalculateButton();

    void Setup();

    void ShowCalcResults(BaseFigureModel* figure, const QString& messageHeader, const QString& messageBody);

protected:
    // ставим валидацию на форме
    QDoubleValidator *validator = nullptr;

    QString imagePath = nullptr;
    QLabel *image = nullptr;
    QPixmap* pixmap = nullptr;
    QVBoxLayout* layout = nullptr;

private:
    void SetupValidator();

    size_t imageWidthPx;
    size_t imageHeightPx;

protected slots:
    virtual void ProvideCalculateLogicFromModel() = 0;
};

#endif // BASEFIGUREVIEWMODEL_H
