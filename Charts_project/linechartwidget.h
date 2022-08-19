#ifndef LINECHARTWIDGET_H
#define LINECHARTWIDGET_H

#include <QWidget>
#include<linechartdata.h>
#include<linechartmodel.h>
#include<linecharttablemodel.h>
#include<mainwindow.h>
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
    QPushButton* aggiungicolonna;
    QPushButton* aggiungilinea;
    LineChartData* dati;
    QChartView* chartview;

private slots:
    void aggiungilineaslot();
    void aggiungipunto();
signals:
    void linea();
public slots:
    void salvaJsonFile();
};

#endif // LINECHARTWIDGET_H
