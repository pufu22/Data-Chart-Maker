#include "areachartmodel.h"

AreaChartModel::AreaChartModel(AreaChartTableModel* data) : ChartModel(data) {
    for(int i=0;i<tableModel->columnCount()-1;++i){
        linesmappers.push_back(new QVXYModelMapper);
        linesmappers[i]->setXColumn(0);
        linesmappers[i]->setYColumn(i+1);
        linesmappers[i]->setFirstRow(0);
        linesmappers[i]->setModel(tableModel);
        series.push_back(new QLineSeries);
        linesmappers[i]->setSeries(series[i]);
        if(i==0)
            areaSeries.push_back(new QAreaSeries(series.at(0)));
        else
            areaSeries.push_back(new QAreaSeries(series.at(i),series.at(i-1)));
        areaSeries.at(i)->setName(tableModel->headerData(i+1,Qt::Horizontal,Qt::DisplayRole).toString());
        chart->addSeries(areaSeries.at(i));
        connect(areaSeries.at(i),&QAreaSeries::doubleClicked,this,&AreaChartModel::cambiaNome);
    }
    chart->createDefaultAxes();
    QValueAxis *axisY = qobject_cast<QValueAxis *>(chart->axes(Qt::Vertical).at(0));
    axisY->setMax(axisY->max() * 1.01);
    axisY->setMin(axisY->min() * 0.99);
    chart->setTitle(tableModel->getData()->getTitle());
}

void AreaChartModel::updateInsertColumn() {
    int n = tableModel->columnCount()-2;
    series.push_back(new QLineSeries);
    linesmappers.push_back(new QVXYModelMapper);
    linesmappers[n]->setXColumn(0);
    linesmappers[n]->setYColumn(n+1);
    linesmappers[n]->setFirstRow(0);
    linesmappers[n]->setModel(tableModel);
    linesmappers[n]->setSeries(series[n]);
    areaSeries.push_back(new QAreaSeries(series.at(n),series.at(n-1)));
    chart->addSeries(areaSeries.at(n));
    areaSeries.at(n)->setName(tableModel->headerData(n+1,Qt::Horizontal,Qt::DisplayRole).toString());
    chart->createDefaultAxes();
    connect(areaSeries.at(n),&QAreaSeries::doubleClicked,this,&AreaChartModel::cambiaNome);
}

void AreaChartModel::updateRemoveColumn(int pos) {
    int n = tableModel->columnCount()-1;
    chart->removeSeries(areaSeries.at(pos));
    series.removeAt(pos);
    linesmappers.removeAt(pos);
    areaSeries.removeAt(pos);
        for(int i=pos; i<n; ++i){
            linesmappers[i]->setXColumn(0);
            linesmappers[i]->setYColumn(i+1);
        }
    if(pos != n && pos != 0)
    areaSeries.at(pos)->setLowerSeries(series.at(pos-1));
    if(pos == 0){
        areaSeries.at(0)->setUpperSeries(series.at(0));
        areaSeries.at(0)->setLowerSeries(Q_NULLPTR);
    }
    if(pos != 0)
    areaSeries.at(pos-1)->setUpperSeries(series.at(pos-1));
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
    chart->axisX()->setRange(0,tableModel->rowCount()-1);
}

void AreaChartModel::cambiaNome(){
    QObject* obj=sender();
    for(int i=0;i<areaSeries.size();++i){
        QAreaSeries* areaserie=areaSeries.at(i);
        if(obj==areaserie){
            bool ok;
            QString nome=QInputDialog::getText(nullptr,tr("Nome"),tr("Nome:"),QLineEdit::Normal,tr(""),&ok);
            if(ok && nome.trimmed()!=""){
                tableModel->setHeaderData(i,Qt::Horizontal,nome,Qt::EditRole);
               areaSeries.at(i)->setName(tableModel->headerData(i+1,Qt::Horizontal,Qt::DisplayRole).toString());
            }
        }
    }
}

void AreaChartModel::salvaJson(){
    QJsonObject mainObject;
    QJsonObject secondaryObject;
    mainObject.insert(QString::fromStdString("title"),chart->title());
    mainObject.insert(QString::fromStdString("Type"),QString::fromStdString("areachart"));
    QJsonArray areanames;
    QJsonArray lines;

    for(int i=0;i<tableModel->rowCount();++i)
    {
        for(int j=0;j<tableModel->columnCount()-1;++j){
            if(i>0)
                lines.pop_front();
            if(i==0)
                areanames.append(tableModel->headerData(j+1,Qt::Horizontal,Qt::DisplayRole).toString());
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

