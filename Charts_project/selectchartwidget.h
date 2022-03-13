#ifndef SELECTCHARTWIDGET_H
#define SELECTCHARTWIDGET_H

#endif // SELECTCHARTWIDGET_H
#include<QWidget>
#include <QBoxLayout>
class selectchartwidget:public QWidget{
    Q_OBJECT
public:
    selectchartwidget(QWidget *parent = 0, const char *name = 0);
    ~selectchartwidget(){};
private:
    QHBoxLayout* lt;
};
