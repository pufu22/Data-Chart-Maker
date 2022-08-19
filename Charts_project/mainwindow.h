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
    void creaPieChartFromFile(const QJsonObject &json);
    void creaBarChartFromFile(const QJsonObject &json);
    void creaLineChartFromFile(const QJsonObject &json);
private:
    //CreateChartWidget createchart;
    QMenu* fileMenu;
    QMenu* openMenu;
    QMenu* saveMenu;
    QAction* saveAct;
    QAction* newAct;
    QAction* openAct;
    selectWindow* selezionaTipo;
signals:
    void graficoSalvabile(bool);
    void salvaConNomeSignal();
private slots:
    void nuovoGrafico();
    bool apriFile();
    bool salvaConNome();
public slots:
    void creaBarChart();
    void creaLineChart();

};
#endif // MAINWINDOW_H
