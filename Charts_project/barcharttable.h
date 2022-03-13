#ifndef BARCHARTTABLE_H
#define BARCHARTTABLE_H

#include <QWidget>
#include <QTableView>
#include <QLayout>
#include <QPushButton>
#include <barchart_model.h>
#include <barcharttablemodel.h>
class barcharttable:public QWidget{
    Q_OBJECT

public:
    barcharttable(QWidget *parent = 0, const char *name = 0);
    virtual ~barcharttable(){}
private:
    BarChartTableModel *barmodel;
    QTableView *table;
    QLayout* lt;
    QPushButton* aggiungi_riga;
    QPushButton* aggiungi_colonna;
};

#endif // BARCHARTTABLE_H
