QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Models/basefiguremodel.cpp \
    Models/circlemodel.cpp \
    Models/parallelogrammodel.cpp \
    Models/rectmodel.cpp \
    Models/rhombusmodel.cpp \
    Models/sectormodel.cpp \
    Models/squaremodel.cpp \
    Models/trapezoidmodel.cpp \
    Models/trianglemodel.cpp \
    ViewModels/basefigureviewmodel.cpp \
    ViewModels/circleviewmodel.cpp \
    ViewModels/menuviewmodel.cpp \
    ViewModels/parallelogrammviewmodel.cpp \
    ViewModels/rectviewmodel.cpp \
    ViewModels/rhombusviewmodel.cpp \
    ViewModels/sectorviewmodel.cpp \
    ViewModels/squareviewmodel.cpp \
    ViewModels/trapezoidviewmodel.cpp \
    ViewModels/triangleviewmodel.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    Models/basefiguremodel.h \
    Models/circlemodel.h \
    Models/parallelogrammodel.h \
    Models/rectmodel.h \
    Models/rhombusmodel.h \
    Models/sectormodel.h \
    Models/squaremodel.h \
    Models/trapezoidmodel.h \
    Models/trianglemodel.h \
    ViewModels/basefigureviewmodel.h \
    ViewModels/circleviewmodel.h \
    ViewModels/menuviewmodel.h \
    ViewModels/parallelogrammviewmodel.h \
    ViewModels/rectviewmodel.h \
    ViewModels/rhombusviewmodel.h \
    ViewModels/sectorviewmodel.h \
    ViewModels/squareviewmodel.h \
    ViewModels/trapezoidviewmodel.h \
    ViewModels/triangleviewmodel.h \
    mainwindow.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    Images/circle.png \
    Images/parallelogram.png \
    Images/rect.png \
    Images/rhombus.png \
    Images/sector.png \
    Images/square.jpg \
    Images/trapezoid.png \
    Images/triangle.png

RESOURCES += \
    resources.qrc
