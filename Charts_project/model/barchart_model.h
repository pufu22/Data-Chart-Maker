#ifndef BARCHART_MODEL_H
#define BARCHART_MODEL_H
#include<data/bar_data.h>
#include<model/barcharttablemodel.h>
#include<qbarmodelmapper.h>
#include<QString>
class BarChartModel:public QObject
{
public:
    BarChartModel(BarChartTableModel *data);
    QChart* getChart();
    void updateMapperLastColumn();
    void updateMapperLastRow(BarChartTableModel *data);
    void updateMapperRemoveColumn();
    void updateMapperRemoveRow(int pos);
    void salvaJsonBar();
    void changeTitle(BarChartTableModel *data,QString t);
private:
    BarChartTableModel* dati;
    QChart *chart;
    QBarSeries *series;
    QStringList categories;
    QBarCategoryAxis *axisX;
    QValueAxis *axisY;
    QVBarModelMapper *mapper;
    QString title;
    int lastcolumn;
    int lastrow;
    int getMax();
    int getMin();
private slots:
    void cambiaNome(int index,QBarSet* barset);
public slots:
    void updateAxisY();
};

#endif // BARCHART_MODEL_H
