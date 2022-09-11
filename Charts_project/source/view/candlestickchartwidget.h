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
    QPushButton* cambiaTitolo;
public:
    explicit CandleStickChartWidget(CandleStickData* data = nullptr, QWidget *parent = nullptr);
private slots:
    void cambiaTitoloSlot();
    void aggiungiSetSlot();
    void rimuoviSetSlot();
signals:
    void salvaJson();
    void cambiaTitoloSignal(QString titolo);
};

#endif // CANDLESTICKCHARTWIDGET_H
