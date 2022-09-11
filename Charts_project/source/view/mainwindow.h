#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "areachartwidget.h"
#include "barcharttable.h"
#include "candlestickchartwidget.h"
#include "linechartwidget.h"
#include "piechartwidget.h"
#include <source/widget/selectGraphic.h>

// è una view specializzata per la finestra principale dell'applicazione (il cornicione sul quale verrà visualizzato il resto).
class MainWindow : public QMainWindow
{
    Q_OBJECT
private:
    QMenu* fileMenu;
    QMenu* openMenu;
    QMenu* saveMenu;
    QAction* saveAct;
    QAction* newAct;
    QAction* openAct;
public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void createMenus();
    void createActions();
    void creaPieChartFromFile(const QJsonObject &json);
    void creaBarChartFromFile(const QJsonObject &json);
    void creaLineChartFromFile(const QJsonObject &json);
    void creaCandleChartFromFile(const QJsonObject &json);
private slots:
    void nuovoGrafico();
    bool apriFile();
    bool salvaConNome();
public slots:
    void creaChart(QString name);
    void creaBarChart();
    void creaLineChart();
    void creaPieChart();
    void creaAreaChart();
    void creaCandleChart();
signals:
    void graficoSalvabile(bool);
    void salvaConNomeSignal();
};
#endif // MAINWINDOW_H
