#include "mainwindow.h"
#include "CreateChartWidget.h"
#include<QChartView>
#include<qchartview.h>
#include<QChart>
#include <QAction>
#include <QMenuBar>
#include <QMenu>
#include <barcharttable.h>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{

    //barcharttable* bartable=new barcharttable(this,"bartable");
    //LineChartWidget* linechart= new LineChartWidget(this,"linechart");
    //this->setCentralWidget(linechart);
    //linechart->show();
    //bartable->show();
    this->createActions();
    this->createMenus();
}

MainWindow::~MainWindow()
{
}

void MainWindow::createMenus()
  {
       fileMenu = menuBar()->addMenu(tr("&File"));
       editMenu = menuBar()->addMenu(tr("&Edit"));
       fileMenu->addAction(newAct);
}

void MainWindow::createActions()
{
    newAct=new QAction(tr("&Nuovo"),this);
    newAct->setShortcuts(QKeySequence::New);
    newAct->setStatusTip("Crea un nuovo grafico");
    connect(newAct,&QAction::triggered,this,&MainWindow::nuovoGrafico);
}

void MainWindow::nuovoGrafico()
{
    selezionaTipo=new selectWindow(this);
    selezionaTipo->show();
}
