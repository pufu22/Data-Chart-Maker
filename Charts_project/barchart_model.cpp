#include "barchart_model.h"
#include <bar_data.h>
#include<QStringList>
#include<QString>
#include<iostream>
BarChartModel::BarChartModel(Bar_data data)
{
        QBarSeries *series = new QBarSeries();
        for(unsigned int i=0;i<data.sets.size(); ++i){
            QBarSet *set=new QBarSet("prova");
                for(int j=0;j<data.sets[i].size();++j){
                    std::cout<< data.sets[i].size();
                    std::cout<<data.sets[i].at(j);
                    *set<<data.sets[i].at(j);
                }
                series->append(set);
            }
        chart = new QChart();
          chart->addSeries(series);
          QString qstr = QString::fromStdString(data.title);
          chart->setTitle(qstr);
          chart->setAnimationOptions(QChart::SeriesAnimations);
        QStringList categ;
        for(std::list<std::string>::iterator it=data.categories.begin();it!=data.categories.end();++it){
            QString qstr = QString::fromStdString(*it);
            categ<<qstr;
        }
        QBarCategoryAxis *axisX = new QBarCategoryAxis();
        axisX->append(categ);
            chart->addAxis(axisX, Qt::AlignBottom);
            series->attachAxis(axisX);

            QValueAxis   *axisY = new QValueAxis();
            axisY->setRange(0,15);
            chart->addAxis(axisY, Qt::AlignLeft);
            series->attachAxis(axisY);
            chart->legend()->setVisible(true);
               chart->legend()->setAlignment(Qt::AlignBottom);

};
