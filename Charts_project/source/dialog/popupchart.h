#ifndef POPUPCHART_H
#define POPUPCHART_H

#include <QDialog>
#include <QtCharts>

class PopupChart : public QDialog {
    Q_OBJECT
public:
    PopupChart(QChartView* chart,QWidget *parent = nullptr);
    QVBoxLayout* lyt;
    QChart* chart;
    static void chartFocus(QChartView* chart,QWidget* parent);
};

#endif // POPUPCHART_H
