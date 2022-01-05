#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "CreateChartWidget.h"
#include<QChartView>
#include<qchartview.h>
#include<QChart>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    CreateChartWidget *createwidget=new CreateChartWidget(this,"cre");
    this->layout()->addWidget(createwidget);

}

MainWindow::~MainWindow()
{
    delete ui;
}

