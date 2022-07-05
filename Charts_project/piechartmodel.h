#ifndef PIECHARTMODEL_H
#define PIECHARTMODEL_H

#include<vector>
#include<string>
#include<QtCharts>
#include<QString>
#include<QHPieModelMapper>
#include<piecharttablemodel.h>
class piechartmodel:public QObject
{
public:
    QChart* chart;
    piechartmodel(Piecharttablemodel* data);
    void connectInsertedSlice();
    int sliceCount();
    void mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event);
protected:
    QPieSeries* pieSeries;
    QString* title;
    QVPieModelMapper* piemapper;
public slots:
    void explodeSplice(bool state);


};

#endif // PIECHARTMODEL_H
