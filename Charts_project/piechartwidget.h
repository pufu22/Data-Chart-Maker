#ifndef PIECHARTWIDGET_H
#define PIECHARTWIDGET_H

#include <QWidget>
#include<pie_data.h>
#include<piechartmodel.h>
#include<piecharttablemodel.h>
class piechartwidget:public QWidget
{
    Q_OBJECT
public:
    piechartwidget(QWidget *parent = 0, const char* name = 0);
    virtual ~piechartwidget(){};
private:
    piechartmodel* piemodel;
    Piecharttablemodel* pietablemodel;
    QTableView* pietable;
    QLayout* lt;
    pie_data* dati;
    QChartView* chartview;
    QPushButton* aggiungifetta;
public slots:
    void aggiungifettaslot();
};

#endif // PIECHARTWIDGET_H
