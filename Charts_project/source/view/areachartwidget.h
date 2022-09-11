#ifndef AREACHARTWIDGET_H
#define AREACHARTWIDGET_H

#include<source/model/areachartmodel.h>
#include <QWidget>

class AreaChartWidget : public QWidget {
    Q_OBJECT
private:
    ChartModel* areaModel;
    QTableView* areaTable;
    QLayout* lt;
    QChartView* chartview;
    QPushButton* aggiungiLinea;
    QPushButton* aggiungiPunto;
    QPushButton* rimuoviLinea;
    QPushButton* rimuoviPunto;
    QPushButton* cambiaTitolo;
public:
    AreaChartWidget(AreaChartData* data = nullptr, QWidget *parent = nullptr);
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
