#ifndef BARCHART_MODEL_H
#define BARCHART_MODEL_H
#include<bar_data.h>
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
    QChart *chart;
    QVector<QVector<QList<QBarSet>>> sets;
    QBarSeries *series;
    QStringList categories;
    QBarCategoryAxis *axisX;
    QValueAxis *axisY;
    QVBarModelMapper *mapper;
    QString title;
    int lastcolumn;
    int lastrow;
    friend class main;
public slots:
    void updateAxisY(int min,int max);
};

#endif // BARCHART_MODEL_H
