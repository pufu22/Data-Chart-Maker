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
public:
    AreaChartWidget(QWidget *parent = nullptr, const char* name = nullptr);
private slots:
    void aggiungiLineaSlot();
    void aggiungiPuntoSlot();
};

#endif // AREACHARTWIDGET_H
