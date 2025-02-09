#ifndef PIECHARTWIDGET_H
#define PIECHARTWIDGET_H

#include "mainwindow.h"
#include <source/model/piechartmodel.h>
#include <source/dialog/inputdialog.h>
#include <source/dialog/popupchart.h>
#include <QWidget>

class piechartwidget : public QWidget {
    Q_OBJECT
public:
    piechartwidget(pie_data* data=nullptr, QWidget* parent = nullptr);
    ~piechartwidget();
private:
    ChartModel* pieModel;
    QTableView* pietable;
    QLayout* lt;
    QChartView* chartview;
    QPushButton* aggiungifetta;
    QPushButton* rimuovifetta;
    QPushButton* cambiaTitolo;
    QPushButton* ingrandisci;
public slots:
    void aggiungifettaslot();
    void rimuovifettaslot();
    void cambiaTitoloSlot();
    void chartFocus();
    void salvaJsonPie();
signals:
    void cambiaTitoloSignal(QString titolo);
};

#endif // PIECHARTWIDGET_H
