#include "mainwindow.h"
#include "CreateChartWidget.h"
#include<QChartView>
#include<qchartview.h>
#include<QChart>
#include <QAction>
#include <QMenuBar>
#include <QMenu>
#include <view/barcharttable.h>
#include<view/piechartwidget.h>
#include<view/areachartwidget.h>
#include <view/selectGraphic.h>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{

    //LineChartWidget* linechart= new LineChartWidget(this,"linechart");
    //this->setCentralWidget(linechart);
    //linechart->show();
    //bartable->show();

    this->createActions();
    this->createMenus();
    //AreaChartWidget* areaChart=new AreaChartWidget(this,"areachart");
    //this->setCentralWidget(areaChart);
    //areaChart->show();
    //piechartwidget* piechart=new piechartwidget(this,"piechart",nullptr);
    //this->setCentralWidget(piechart);
    //piechart->show();
    this->setCentralWidget(new SelectGraphic(this));

}

MainWindow::~MainWindow()
{

}

void MainWindow::createMenus()
  {
       fileMenu = menuBar()->addMenu(tr("&File"));
       openMenu = menuBar()->addMenu(tr("&Open"));
       fileMenu->addAction(newAct);
       fileMenu->addAction(saveAct);
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
    saveAct=new QAction(tr("Salva con nome"),this);
    saveAct->setShortcuts(QKeySequence::SaveAs);
    saveAct->setEnabled(false);
    connect(saveAct,&QAction::triggered,this,&MainWindow::salvaConNome);
     connect(this,&MainWindow::graficoSalvabile,saveAct,&QAction::setEnabled);
}

void MainWindow::nuovoGrafico()
{
    selezionaTipo=new selectWindow(this);
    selezionaTipo->setFocus();
    selezionaTipo->setModal(true);
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
         else if(tipo=="barchart"){
             creaBarChartFromFile(obj);
         }else if(tipo=="linechart"){
            creaLineChartFromFile(obj);
         }
         else
             return false;

    }


}

bool MainWindow::salvaConNome(){
emit salvaConNomeSignal();
}

void MainWindow::creaBarChart()
{
    barcharttable* bartable=new barcharttable(nullptr,this,"bartable");
    if(this->centralWidget())
        this->centralWidget()->disconnect();
    this->setCentralWidget(bartable);
    bartable->show();
    emit graficoSalvabile(true);
}

void MainWindow::creaLineChart()
{
    LineChartWidget* linechart= new LineChartWidget(nullptr,this,"linechart");
        this->setCentralWidget(linechart);
        linechart->show();
        emit graficoSalvabile(true);

}

void MainWindow::creaPieChartFromFile(const QJsonObject &json){
    QVector<QVariant> v= json["values"].toArray().toVariantList().toVector();
     QVector<QVariant> v2=json["slices"].toArray().toVariantList().toVector();
     QVector<int> s;
     QVector<QString> s2;
    for(int i=0;i<v.size();++i){
        s.push_back(v.at(i).toInt());
        s2.push_back(v2.at(i).toString());
    }
    QString s3=json["title"].toString();
    pie_data* d=new pie_data(s,s2,s3);
    piechartwidget* piechart=new piechartwidget(this,"piechart",d);
    this->setCentralWidget(piechart);
    piechart->show();
    emit graficoSalvabile(true);
    connect(this,&MainWindow::salvaConNomeSignal,piechart,&piechartwidget::salvaJsonPie);
}

void MainWindow::creaBarChartFromFile(const QJsonObject &json){
QString tempString =json["title"].toString();
QJsonObject tempA =json["bars"].toObject();
QVector<QVector<int>> s;
QVector<QString> s2;
int j=0;
foreach(const QString& key, tempA.keys()) {
        s2.push_back(key);
       QJsonValue value = tempA.value(key);
       QJsonArray a=value.toArray();
       QVector<int> n2;
       for(int i=0;i<a.size();++i)
       {
            n2.push_back(a.at(i).toInt());
       }
       s.push_back(n2);
       ++j;
}
int minVal;
int maxVal;
//Bar_data* d=new Bar_data(s,tempString,s2,minVal,maxVal);
//barcharttable* barchart=new barcharttable(d);
//this->setCentralWidget(barchart);
//barchart->show();
//emit graficoSalvabile(true);
}

void MainWindow::creaLineChartFromFile(const QJsonObject &json)
{
    std::string tempString =json["title"].toString().toStdString();
    QJsonObject tempA =json["series"].toObject();
    QVector<QVector<int>> s;
    foreach(const QString& key, tempA.keys()) {
           QJsonValue value = tempA.value(key);
           QJsonArray a=value.toArray();
           QVector<int> n2;
           for(int i=0;i<a.size();++i)
           {
                n2.push_back(a.at(i).toInt());
           }
           s.push_back(n2);
    }
    LineChartData* d=new LineChartData(s,json["title"].toString());
    LineChartWidget* linechart=new LineChartWidget(d);
    this->setCentralWidget(linechart);
    linechart->show();
    emit graficoSalvabile(true);
}
