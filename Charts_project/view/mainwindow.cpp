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
#include<stdio.h>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{

    /*LineChartWidget* linechart= new LineChartWidget();
    this->setCentralWidget(linechart);
    linechart->show();*/
    //bartable->show();

    this->createActions();
    this->createMenus();
    //CandleStickChartWidget* cChart=new CandleStickChartWidget(this);
    //this->setCentralWidget(cChart);
    //cChart->show();
    //AreaChartWidget* areaChart=new AreaChartWidget(this,"areachart");
    //this->setCentralWidget(areaChart);
    //areaChart->show();
    /*piechartwidget* piechart=new piechartwidget(this,"piechart",nullptr);
    this->setCentralWidget(piechart);
    piechart->show();
*/
    this->setMinimumSize(1080,590);
    SelectGraphic* sG=new SelectGraphic(this);
    this->setCentralWidget(sG);
    connect(sG,&SelectGraphic::createChart,this,&MainWindow::creaChart);
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

    SelectGraphic* sG=new SelectGraphic(this);
    this->setCentralWidget(sG);
    connect(sG,&SelectGraphic::createChart,this,&MainWindow::creaChart);
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
             return true;
         }else if(tipo=="linechart"){
            creaLineChartFromFile(obj);
            return true;
         }
         else if(tipo=="candlestickchart")
             creaCandleChartFromFile(obj);
         else if(tipo=="areachart")
             creaAreaChartFromFile(obj);
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
    connect(this,&MainWindow::salvaConNomeSignal,bartable,&barcharttable::salvaJsonBar);
    emit graficoSalvabile(true);
}

void MainWindow::creaLineChart()
{
    LineChartWidget* linechart= new LineChartWidget(nullptr,this,"linechart");
    if(this->centralWidget())
        this->centralWidget()->disconnect();
    this->setCentralWidget(linechart);
        linechart->show();
        connect(this,&MainWindow::salvaConNomeSignal,linechart,&LineChartWidget::salvaJsonFile);
        emit graficoSalvabile(true);

}
void MainWindow::creaPieChart(){
    if(this->centralWidget())
        this->centralWidget()->disconnect();
    piechartwidget* piechart=new piechartwidget(this,"piechart");
    this->setCentralWidget(piechart);
    piechart->show();
    connect(this,&MainWindow::salvaConNomeSignal,piechart,&piechartwidget::salvaJsonPie);
    emit graficoSalvabile(true);
}
void MainWindow::creaAreaChart(){
    if(this->centralWidget())
        this->centralWidget()->disconnect();
    AreaChartWidget* areachart=new AreaChartWidget(this,"piechart");
    this->setCentralWidget(areachart);
    areachart->show();
    connect(this,&MainWindow::salvaConNomeSignal,areachart,&AreaChartWidget::salvaJson);
    emit graficoSalvabile(true);
}
void MainWindow::creaCandleChart(){
    CandleStickChartWidget* candleChart=new CandleStickChartWidget(this);
    this->setCentralWidget(candleChart);
    candleChart->show();
    emit graficoSalvabile(true);
    connect(this,&MainWindow::salvaConNomeSignal,candleChart,&CandleStickChartWidget::salvaJson);
}
void MainWindow::creaPieChartFromFile(const QJsonObject &json){
    if(json.contains("values")&&json.contains("slices")&&json.contains("title")){
        QVector<QVariant> v= json["values"].toArray().toVariantList().toVector();
         QVector<QVariant> v2=json["slices"].toArray().toVariantList().toVector();
         QVector<qreal> s;
         QVector<QString> s2;
        for(int i=0;i<v.size();++i){
            s.push_back(v.at(i).toInt());
            s2.push_back(v2.at(i).toString());
        }
        QString s3=json["title"].toString();
        if(s.size()==s2.size()){
            pie_data* d=new pie_data(s,s2,s3);
            piechartwidget* piechart=new piechartwidget(this,"piechart",d);
            this->setCentralWidget(piechart);
            piechart->show();
            emit graficoSalvabile(true);
            connect(this,&MainWindow::salvaConNomeSignal,piechart,&piechartwidget::salvaJsonPie);
        }    else {
            qWarning("File JSON non valido");
            QMessageBox::warning(this,"File","File non valido",QMessageBox::Ok);
        }

    }    else {
        qWarning("File JSON non valido");
        QMessageBox::warning(this,"File","File non valido",QMessageBox::Ok);
    }

}

