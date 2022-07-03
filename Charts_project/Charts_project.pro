QT       += core gui charts
QT += charts

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    CreateChartWidget.cpp \
    bar_data.cpp \
    barchart_model.cpp \
    barcharttable.cpp \
    barcharttablemodel.cpp \
    charts_data.cpp \
    createwindow.cpp \
    inputdialog.cpp \
    linechartdata.cpp \
    linechartmodel.cpp \
    linecharttablemodel.cpp \
    linechartwidget.cpp \
    main.cpp \
    mainwindow.cpp \
    pie_data.cpp \
    piechartmodel.cpp \
    piecharttablemodel.cpp \
    piechartwidget.cpp \
    selectchartwidget.cpp \
    selectwindow.cpp \
    tablemodel.cpp

HEADERS += \
    CreateChartWidget.h \
    bar_data.h \
    barchart_model.h \
    barcharttable.h \
    barcharttablemodel.h \
    charts_data.h \
    createwindow.h \
    inputdialog.h \
    linechartdata.h \
    linechartmodel.h \
    linecharttablemodel.h \
    linechartwidget.h \
    mainwindow.h \
    pie_data.h \
    piechartmodel.h \
    piecharttablemodel.h \
    piechartwidget.h \
    selectchartwidget.h \
    selectwindow.h \
    tablemodel.h

FORMS +=

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
