#include "linechartmodel.h"

LineChartModel::LineChartModel(LineChartTableModel * data)
{
    chart=new QChart;
    chart->setAnimationOptions(QChart::AllAnimations);
    series.push_back(new QLineSeries);
    nLines=1;
    mapper.push_back(new QVXYModelMapper());
    mapper[0]->setXColumn(0);
    mapper[0]->setYColumn(1);
    mapper[0]->setSeries(series[0]);
    mapper[0]->setModel(data);
    chart->addSeries(series[0]);
    chart->createDefaultAxes();

    chart->setTitle(title);
    series.at(0)->setName(data->dati->getLineName(0));
}

void LineChartModel::updateMapper(LineChartTableModel * data){
    int temp=nLines++;
        series.push_back(new QLineSeries);
        mapper.push_back(new QVXYModelMapper());
        mapper[temp]->setXColumn(0);
        mapper[temp]->setYColumn(temp+1);
        mapper[temp]->setSeries(series[temp]);
        mapper[temp]->setModel(data);
        chart->addSeries(series[temp]);
        series.at(temp)->setName(data->dati->getLineName(temp));
    updateAxisY();
}

void LineChartModel::updateAxises(){
    chart->createDefaultAxes();
}

void LineChartModel::axises(int maxValue){
    this->updateAxises();
}

void LineChartModel::salvaJsonFile(){
    QJsonObject mainObject;
    mainObject.insert(QString::fromStdString("title"),title);
    mainObject.insert(QString::fromStdString("Type"),QString::fromStdString("linechart"));

}

void LineChartModel::updateAxisY(){
    chart->createDefaultAxes();
    chart->axisY()->setRange(getMin(),getMax()+1);
}

void LineChartModel::addLinea(LineChartTableModel *data,QString l){
    data->dati->addLineName(l);
}
QChart* LineChartModel::getChart(){
    return chart;
}

int LineChartModel::getMax(){
    int max=0;
    for(int i=0;i<series.size();++i){
        for(int j=0;j<series.at(i)->points().size();++j)
        {
            qreal y=series.at(i)->points().at(j).y();
            if(y>max)
                max=y;
        }
    }
    return max;
}

int LineChartModel::getMin(){
    int min=0;
    for(int i=0;i<series.size();++i){
        for(int j=0;j<series.at(i)->points().size();++j)
        {
            qreal y=series.at(i)->points().at(j).y();
            if(y<min)
                min=y;
        }
    }
    return min;
}


