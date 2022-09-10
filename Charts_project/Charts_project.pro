QT       += core gui charts
QT += charts

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    data/areachartdata.cpp \
    data/bar_data.cpp \
    data/candlestickdata.cpp \
    data/chartData.cpp \
    data/comparisonChartData.cpp \
    inputdialog.cpp \
    data/linechartdata.cpp \
    main.cpp \
    model/candlestickchartmodel.cpp \
    model/candlestickcharttablemodel.cpp \
    data/pie_data.cpp \
    model/chartModel.cpp \
    model/chartTableModel.cpp \
    popupchart.cpp \
    model/areachartmodel.cpp \
    model/areacharttablemodel.cpp \
    model/barchart_model.cpp \
    model/barcharttablemodel.cpp \
    model/linechartmodel.cpp \
    model/linecharttablemodel.cpp \
    model/piechartmodel.cpp \
    model/piecharttablemodel.cpp \
    view/areachartwidget.cpp \
    view/barcharttable.cpp \
    view/candlestickchartwidget.cpp \
    view/chartWidget.cpp \
    view/choosechart.cpp \
    view/linechartwidget.cpp \
    view/mainwindow.cpp \
    view/piechartwidget.cpp \
    view/selectGraphic.cpp \
    view/selectwindow.cpp

HEADERS += \
    data/areachartdata.h \
    data/bar_data.h \
    data/candlestickdata.h \
    data/chartData.h \
    data/comparisonChartData.h \
    inputdialog.h \
    data/linechartdata.h \
    model/candlestickchartmodel.h \
    model/candlestickcharttablemodel.h \
    data/pie_data.h \
    model/chartModel.h \
    model/chartTableModel.h \
    popupchart.h \
    model/areachartmodel.h \
    model/areacharttablemodel.h \
    model/barchart_model.h \
    model/barcharttablemodel.h \
    model/linechartmodel.h \
    model/linecharttablemodel.h \
    model/piechartmodel.h \
    model/piecharttablemodel.h \
    view/areachartwidget.h \
    view/barcharttable.h \
    view/candlestickchartwidget.h \
    view/chartWidget.h \
    view/choosechart.h \
    view/linechartwidget.h \
    view/mainwindow.h \
    view/piechartwidget.h \
    view/selectGraphic.h \
    view/selectwindow.h

FORMS +=

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    Images.qrc
