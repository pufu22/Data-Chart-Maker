#include "piechartmodel.h"

piechartmodel::piechartmodel(Piecharttablemodel* data)
{
    chart=new QChart;
    chart->setAnimationOptions(QChart::AllAnimations);
    pieSeries=new QPieSeries;
    piemapper=new QVPieModelMapper();
    piemapper->setSeries(pieSeries);
    piemapper->setLabelsColumn(0);
    piemapper->setValuesColumn(1);
    piemapper->setModel(data);
    chart->addSeries(pieSeries);

    for(int i=0;i<pieSeries->slices().size();++i){
        QPieSlice* slice=pieSeries->slices().at(i);
        connect(slice,&QPieSlice::hovered,this, &piechartmodel::explodeSplice);
    }

    title=data->dati.getTitle();
    chart->createDefaultAxes();
    chart->setTitle(title);

}

void piechartmodel::explodeSplice(bool state){
    QObject* obj=sender();
    for(int i=0;i<pieSeries->slices().size();++i){
        QPieSlice* slice=pieSeries->slices().at(i);
        if(obj==slice){
            slice->setExploded(state);
            slice->setLabelVisible(state);
            break;
        }
    }
}
void piechartmodel::connectInsertedSlice(){
    QPieSlice* slice=pieSeries->slices().at(pieSeries->slices().size()-1);
    connect(slice,&QPieSlice::hovered,this, &piechartmodel::explodeSplice);

}

int piechartmodel::sliceCount(){
    return pieSeries->slices().size();
}
void piechartmodel::mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event){


}
void piechartmodel::salvaJsonPie(){
    QJsonObject mainObject;
    mainObject.insert(QString::fromStdString("title"),title);
    mainObject.insert(QString::fromStdString("Type"),QString::fromStdString("piechart"));
    QJsonArray labels;
    QJsonArray values;
    QList<QPieSlice*>temp=pieSeries->slices();
    for(int i=0;i<temp.size();++i)
    {
        labels.append(temp.at(i)->label());
        values.append(temp.at(i)->value());
    }

    mainObject.insert(QString::fromStdString("slices"),labels);
    mainObject.insert(QString::fromStdString("values"),values);

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
