#ifndef CANDLESTICKCHARTWIDGET_H
#define CANDLESTICKCHARTWIDGET_H

#include <QObject>
#include <QWidget>
#include <model/candlestickchartmodel.h>
#include <model/candlestickcharttablemodel.h>
#include <candlestickdata.h>
class CandleStickChartWidget : public QWidget
{
    Q_OBJECT
public:
    explicit CandleStickChartWidget(QWidget *parent = nullptr,CandleStickData* d=nullptr);
private:
    CandleStickChartModel* candleModel;
    CandleStickChartTableModel* candleTableModel;
    QTableView* candleTable;
    QLayout* lt;
    CandleStickData* dati;
    QChartView* chartview;
    QPushButton* aggiungiSet;
    QPushButton* rimuoviSet;
    QPushButton* cambiaTitolo;
private slots:
    void cambiaTitoloSlot();
    void aggiungiSetSlot();
    void rimuoviSetSlot();
signals:
    void salvaJson();
};

#endif // CANDLESTICKCHARTWIDGET_H
