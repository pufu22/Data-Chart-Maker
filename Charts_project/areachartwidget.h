#ifndef AREACHARTWIDGET_H
#define AREACHARTWIDGET_H

#include <QObject>
#include <QWidget>
#include<areacharttablemodel.h>
#include<areachartmodel.h>
#include<areachartdata.h>
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
private slots:
    void aggiungiLineaSlot();
};

#endif // AREACHARTWIDGET_H
