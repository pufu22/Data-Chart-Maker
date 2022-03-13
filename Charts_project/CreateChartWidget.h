#ifndef CREATECHARTWIDGET_H
#define CREATECHARTWIDGET_H
#include<QPushButton>
#include<QLabel>
#include<QWidget>
#include<qwidget.h>
#include <QBoxLayout>
class CreateChartWidget:public QWidget{
Q_OBJECT
public:
    CreateChartWidget(QWidget *parent = 0, const char *name = 0);
    ~CreateChartWidget(){};

private:
    QHBoxLayout lt;
    QLabel label;
    QPushButton createbutton;
private slots:
    void apri_crea();
};

#endif // CREATECHARTWIDGET_H
