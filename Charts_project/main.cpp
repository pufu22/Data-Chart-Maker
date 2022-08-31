#include "view/mainwindow.h"

#include <QApplication>
#include<QChartView>
#include<model/barchart_model.h>
using namespace QtCharts;
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    /*std::vector<std::vector<int>> sets={{ 1 , 2 , 3 , 4 , 5 , 6},{5,0,0,4,0,7},{3,5,8,13,8,5},{5,6,7,3,4,5},{9,7,5,3,1,2}};
    std::list<std::string> cat={"Jan", "Feb", "Mar", "Apr", "May", "Jun"};
    int range[2]={0,15};
    Bar_data *data=new Bar_data(sets,"prova",cat,range);
    BarChartModel *chart= new BarChartModel(*data);
    QChartView *chartView = new QChartView(chart->chart);
    chartView->setRenderHint(QPainter::Antialiasing);
    w.setCentralWidget(chartView);*/
    w.setWindowState(Qt::WindowMaximized);
    //w.createMenus();
    w.show();
    return a.exec();
}
