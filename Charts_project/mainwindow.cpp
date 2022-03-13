#include "mainwindow.h"
#include "ui_mainwindow.h"
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

    barcharttable* bartable=new barcharttable(this,"bartable");
    this->layout()->addWidget(bartable);

}

MainWindow::~MainWindow()
{

}

void MainWindow::createMenus()
  {
       fileMenu = menuBar()->addMenu(tr("&File"));
}
