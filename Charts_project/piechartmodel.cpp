#include "piechartmodel.h"

piechartmodel::piechartmodel(Piecharttablemodel* data)
{
    chart=new QChart;
    chart->setAnimationOptions(QChart::AllAnimations);
    pieSeries=new QPieSeries;
    piemapper=new QVPieModelMapper;
    piemapper->setSeries(pieSeries);
    piemapper->setLabelsColumn(0);
    piemapper->setValuesColumn(1);
    piemapper->setModel(data);
    chart->addSeries(pieSeries);

    for(int i=0;i<pieSeries->slices().size();++i){
        QPieSlice* slice=pieSeries->slices().at(i);
        connect(slice,&QPieSlice::hovered,this, &piechartmodel::explodeSplice);
    }

    chart->createDefaultAxes();
    chart->setTitle(QString::fromStdString(data->dati.title));

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
