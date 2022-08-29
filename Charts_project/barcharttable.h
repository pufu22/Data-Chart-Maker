#ifndef BARCHARTTABLE_H
#define BARCHARTTABLE_H

#include <QWidget>
#include <QTableView>
#include <QLayout>
#include <QPushButton>
#include <barchart_model.h>
#include <barcharttablemodel.h>
#include<bar_data.h>
#include<mainwindow.h>
class barcharttable:public QWidget{
    Q_OBJECT

public:
    barcharttable(Bar_data* data=0, QWidget *parent = 0, const char *name = 0);

private:
    BarChartTableModel *barmodel;
    BarChartModel *m_model;
    QTableView *table;
    QLayout* lt;
    QPushButton* aggiungi_riga;
    QPushButton* aggiungi_colonna;
    QPushButton* removeBars;
    QPushButton* removeSet;
    QPushButton* changeTitle;
    void setupModels();
    Bar_data *dati;
    BarChartModel *barchartmodel;
    QChart *chart;
private slots:
       void aggiungiriga();
       void aggiungicolonna();
       void removebars();
       void removeset();
       void changetitle();
public slots:
       void salvaJsonBar();
signals:
       void riga();
};

#endif // BARCHARTTABLE_H
