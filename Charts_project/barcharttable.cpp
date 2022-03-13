#include "barcharttable.h"

barcharttable::barcharttable(QWidget *parent, const char *name):QWidget(parent)
{
    lt=new QGridLayout(this);

    aggiungi_riga=new QPushButton("&Aggiungi riga",this);
    aggiungi_colonna=new QPushButton("&Aggiungi colonna",this);
    lt->addWidget(aggiungi_riga);
    lt->addWidget(aggiungi_colonna);
    table=new QTableView(this);

    lt->addWidget(table);
    lt->setSizeConstraint(QLayout::SetFixedSize);
    setLayout(lt);

}
