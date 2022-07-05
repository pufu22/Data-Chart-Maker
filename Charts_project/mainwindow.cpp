#include "mainwindow.h"
#include "CreateChartWidget.h"
#include<QChartView>
#include<qchartview.h>
#include<QChart>
#include <QAction>
#include <QMenuBar>
#include <QMenu>
#include <barcharttable.h>
#include<piechartwidget.h>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{


    //LineChartWidget* linechart= new LineChartWidget(this,"linechart");
    //this->setCentralWidget(linechart);
    //linechart->show();
    //bartable->show();
    this->createActions();
    this->createMenus();
    //piechartwidget* piechart=new piechartwidget(this,"piechart");
    //this->setCentralWidget(piechart);
    //piechart->show();

}

MainWindow::~MainWindow()
{
}

void MainWindow::createMenus()
  {
       fileMenu = menuBar()->addMenu(tr("&File"));
       openMenu = menuBar()->addMenu(tr("&Open"));
       fileMenu->addAction(newAct);
       openMenu->addAction(openAct);
}

void MainWindow::createActions()
{
    newAct=new QAction(tr("&Nuovo"),this);
    newAct->setShortcuts(QKeySequence::New);
    newAct->setStatusTip("Crea un nuovo grafico");
    connect(newAct,&QAction::triggered,this,&MainWindow::nuovoGrafico);
    openAct=new QAction(tr("Apri file"),this);
    openAct->setShortcuts(QKeySequence::Open);
    connect(openAct,&QAction::triggered,this,&MainWindow::apriFile);
}

void MainWindow::nuovoGrafico()
{
    selezionaTipo=new selectWindow(this);
    selezionaTipo->show();
    connect(selezionaTipo,&selectWindow::creaBarChartSignal,this,&MainWindow::creaBarChart);
    connect(selezionaTipo,&selectWindow::creaLineChartSignal,this,&MainWindow::creaLineChart);
}

bool MainWindow::apriFile()
{
    QString fileName = QFileDialog::getOpenFileName(this,tr("Open Image"), ":/graficisalvati", tr("Json File (*.json)"));
    QFile infile(fileName);
    infile.open(QIODevice::ReadOnly|QIODevice::Text);
     QByteArray saveData = infile.readAll();
     infile.close();
      const QJsonDocument json=QJsonDocument::fromJson(saveData);
        QJsonObject obj = json.object();
     if(obj.contains("Type") && obj["Type"].isString())
     {
         std::string tipo=obj["Type"].toString().toStdString();
         if(tipo=="piechart"){

                creaPieChartFromFile(obj);
                return true;
         }
         else
             return false;

    }


}
void MainWindow::creaBarChart()
{
    barcharttable* bartable=new barcharttable(this,"bartable");
    this->setCentralWidget(bartable);
    bartable->show();
}

void MainWindow::creaLineChart()
{
    LineChartWidget* linechart= new LineChartWidget(this,"linechart");
        this->setCentralWidget(linechart);
        linechart->show();
}

void MainWindow::creaPieChartFromFile(const QJsonObject &json){
    QVector<QVariant> v= json["values"].toArray().toVariantList().toVector();
     QVector<QVariant> v2=json["slices"].toArray().toVariantList().toVector();
     std::vector<int> s;
     std::vector<std::string> s2;
    for(int i=0;i<v.size();++i){
        s.push_back(v.at(i).toInt());
        s2.push_back(v2.at(i).toString().toStdString());
    }
    std::string s3=json["title"].toString().toStdString();
    pie_data* d=new pie_data(s,s2,s3);
    piechartwidget* piechart=new piechartwidget(this,"piechart",d);
    this->setCentralWidget(piechart);
    piechart->show();
}

