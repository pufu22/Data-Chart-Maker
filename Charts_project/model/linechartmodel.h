#ifndef LINECHARTMODEL_H
#define LINECHARTMODEL_H

#include<vector>
#include<string>
#include<model/linecharttablemodel.h>
#include<QtCharts>
#include<QVXYModelMapper>
#include<data/linechartdata.h>
class LineChartModel:public QObject
{

public:
    QChart* getChart();
    LineChartModel(LineChartTableModel *data);

    void updateMapper(LineChartTableModel *data);
    //void addLinea(LineChartTableModel *data,QString l);
    void salvaJsonFile();
    void removeLine(int pos);
    void updateRemoved(int pos);
    void cambiaTitolo(LineChartTableModel* data,QString t);
private:
    LineChartTableModel* dati;
    QChart *chart;
    int nLines;
    QVector<QLineSeries*> series;
    QString title;
    QVector<QVXYModelMapper*> mapper;
    int getMax();
    int getMin();
public slots:
    void updateAxises();
    void axises(int maxValue);
    void updateAxisY();
    void cambiaNome();
};

#endif // LINECHARTMODEL_H
