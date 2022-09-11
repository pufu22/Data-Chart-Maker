#ifndef LINECHARTWIDGET_H
#define LINECHARTWIDGET_H

#include "mainwindow.h"
#include <source/model/linechartmodel.h>
#include <QWidget>
#include <source/dialog/popupchart.h>
class LineChartWidget : public QWidget {
    Q_OBJECT
private:
    ChartModel* lineModel;
    QTableView* tableModel;
    QLayout* lt;
    QChartView* chartview;
    QPushButton* aggiungiriga;
    QPushButton* aggiungilinea;
    QPushButton* togliLinea;
    QPushButton* togliPunto;
    QPushButton* cambiaTitolo;
    QPushButton* ingrandisci;
public:
    LineChartWidget(LineChartData* data = nullptr,QWidget *parent = nullptr);
    virtual ~LineChartWidget(){};
private slots:
    void aggiungilineaSlot();
    void aggiungipuntoSlot();
    void togliLineaSlot();
    void togliPuntoSlot();
    void cambiaTitoloSlot();
public slots:
    void salvaJsonFile();
    void chartFocus();
signals:
    void linea();
    void cambiaTitoloSignal(QString titolo);
};

#endif // LINECHARTWIDGET_H
