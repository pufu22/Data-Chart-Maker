#ifndef PIECHARTWIDGET_H
#define PIECHARTWIDGET_H

#include <QWidget>
#include<pie_data.h>
#include<model/piechartmodel.h>
#include<model/piecharttablemodel.h>
#include<inputdialog.h>
#include<view/mainwindow.h>
class piechartwidget:public QWidget
{
    Q_OBJECT
public:
    piechartwidget(QWidget *parent = 0, const char* name = 0);
    piechartwidget(QWidget *parent=0, const char *name=0,pie_data* d=0);
    //virtual ~piechartwidget(){};
private:
    piechartmodel* piemodel;
    Piecharttablemodel* pietablemodel;
    QTableView* pietable;
    QLayout* lt;
    pie_data* dati;
    QChartView* chartview;
    QPushButton* aggiungifetta;
    QPushButton* rimuovifetta;
    QPushButton* cambiaTitolo;
public slots:
    void aggiungifettaslot();
    void rimuovifettaslot();
    void cambiaTitoloSlot();
    void salvaJsonPie();
};

#endif // PIECHARTWIDGET_H
