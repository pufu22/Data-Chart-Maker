#ifndef AREACHARTWIDGET_H
#define AREACHARTWIDGET_H

#include <QObject>
#include <QWidget>
#include<model/areacharttablemodel.h>
#include<model/areachartmodel.h>
#include<data/areachartdata.h>
class AreaChartWidget:public QWidget
{
    Q_OBJECT
public:
    AreaChartWidget(QWidget *parent = 0, const char* name = 0);
    AreaChartModel* areaModel;
    AreaChartTableModel* areaTableModel;
    QTableView* areaTable;
    QLayout* lt;
    AreaChartData* dati;
    QChartView* chartview;
    QPushButton* aggiungiLinea;
    QPushButton* aggiungiPunto;
private slots:
    void aggiungiLineaSlot();
    void aggiungiPuntoSlot();
};

#endif // AREACHARTWIDGET_H
