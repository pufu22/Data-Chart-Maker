#include "areachartmodel.h"
#include"stdio.h"
AreaChartModel::AreaChartModel(QAbstractTableModel* data)
{
    dati=data;
    chart=new QChart;
    chart->setAnimationOptions(QChart::AllAnimations);
    nLines=0;
    for(int i=0;i<data->columnCount()-1;++i){
        linesmappers.push_back(new QVXYModelMapper);
        linesmappers[i]->setXColumn(0);
        linesmappers[i]->setYColumn(i+1);
        linesmappers[i]->setFirstRow(0);
        linesmappers[i]->setModel(dati);
        series.push_back(new QLineSeries);
        linesmappers[i]->setSeries(series[i]);
        if(i==0)
            areaSeries.push_back(new QAreaSeries(series.at(0)));
        else
            areaSeries.push_back(new QAreaSeries(series.at(i),series.at(i-1)));
        areaSeries.at(i)->setName(dati->headerData(i+1,Qt::Horizontal,Qt::DisplayRole).toString());
        chart->addSeries(areaSeries.at(i));
        nLines++;
        connect(areaSeries.at(i),&QAreaSeries::doubleClicked,this,&AreaChartModel::cambiaNome);
        connect(linesmappers.at(i)->series(),&QLineSeries::pointReplaced,this,&AreaChartModel::updateAxisY);
    }
    chart->createDefaultAxes();
    QValueAxis *axisY = qobject_cast<QValueAxis *>(chart->axes(Qt::Vertical).at(0));
    axisY->setMax(axisY->max() * 1.01);
    axisY->setMin(axisY->min() * 0.99);
    //chart->setTitle(dati->dati->getTitle());
}

void AreaChartModel::salvaJson(){
    QJsonObject mainObject;
    QJsonObject secondaryObject;
    mainObject.insert(QString::fromStdString("title"),chart->title());
    mainObject.insert(QString::fromStdString("Type"),QString::fromStdString("areachart"));
    QJsonArray areanames;
    QJsonArray lines;

    for(int i=0;i<dati->rowCount();++i)
    {
        for(int j=0;j<dati->columnCount()-1;++j){
            if(i>0)
                lines.pop_front();
            if(i==0)
                areanames.append(dati->headerData(j+1,Qt::Horizontal,Qt::DisplayRole).toString());
            lines.append(series.at(j)->at(i).y());
        }
        secondaryObject.insert(QString::fromStdString(std::to_string(i)),lines);

    }
    mainObject.insert(QString::fromStdString("lines"),secondaryObject);
    mainObject.insert(QString::fromStdString("areanames"),areanames);

    QJsonDocument document;
    document.setObject( mainObject );
    bool ok;
    QString nomeFile=QInputDialog::getText(nullptr,tr("Salva con nome:"),tr("Nome file:"),QLineEdit::Normal,QDir::home().dirName(),&ok);

    QFile file( "../Charts_project/graficisalvati/"+nomeFile+".json");
    if(file.open( QIODevice::WriteOnly))
    {
        file.write(document.toJson());
               //return false;
    }
    else
            qWarning("Couldn't open save file.");
}
void AreaChartModel::updateMappers()
{
    int temp=nLines++;
    series.push_back(new QLineSeries);
    linesmappers.push_back(new QVXYModelMapper);
    linesmappers[temp]->setXColumn(0);
    linesmappers[temp]->setYColumn(temp+1);
    linesmappers[temp]->setFirstRow(0);
    linesmappers[temp]->setModel(dati);
    linesmappers[temp]->setSeries(series[temp]);
        areaSeries.push_back(new QAreaSeries(series.at(temp),series.at(temp-1)));
        chart->addSeries(areaSeries.at(temp));
    areaSeries.at(temp)->setName(dati->headerData(temp+1,Qt::Horizontal,Qt::DisplayRole).toString());
    chart->createDefaultAxes();
    connect(areaSeries.at(temp),&QAreaSeries::doubleClicked,this,&AreaChartModel::cambiaNome);
    connect(linesmappers.at(temp)->series(),&QLineSeries::pointReplaced,this,&AreaChartModel::updateAxisY);
}

void AreaChartModel::updateRemoved(int pos){
    int temp=--nLines;
    chart->removeSeries(areaSeries.at(pos));
    series.removeAt(pos);
    linesmappers.removeAt(pos);
    areaSeries.removeAt(pos);
        for(int i=pos;i<temp;++i){
            linesmappers[i]->setXColumn(0);
            linesmappers[i]->setYColumn(i+1);
        }
    if(pos!=temp&&pos!=0)
    areaSeries.at(pos)->setLowerSeries(series.at(pos-1));
    if(pos==0){
        areaSeries.at(0)->setUpperSeries(series.at(0));
        areaSeries.at(0)->setLowerSeries(Q_NULLPTR);
    }
    if(pos!=0)
    areaSeries.at(pos-1)->setUpperSeries(series.at(pos-1));
}

QChart* AreaChartModel::getChart(){
    return chart;
}
int AreaChartModel::getMax(){
    qreal max=0;
    for(int i=0;i<series.size();++i){
        for(int j=0;j<series.at(i)->points().size();++j)
        {
            qreal y=series.at(i)->points()[j].ry();
            if(y>max)
                max=y;
        }
    }
    return max;
}

int AreaChartModel::getMin(){
    qreal min=0;
    for(int i=0;i<series.size();++i){
        for(int j=0;j<series.at(i)->points().size();++j)
        {
            qreal y=series.at(i)->points()[j].ry();
            if(y<min)
                min=y;
        }
    }
    return min;
}

void AreaChartModel::updateAxisY(){
    chart->createDefaultAxes();
    chart->axisY()->setRange(getMin(),getMax());
    chart->axisX()->setRange(0,dati->rowCount()-1);
}

void AreaChartModel::changeTitle(QString title){
    //dati->dati->setTitle(title);
    chart->setTitle(title);
}

void AreaChartModel::cambiaNome(){
    QObject* obj=sender();
    for(int i=0;i<areaSeries.size();++i){
        QAreaSeries* areaserie=areaSeries.at(i);
        if(obj==areaserie){
            bool ok;
            QString nome=QInputDialog::getText(nullptr,tr("Nome"),tr("Nome:"),QLineEdit::Normal,tr(""),&ok);
            if(ok && nome.trimmed()!=""){
                dati->setHeaderData(i,Qt::Horizontal,nome,Qt::EditRole);
               areaSeries.at(i)->setName(dati->headerData(i+1,Qt::Horizontal,Qt::DisplayRole).toString());
            }
        }
    }
}
