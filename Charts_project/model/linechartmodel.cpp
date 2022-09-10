#include "linechartmodel.h"

LineChartModel::LineChartModel(LineChartTableModel * data)
{
    dati=data;
    chart=new QChart;
    chart->setAnimationOptions(QChart::AllAnimations);
    nLines=0;
    for(int i=0;i<data->columnCount()-1;++i)
    {
        series.push_back(new QLineSeries);
        mapper.push_back(new QVXYModelMapper());
        mapper[i]->setXColumn(0);
        mapper[i]->setYColumn(i+1);
        mapper[i]->setSeries(series[i]);
        mapper[i]->setModel(data);
        chart->addSeries(series[i]);
        series.at(i)->setName(dati->headerData(i+1,Qt::Horizontal,Qt::DisplayRole).toString());
        connect(series.at(i),&QLineSeries::doubleClicked,this,&LineChartModel::cambiaNome);
        nLines++;
    }
    chart->createDefaultAxes();
    chart->setTitle(dati->dati->getTitle());


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
        series.at(temp)->setName(dati->headerData(temp+1,Qt::Horizontal,Qt::DisplayRole).toString());
        updateAxisY();
        connect(series.at(temp),&QLineSeries::doubleClicked,this,&LineChartModel::cambiaNome);
}

void LineChartModel::updateRemoved(int pos){
    int temp=--nLines;
    chart->removeSeries(series.at(pos));
    series.removeAt(pos);
    mapper.removeAt(pos);
        for(int i=pos;i<temp;++i){
            mapper[i]->setXColumn(i);
            mapper[i]->setYColumn(i+1);
        }
}
void LineChartModel::cambiaNome(){
    QObject* obj=sender();
    for(int i=0;i<series.size();++i){
        QLineSeries* lineseries=series.at(i);
        if(obj==lineseries){
            bool ok;
            QString nome=QInputDialog::getText(nullptr,tr("Nome"),tr("Nome:"),QLineEdit::Normal,tr(""),&ok);
            if(ok && nome.trimmed()!=""){
                dati->setHeaderData(i,Qt::Horizontal,nome,Qt::EditRole);
               series.at(i)->setName(dati->headerData(i+1,Qt::Horizontal,Qt::DisplayRole).toString());
            }
        }
    }
}
void LineChartModel::updateAxises(){
    chart->createDefaultAxes();
}

void LineChartModel::axises(int maxValue){
    this->updateAxises();
}

void LineChartModel::salvaJsonFile(){
    QJsonObject mainObject;
    QJsonObject secondaryObject;
    mainObject.insert(QString::fromStdString("title"),chart->title());
    mainObject.insert(QString::fromStdString("Type"),QString::fromStdString("linechart"));
    QJsonArray names;
    QJsonArray line;

    for(int i=0;i<dati->rowCount();++i)
    {
        for(int j=0;j<dati->columnCount()-1;++j){
            if(i>0)
                line.pop_front();
            if(i==0)
                names.append(dati->headerData(j+1,Qt::Horizontal,Qt::DisplayRole).toString());
            line.append(series.at(j)->at(i).y());
        }
        secondaryObject.insert(QString::fromStdString(std::to_string(i)),line);

    }
    mainObject.insert(QString::fromStdString("series"),secondaryObject);
    mainObject.insert(QString::fromStdString("names"),names);

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

void LineChartModel::updateAxisY(){
    chart->createDefaultAxes();
    chart->axisY()->setRange(getMin(),getMax()+1);
    chart->axisX()->setRange(0,series.at(0)->count()-1);
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

void LineChartModel::removeLine(int pos){
    series.removeAt(pos);
}

void LineChartModel::cambiaTitolo(LineChartTableModel* data,QString t){
    data->dati->setTitle(t);
    chart->setTitle(t);
}

