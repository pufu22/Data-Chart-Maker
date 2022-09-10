#ifndef AREACHARTWIDGET_H
#define AREACHARTWIDGET_H

#include <QObject>
#include <QWidget>
#include<model/areacharttablemodel.h>
#include<model/areachartmodel.h>
#include<data/areachartdata.h>
class AreaChartWidget:public QWidget
{
    Q_OBJECT
public:
    AreaChartWidget(QWidget *parent = 0, const char* name = 0,AreaChartData* data=nullptr);
    AreaChartModel* areaModel;
    AreaChartTableModel* areaTableModel;
    QTableView* areaTable;
    QLayout* lt;
    QChartView* chartview;
    QPushButton* aggiungiLinea;
    QPushButton* aggiungiPunto;
    QPushButton* rimuoviLinea;
    QPushButton* rimuoviPunto;
    QPushButton* cambiaTitolo;
private slots:
    void cambiaTitoloSlot();
    void aggiungiLineaSlot();
    void aggiungiPuntoSlot();
    void rimuoviLineaSlot();
    void rimuoviPuntoSlot();
public slots:
    void salvaJson();
signals:
    void cambiaTitoloSignal(QString titolo);
};

#endif // AREACHARTWIDGET_H
