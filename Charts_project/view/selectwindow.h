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
    void creaLineChart();
    void creaBarChart();
signals:
    void creaBarChartSignal();
    void creaLineChartSignal();
};

#endif // SELECTWINDOW_H
