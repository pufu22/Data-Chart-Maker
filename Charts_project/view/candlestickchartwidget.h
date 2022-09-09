#ifndef CANDLESTICKCHARTWIDGET_H
#define CANDLESTICKCHARTWIDGET_H

#include <QObject>
#include <QWidget>
#include <model/candlestickchartmodel.h>
#include <model/candlestickcharttablemodel.h>
#include <data/candlestickdata.h>
class CandleStickChartWidget : public QWidget
{
    Q_OBJECT
public:
    explicit CandleStickChartWidget(QWidget *parent = nullptr);
private:
    CandleStickChartModel* candleModel;
    CandleStickChartTableModel* candleTableModel;
    QTableView* candleTable;
    QLayout* lt;
    CandleStickData* dati;
    QChartView* chartview;
    QPushButton* aggiungiSet;
    QPushButton* rimuoviSet;
private slots:
    void aggiungiSetSlot();
    void rimuoviSetSlot();
};

#endif // CANDLESTICKCHARTWIDGET_H
