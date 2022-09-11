#ifndef CANDLESTICKCHARTWIDGET_H
#define CANDLESTICKCHARTWIDGET_H

#include <source/model/candlestickchartmodel.h>
#include <QWidget>

class CandleStickChartWidget : public QWidget {
    Q_OBJECT
private:
    ChartModel* candleModel;
    QTableView* candleTable;
    QLayout* lt;
    QChartView* chartview;
    QPushButton* aggiungiSet;
    QPushButton* rimuoviSet;
public:
    explicit CandleStickChartWidget(QWidget *parent = nullptr);
private slots:
    void aggiungiSetSlot();
    void rimuoviSetSlot();
};

#endif // CANDLESTICKCHARTWIDGET_H
