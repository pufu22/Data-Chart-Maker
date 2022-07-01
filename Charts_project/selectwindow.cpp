#include "selectwindow.h"

selectWindow::selectWindow(QWidget* parent)
{
    lt=new QGridLayout(this);
    prima=new QPushButton("&Linechart");
    lt->addWidget(prima);
}
selectWindow::~selectWindow()
{}
