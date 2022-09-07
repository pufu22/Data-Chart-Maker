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
    candlestickdata.cpp \
    comparisonChartData.cpp \
    inputdialog.cpp \
    linechartdata.cpp \
    main.cpp \
    model/candlestickchartmodel.cpp \
    model/candlestickcharttablemodel.cpp \
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
    statisticalChartData.cpp \
    view/areachartwidget.cpp \
    view/barcharttable.cpp \
    view/candlestickchartwidget.cpp \
    view/choosechart.cpp \
    view/linechartwidget.cpp \
    view/mainwindow.cpp \
    view/piechartwidget.cpp \
    view/selectGraphic.cpp \
    view/selectwindow.cpp

HEADERS += \
    areachartdata.h \
    bar_data.h \
    candlestickdata.h \
    comparisonChartData.h \
    inputdialog.h \
    linechartdata.h \
    model/candlestickchartmodel.h \
    model/candlestickcharttablemodel.h \
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
    statisticalChartData.h \
    view/areachartwidget.h \
    view/barcharttable.h \
    view/candlestickchartwidget.h \
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
