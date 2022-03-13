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
    charts_data.cpp \
    main.cpp \
    mainwindow.cpp \
    selectchartwidget.cpp \
    tablemodel.cpp

HEADERS += \
    CreateChartWidget.h \
    bar_data.h \
    barchart_model.h \
    barcharttable.h \
    charts_data.h \
    mainwindow.h \
    selectchartwidget.h \
    tablemodel.h

FORMS +=

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