void MainWindow::creaBarChartFromFile(const QJsonObject &json){
    if(json.contains("title")&&json.contains("bars")&&json.contains("names"))
    {
        int sizeFirst=0;
        bool sizesCoherent=true;
        QString tempString =json["title"].toString();
        QJsonObject tempA =json["bars"].toObject();
        QVector<QVariant> v= json["names"].toArray().toVariantList().toVector();
        QVector<QVector<qreal>> s;
        QVector<QString> s2;
        QVector<QString> s3;
        int j=0;
        for(int i=0;i<v.size();++i){
            s3.push_back(v.at(i).toString());
        }
        foreach(const QString& key, tempA.keys()) {
                s2.push_back(key);
               QJsonValue value = tempA.value(key);
               QJsonArray a=value.toArray();
               QVector<qreal> n2;
               for(int i=0;i<a.size();++i)
               {
                    n2.push_back(a.at(i).toInt());
               }
               if(sizeFirst==0)
                   sizeFirst=n2.size();
               else
                   if(n2.size()!=sizeFirst)
                       sizesCoherent=false;
               s.push_back(n2);
               ++j;
        }
    if(sizesCoherent&&sizeFirst==s3.size()){
        Bar_data* d=new Bar_data(s,tempString,s2,s3);
        barcharttable* barchart=new barcharttable(d);
        this->setCentralWidget(barchart);
        barchart->show();
        connect(this,&MainWindow::salvaConNomeSignal,barchart,&barcharttable::salvaJsonBar);
        emit graficoSalvabile(true);
    }
    else {
        qWarning("File JSON non valido");
        QMessageBox::warning(this,"File","File non valido",QMessageBox::Ok);
    }
    }
    else {
        qWarning("File JSON non valido");
        QMessageBox::warning(this,"File","File non valido",QMessageBox::Ok);
    }

}

void MainWindow::creaLineChartFromFile(const QJsonObject &json)
{

    if(json.contains("title")&&json.contains("series")&&json.contains("names"))
    {
        int sizeFirst=0;
        bool sizesCoherent=true;
        QJsonObject tempA =json["series"].toObject();
        QVector<QVariant> v= json["names"].toArray().toVariantList().toVector();
        QVector<QString> s3;
        for(int i=0;i<v.size();++i){
            s3.push_back(v.at(i).toString());
        }
        QVector<QVector<qreal>> s;
        foreach(const QString& key, tempA.keys()) {
               QJsonValue value = tempA.value(key);

               QJsonArray a=value.toArray();
               QVector<qreal> n2;
               n2.push_back(key.toInt());
               for(int i=0;i<a.size();++i)
               {
                    n2.push_back(a.at(i).toInt());
               }
               if(sizeFirst==0)
                   sizeFirst=n2.size();
               else if(n2.size()!=sizeFirst)
                   sizesCoherent=false;
               s.push_back(n2);
        }
        if(sizesCoherent && sizeFirst-1==s3.size())
        {
            LineChartData* d=new LineChartData(s,json["title"].toString(),s3);
            LineChartWidget* linechart=new LineChartWidget(d);
            this->setCentralWidget(linechart);
            linechart->show();
            connect(this,&MainWindow::salvaConNomeSignal,linechart,&LineChartWidget::salvaJsonFile);
            emit graficoSalvabile(true);
        }    else {
            qWarning("File JSON non valido");
            QMessageBox::warning(this,"File","File non valido",QMessageBox::Ok);
        }

    }    else {
        qWarning("File JSON non valido");
        QMessageBox::warning(this,"File","File non valido",QMessageBox::Ok);
    }

}

