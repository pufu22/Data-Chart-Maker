QT       += core gui charts
QT += charts

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    areachartdata.cpp \
    bar_data.cpp \
    charts_data.cpp \
    inputdialog.cpp \
    linechartdata.cpp \
    main.cpp \
    pie_data.cpp \
    popupchart.cpp \
    model/areachartmodel.cpp \
    model/areacharttablemodel.cpp \
    model/barchart_model.cpp \
    model/barcharttablemodel.cpp \
    model/linechartmodel.cpp \
    model/linecharttablemodel.cpp \
    model/piechartmodel.cpp \
    model/piecharttablemodel.cpp \
    model/tablemodel.cpp \
    view/areachartwidget.cpp \
    view/CreateChartWidget.cpp \
    view/barcharttable.cpp \
    view/createwindow.cpp \
    view/linechartwidget.cpp \
    view/mainwindow.cpp \
    view/piechartwidget.cpp \
    view/selectchartwidget.cpp \
    view/selectwindow.cpp

HEADERS += \
    areachartdata.h \
    bar_data.h \
    charts_data.h \
    inputdialog.h \
    linechartdata.h \
    pie_data.h \
    popupchart.h \
    model/areachartmodel.h \
    model/areacharttablemodel.h \
    model/barchart_model.h \
    model/barcharttablemodel.h \
    model/linechartmodel.h \
    model/linecharttablemodel.h \
    model/piechartmodel.h \
    model/piecharttablemodel.h \
    model/tablemodel.h \
    view/areachartwidget.h \
    view/CreateChartWidget.h \
    view/barcharttable.h \
    view/createwindow.h \
    view/linechartwidget.h \
    view/mainwindow.h \
    view/piechartwidget.h \
    view/selectchartwidget.h \
    view/selectwindow.h

FORMS +=

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
