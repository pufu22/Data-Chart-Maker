#ifndef LINECHARTWIDGET_H
#define LINECHARTWIDGET_H

#include "mainwindow.h"
#include <source/model/linechartmodel.h>
#include <QWidget>

class LineChartWidget : public QWidget {
    Q_OBJECT
private:
    ChartModel* lineModel;
    QTableView* tableModel;
    QLayout* lt;
    QPushButton* aggiungiriga;
    QPushButton* aggiungilinea;
    QPushButton* togliLinea;
    QPushButton* togliPunto;
    QChartView* chartview;
public:
    LineChartWidget(LineChartData* data=nullptr,QWidget *parent = 0, const char* name = 0);
    virtual ~LineChartWidget(){};
private slots:
    void aggiungilineaslot();
    void aggiungipunto();
    void togliLineaSlot();
    void togliPuntoSlot();
signals:
    void linea();
public slots:
    void salvaJsonFile();
};

#endif // LINECHARTWIDGET_H
