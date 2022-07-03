#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <CreateChartWidget.h>
#include<QChartView>
#include<QChart>
#include<QMenu>
#include<linechartwidget.h>
#include<selectwindow.h>
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void createMenus();
    void createActions();

private:
    //CreateChartWidget createchart;
    QMenu* fileMenu;
    QMenu* editMenu;
    QAction* newAct;
    selectWindow* selezionaTipo;
private slots:
    void nuovoGrafico();
public slots:
    void creaBarChart();
    void creaLineChart();
};
#endif // MAINWINDOW_H
