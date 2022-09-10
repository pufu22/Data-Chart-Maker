#ifndef AREACHARTMODEL_H
#define AREACHARTMODEL_H
#include<QChart>
#include<QVXYModelMapper>
#include<data/areachartdata.h>
#include<model/areacharttablemodel.h>
class AreaChartModel:public QObject
{
public:
    AreaChartModel(QAbstractTableModel* data);
    QChart* getChart();
    void updateMappers();
    void updateRemoved(int pos);

public slots:
    void updateAxisY();
    void salvaJson();
    void changeTitle(QString title);
private slots:
    void cambiaNome();
private:
    QAbstractTableModel* dati;
    QChart *chart;
    QVector<QVXYModelMapper*> linesmappers;
    QVector <QLineSeries*> series;
    QVector <QAreaSeries*> areaSeries;
    int nLines;
    int getMin();
    int getMax();

};

#endif // AREACHARTMODEL_H
