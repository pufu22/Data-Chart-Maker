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

    chart->createDefaultAxes();
    chart->setTitle(QString::fromStdString(data->dati.title));
}
