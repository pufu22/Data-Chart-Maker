#ifndef SELECTWINDOW_H
#define SELECTWINDOW_H
#include<QDialog>
#include<QLayout>
#include<QPushButton>

class selectWindow:public QDialog
{
    Q_OBJECT
public:
    selectWindow(QWidget* parent=0);
    ~selectWindow();

private:
    QLayout* lt;
    QPushButton* prima;
    QPushButton* seconda;
    QPushButton* terza;
    QPushButton* quarta;
    void creaLineChart();
    void creaBarChart();
    void creaAreaChart();
    void creaPieChart();
signals:
    void creaBarChartSignal();
    void creaLineChartSignal();
    void creaPieChartSignal();
    void creaAreaChartSignal();
};

#endif // SELECTWINDOW_H
