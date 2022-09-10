#include "candlestickchartmodel.h"
#include<iostream>
CandleStickChartModel::CandleStickChartModel(CandleStickChartTableModel* data)
{
    chart=new QChart();
    chart->setAnimationOptions(QChart::AllAnimations);
    candleSeries=new QCandlestickSeries;
    candleSeries->setIncreasingColor(QColor(Qt::green));
    candleSeries->setDecreasingColor(QColor(Qt::red));
    mapper=new QHCandlestickModelMapper;
    mapper->setFirstSetRow(0);
    mapper->setLastSetRow(data->rowCount());
    mapper->setTimestampColumn(0);
    mapper->setOpenColumn(1);
    mapper->setHighColumn(2);
    mapper->setLowColumn(3);
    mapper->setCloseColumn(4);
    mapper->setModel(data);
    mapper->setSeries(candleSeries);
    for(int i=0;i<candleSeries->sets().size();++i){
        categories << QDateTime::fromMSecsSinceEpoch(candleSeries->sets().at(i)->timestamp()).toString("dd.MM.yyyy");
    }
    chart->addSeries(candleSeries);
    chart->createDefaultAxes();
    chart->legend()->hide();
    //candleSeries->setName("Acme Ltd");
    axisX = qobject_cast<QBarCategoryAxis *>(chart->axes(Qt::Horizontal).at(0));
    axisX->setCategories(categories);
    axisY = qobject_cast<QValueAxis *>(chart->axes(Qt::Vertical).at(0));
        axisY->setMax(axisY->max() * 1.01);
        axisY->setMin(axisY->min() * 0.99);
    chart->setTitle(data->dati.getTitle());
    connect(candleSeries,&QCandlestickSeries::candlestickSetsAdded,this,&CandleStickChartModel::updateAxis);
}

int CandleStickChartModel::setsCount(){
    return candleSeries->sets().size();
}

void CandleStickChartModel::updateMapper(){
    mapper->setLastSetRow(mapper->lastSetRow()+1);
    categories<<QDateTime::fromMSecsSinceEpoch(candleSeries->sets().at(mapper->lastSetRow()-1)->timestamp()).toString("dd.MM.yyyy");
    chart->createDefaultAxes();
    axisX = qobject_cast<QBarCategoryAxis *>(chart->axes(Qt::Horizontal).at(0));
    axisX->setCategories(categories);
    axisY = qobject_cast<QValueAxis *>(chart->axes(Qt::Vertical).at(0));
        axisY->setMax(getMax() * 1.01);
        axisY->setMin(getMin() * 0.99);
}

void CandleStickChartModel::updateAxis(){
    chart->createDefaultAxes();
    axisX = qobject_cast<QBarCategoryAxis *>(chart->axes(Qt::Horizontal).at(0));
    axisX->setCategories(categories);
    axisY = qobject_cast<QValueAxis *>(chart->axes(Qt::Vertical).at(0));
        axisY->setMax(getMax()*1.01);
        axisY->setMin(getMin()*0.99);
}
void CandleStickChartModel::updateRemoved(int row){
    mapper->setLastSetRow(mapper->lastSetRow()-1);
    categories.removeAt(row);
    chart->createDefaultAxes();
    axisX = qobject_cast<QBarCategoryAxis *>(chart->axes(Qt::Horizontal).at(0));
    axisX->setCategories(categories);
    axisY = qobject_cast<QValueAxis *>(chart->axes(Qt::Vertical).at(0));
        axisY->setMax(getMax() * 1.01);
        axisY->setMin(getMin() * 0.99);
}
qreal CandleStickChartModel::getMax(){
    qreal max=candleSeries->sets().at(0)->high();
    for(int i=0;i<candleSeries->sets().size();++i){
        if(candleSeries->sets().at(i)->high()>max)
            max=candleSeries->sets().at(i)->high();
    }
    return max;
}

qreal CandleStickChartModel::getMin(){
    qreal min=candleSeries->sets().at(0)->low();
    for(int i=0;i<candleSeries->sets().size();++i){
        if(candleSeries->sets().at(i)->low()<min)
            min=candleSeries->sets().at(i)->low();
    }
    return min;
}

QChart* CandleStickChartModel::getChart(){
    return chart;
}

void CandleStickChartModel::salvaJson(){
    QJsonObject mainObject;
    mainObject.insert(QString::fromStdString("title"),chart->title());
    mainObject.insert(QString::fromStdString("Type"),QString::fromStdString("candlestickchart"));
    QJsonArray timestamps;
    QJsonArray opens;
    QJsonArray highs;
    QJsonArray lows;
    QJsonArray closes;
    QList<QCandlestickSet*>candleSets=candleSeries->sets();
    for(int i=0;i<candleSets.size();++i)
    {
        timestamps.append(candleSets.at(i)->timestamp());
        opens.append(candleSets.at(i)->open());
        highs.append(candleSets.at(i)->high());
        lows.append(candleSets.at(i)->low());
        closes.append(candleSets.at(i)->close());
    }

    mainObject.insert(QString::fromStdString("timestamps"),timestamps);
    mainObject.insert(QString::fromStdString("opens"),opens);
    mainObject.insert(QString::fromStdString("highs"),highs);
    mainObject.insert(QString::fromStdString("lows"),lows);
    mainObject.insert(QString::fromStdString("closes"),closes);

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

void CandleStickChartModel::cambiaTitolo(CandleStickChartTableModel* data,QString t){
    data->dati.setTitle(t);
    chart->setTitle(t);
}
