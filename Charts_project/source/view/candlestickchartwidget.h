#ifndef CANDLESTICKCHARTWIDGET_H
#define CANDLESTICKCHARTWIDGET_H

#include <source/model/candlestickchartmodel.h>
#include <QWidget>
#include <source/dialog/popupchart.h>
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
    QPushButton* ingrandisci;
public:
    explicit CandleStickChartWidget(CandleStickData* data = nullptr, QWidget *parent = nullptr);
private slots:
    void cambiaTitoloSlot();
    void aggiungiSetSlot();
    void rimuoviSetSlot();
    void chartFocus();
signals:
    void salvaJson();
    void cambiaTitoloSignal(QString titolo);
};

#endif // CANDLESTICKCHARTWIDGET_H
