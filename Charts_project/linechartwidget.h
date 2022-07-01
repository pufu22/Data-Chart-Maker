#ifndef LINECHARTWIDGET_H
#define LINECHARTWIDGET_H

#include <QWidget>
#include<linechartdata.h>
#include<linechartmodel.h>
#include<linecharttablemodel.h>
class LineChartWidget:public QWidget
{
    Q_OBJECT
public:
    LineChartWidget(QWidget *parent = 0, const char* name = 0);
    virtual ~LineChartWidget(){};
private:
    LineChartTableModel *linecharttablemodel;
    LineChartModel *linechartmodel;
    QTableView *table;
    QLayout *lt;
    QPushButton* aggiungiriga;
    QPushButton* aggiungicolonna;
    QPushButton* aggiungilinea;
    LineChartData* dati;
    QChartView* chartview;

private slots:
    void aggiungilineaslot();
    void aggiungipunto();
signals:
    void linea();
};

#endif // LINECHARTWIDGET_H
