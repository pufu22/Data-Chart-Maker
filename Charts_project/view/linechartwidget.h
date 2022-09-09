#ifndef LINECHARTWIDGET_H
#define LINECHARTWIDGET_H

#include <QWidget>
#include<data/linechartdata.h>
#include<model/linechartmodel.h>
#include<model/linecharttablemodel.h>
#include<view/mainwindow.h>
#include <algorithm>
class LineChartWidget:public QWidget
{
    Q_OBJECT
public:
    LineChartWidget(LineChartData* data=nullptr,QWidget *parent = 0, const char* name = 0);
    virtual ~LineChartWidget(){};
private:
    LineChartTableModel *linecharttablemodel;
    LineChartModel *linechartmodel;
    QTableView *table;
    QLayout *lt;
    QPushButton* aggiungiriga;
    QPushButton* aggiungilinea;
    QPushButton* togliLinea;
    QPushButton* togliPunto;
    LineChartData* dati;
    QChartView* chartview;

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
