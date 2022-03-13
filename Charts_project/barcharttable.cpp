#include "barcharttable.h"

barcharttable::barcharttable(QWidget *parent, const char *name):QWidget(parent)
{
    lt=new QGridLayout(this);

    aggiungi_riga=new QPushButton("&Aggiungi riga");
    aggiungi_colonna=new QPushButton("&Aggiungi colonna");
    table=new QTableView;
    barmodel=new BarChartTableModel();
    table->setModel(barmodel);
    lt->addWidget(table);
    table->show();
    lt->addWidget(aggiungi_riga);
    lt->addWidget(aggiungi_colonna);




    lt->setSizeConstraint(QLayout::SetFixedSize);
    setLayout(lt);

}