void MainWindow::creaCandleChartFromFile(const QJsonObject &json){
    if(json.contains("title") && json.contains("timestamps") && json.contains("opens") && json.contains("highs") &&
            json.contains("lows") && json.contains("closes"))
    {
        QString title=json["title"].toString();
        QVector<QVariant>timestamps= json["timestamps"].toArray().toVariantList().toVector();
        QVector<QVariant>opens= json["opens"].toArray().toVariantList().toVector();
        QVector<QVariant>highs= json["highs"].toArray().toVariantList().toVector();
        QVector<QVariant>lows= json["lows"].toArray().toVariantList().toVector();
        QVector<QVariant>closes= json["closes"].toArray().toVariantList().toVector();
        QVector<qreal> t;
        QVector<qreal> o;
        QVector<qreal> h;
        QVector<qreal> l;
        QVector<qreal> c;

        for(int i=0;i<timestamps.size();++i){
            t.push_back(timestamps.at(i).toReal());
            o.push_back(opens.at(i).toReal());
            h.push_back(highs.at(i).toReal());
            l.push_back(lows.at(i).toReal());
            c.push_back(closes.at(i).toReal());
        }
        if(t.size()==o.size()==h.size()==l.size()==c.size()){
            CandleStickData* candleData=new CandleStickData(t,o,c,h,l,title);
            CandleStickChartWidget* candleWidget=new CandleStickChartWidget(this,candleData);
            this->setCentralWidget(candleWidget);
            candleWidget->show();
            emit graficoSalvabile(true);
            connect(this,&MainWindow::salvaConNomeSignal,candleWidget,&CandleStickChartWidget::salvaJson);
        }    else {
            qWarning("File JSON non valido");
            QMessageBox::warning(this,"File","File non valido",QMessageBox::Ok);
        }
    }    else {
        qWarning("File JSON non valido");
        QMessageBox::warning(this,"File","File non valido",QMessageBox::Ok);
    }


}
void MainWindow::creaAreaChartFromFile(const QJsonObject &json){
    if(json.contains("lines")&&json.contains("areanames")&&json.contains("title"))
    {
        int sizeFirst=0;
        bool sizesCoherent=true;
        QJsonObject tempA =json["lines"].toObject();
        QVector<QVariant> v= json["areanames"].toArray().toVariantList().toVector();
        QVector<QString> s3;
        for(int i=0;i<v.size();++i){
            s3.push_back(v.at(i).toString());
        }
        QVector<QVector<qreal>> s;
        foreach(const QString& key, tempA.keys()) {
               QJsonValue value = tempA.value(key);

               QJsonArray a=value.toArray();
               QVector<qreal> n2;
               n2.push_back(key.toInt());
               for(int i=0;i<a.size();++i)
               {
                    n2.push_back(a.at(i).toInt());
               }
               if(sizeFirst==0)
                   sizeFirst=n2.size();
               else
                   if(n2.size()!=sizeFirst)
                        sizesCoherent=false;
               s.push_back(n2);
        }
        if(sizesCoherent && sizeFirst-1==s3.size())
        {
            AreaChartData* d=new AreaChartData(s,json["title"].toString(),s3);
            AreaChartWidget* areachart=new AreaChartWidget(this,"AreaChart",d);
            this->setCentralWidget(areachart);
            areachart->show();
            connect(this,&MainWindow::salvaConNomeSignal,areachart,&AreaChartWidget::salvaJson);
            emit graficoSalvabile(true);
        }    else {
            qWarning("File JSON non valido");
            QMessageBox::warning(this,"File","File non valido",QMessageBox::Ok);
        }

    }    else {
        qWarning("File JSON non valido");
        QMessageBox::warning(this,"File","File non valido",QMessageBox::Ok);
    }

}

void MainWindow::creaChart(QString name){

     if(name.compare("PieChart")==0)
        creaPieChart();
     if(name.compare("AreaChart")==0)
         creaAreaChart();
     if(name.compare("BarChart")==0)
         creaBarChart();
     if(name.compare("LineChart")==0)
         creaLineChart();
     if(name.compare("CandleChart")==0)
         creaCandleChart();
}

