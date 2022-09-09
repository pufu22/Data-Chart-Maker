#ifndef CHARTWIDGET_H
#define CHARTWIDGET_H

#include <QWidget>
#include <QTableView>
#include <QPushButton>
#include <QtCharts>

class ChartWidget : public QWidget {
    Q_OBJECT
protected:
    QTableView* table;
    QVector<QPushButton*>* buttons;
    QChartView* chartView;
    QLayout* lt;
public:
    explicit ChartWidget(QWidget *parent = nullptr);
    virtual void setTableView() =0;
    virtual QVector<QPushButton*>* setArrayPushButton() =0;
    virtual void setChartView() =0;
};

#endif // CHARTWIDGET_H
