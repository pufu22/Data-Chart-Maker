QT       += core gui charts
QT += charts

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    source/data/areachartdata.cpp \
    source/data/bar_data.cpp \
    source/data/candlestickdata.cpp \
    source/data/chartData.cpp \
    source/data/comparisonChartData.cpp \
    source/data/linechartdata.cpp \
    source/data/pie_data.cpp \
    source/model/candlestickchartmodel.cpp \
    source/model/candlestickcharttablemodel.cpp \
    source/model/chartModel.cpp \
    source/model/chartTableModel.cpp \
    source/model/areachartmodel.cpp \
    source/model/areacharttablemodel.cpp \
    source/model/barchart_model.cpp \
    source/model/barcharttablemodel.cpp \
    source/model/linechartmodel.cpp \
    source/model/linecharttablemodel.cpp \
    source/model/piechartmodel.cpp \
    source/model/piecharttablemodel.cpp \
    source/view/areachartwidget.cpp \
    source/view/barcharttable.cpp \
    source/view/candlestickchartwidget.cpp \
    source/view/linechartwidget.cpp \
    source/view/mainwindow.cpp \
    source/view/piechartwidget.cpp \
    source/widget/choosechart.cpp \
    source/widget/selectGraphic.cpp \
    source/dialog/popupchart.cpp \
    source/dialog/inputdialog.cpp \
    source/main.cpp

HEADERS += \
    source/data/areachartdata.h \
    source/data/bar_data.h \
    source/data/candlestickdata.h \
    source/data/chartData.h \
    source/data/comparisonChartData.h \
    source/data/pie_data.h \
    source/data/linechartdata.h \
    source/model/candlestickchartmodel.h \
    source/model/candlestickcharttablemodel.h \
    source/model/chartModel.h \
    source/model/chartTableModel.h \
    source/model/areachartmodel.h \
    source/model/areacharttablemodel.h \
    source/model/barchart_model.h \
    source/model/barcharttablemodel.h \
    source/model/linechartmodel.h \
    source/model/linecharttablemodel.h \
    source/model/piechartmodel.h \
    source/model/piecharttablemodel.h \
    source/view/areachartwidget.h \
    source/view/barcharttable.h \
    source/view/candlestickchartwidget.h \
    source/view/linechartwidget.h \
    source/view/mainwindow.h \
    source/view/piechartwidget.h \
    source/widget/choosechart.h \
    source/widget/selectGraphic.h \
    source/dialog/inputdialog.h \
    source/dialog/popupchart.h

FORMS +=

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    Images.qrc
