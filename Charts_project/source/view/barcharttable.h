#ifndef BARCHARTTABLE_H
#define BARCHARTTABLE_H

#include "mainwindow.h"
#include <source/model/barchart_model.h>
#include <source/dialog/popupchart.h>
#include <QWidget>

class barcharttable : public QWidget {
    Q_OBJECT
private:
    ChartModel *barModel;
    QTableView *barTable;
    QChartView *chartView;
    QLayout* lt;
    QPushButton* aggiungi_riga;
    QPushButton* aggiungi_colonna;
    QPushButton* removeBars;
    QPushButton* removeSet;
    QPushButton* changeTitle;
    QPushButton* ingrandisci;
public:
    barcharttable(Bar_data* data = nullptr, QWidget *parent = nullptr);
private slots:
       void aggiungiriga();
       void aggiungicolonna();
       void removebars();
       void removeset();
       void changetitle();
public slots:
       void salvaJsonBar();
       void chartFocus();
signals:
       void riga();
       void cambiaTitoloSignal(QString titolo);
};

#endif // BARCHARTTABLE_H
