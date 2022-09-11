#include "linechartmodel.h"

LineChartModel::LineChartModel(LineChartTableModel * data) :ChartModel(data)
{
    for(int i=0; i < tableModel->columnCount()-1; ++i)
    {
        series.push_back(new QLineSeries);
        mapper.push_back(new QVXYModelMapper());
        mapper[i]->setXColumn(0);
        mapper[i]->setYColumn(i+1);
        mapper[i]->setSeries(series[i]);
        mapper[i]->setModel(tableModel);
        chart->addSeries(series[i]);
        series.at(i)->setName(tableModel->headerData(i+1,Qt::Horizontal,Qt::DisplayRole).toString());
        connect(series.at(i),&QLineSeries::doubleClicked,this,&LineChartModel::cambiaNome);
        connect(series.at(i),&QLineSeries::pointReplaced,this,&LineChartModel::updateAxisY);
    }
    chart->createDefaultAxes();
    chart->setTitle(tableModel->getData()->getTitle());

}
void LineChartModel::updateInsertColumn() {
    int n = tableModel->columnCount()-2;
    series.push_back(new QLineSeries);
    mapper.push_back(new QVXYModelMapper());
    mapper[n]->setXColumn(0);
    mapper[n]->setYColumn(n+1);
    mapper[n]->setSeries(series[n]);
    mapper[n]->setModel(tableModel);
    chart->addSeries(series[n]);
    series.at(n)->setName(tableModel->headerData(n+1,Qt::Horizontal,Qt::DisplayRole).toString());
    updateAxisY();
    connect(series.at(n),&QLineSeries::doubleClicked,this,&LineChartModel::cambiaNome);
    connect(series.at(n),&QLineSeries::pointReplaced,this,&LineChartModel::updateAxisY);
}


void LineChartModel::updateRemoveColumn(int pos) {
    int n = tableModel->columnCount()-1;
    chart->removeSeries(series.at(pos));
    series.removeAt(pos);
    mapper.removeAt(pos);
    for(int i=pos;i<n;++i){
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
                tableModel->setHeaderData(i,Qt::Horizontal,nome,Qt::EditRole);
               series.at(i)->setName(tableModel->headerData(i+1,Qt::Horizontal,Qt::DisplayRole).toString());
            }
        }
    }
}

void LineChartModel::salvaJson(){
    QJsonObject mainObject;
    QJsonObject secondaryObject;
    mainObject.insert(QString::fromStdString("title"),chart->title());
    mainObject.insert(QString::fromStdString("Type"),QString::fromStdString("linechart"));
    QJsonArray names;
    QJsonArray line;

    for(int i=0;i<tableModel->rowCount();++i)
    {
        for(int j=0;j<tableModel->columnCount()-1;++j){
            if(i>0)
                line.pop_front();
            if(i==0)
                names.append(tableModel->headerData(j+1,Qt::Horizontal,Qt::DisplayRole).toString());
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


