#ifndef BARCHARTTABLE_H
#define BARCHARTTABLE_H

#include <QWidget>
#include <QTableView>
#include <QLayout>
#include <QPushButton>
#include <barchart_model.h>
#include <barcharttablemodel.h>
#include<bar_data.h>
class barcharttable:public QWidget{
    Q_OBJECT

public:
    barcharttable(QWidget *parent = 0, const char *name = 0);
    virtual ~barcharttable(){}
private:
    BarChartTableModel *barmodel;
    BarChartModel *m_model;
    QTableView *table;
    QLayout* lt;
    QPushButton* aggiungi_riga;
    QPushButton* aggiungi_colonna;
    void setupModels();
    Bar_data *dati;
    BarChartModel *barchartmodel;
    QChart *chart;
private slots:
       void aggiungiriga();
       void aggiungicolonna();
signals:
       void riga();
};

#endif // BARCHARTTABLE_H
