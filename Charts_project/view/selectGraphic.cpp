#include "view/selectGraphic.h"

SelectGraphic::SelectGraphic(QWidget* parent) : QWidget(parent) {
    map = getChartImages();

    /*Si tratta di una griglia concettuale composta da n righe e 3 colonne. Il secondo for serve soltanto a una
      visualizzazione più carina degli widget a schermo (evitando così il classico alignment verso il bordo sinistro).*/
    QGridLayout *gridLayout = new QGridLayout(this);
    int totCharts = map.size();
    int i = 0;
    for (; i < (totCharts/3)*3; i++){
        chart = new ChooseChart(map.firstKey(), map.first(), this);
        gridLayout->addWidget(chart, i/3, 2*(i%3), 1, 2);
        map.remove(map.firstKey());
    }
    for (int j = 0; i < totCharts; i++, j++) {
        chart = new ChooseChart(map.firstKey(), map.first(), this);
        if (totCharts-((totCharts/3)*3) == 1)
            gridLayout->addWidget(chart, i/3, 2, 1, 2);
        else // per forza == 2
            gridLayout->addWidget(chart, i/3, (2*j)+1, 1, 2);
        map.remove(map.firstKey());
    }
    setLayout(gridLayout);
}

QMap<QString, QString> SelectGraphic::getChartImages() {
    QMap<QString, QString> map = QMap<QString, QString>();
    map.insert("BarChart", ":/Chart/Immagini/barchart.png");
    map.insert("LineChart", ":/Chart/Immagini/linechart.svg");
    map.insert("PieChart", ":/Chart/Immagini/piechart.png");
    map.insert("AreaChart", ":/Chart/Immagini/areachart.PNG");
    map.insert("CandleChart", ":/Chart/Immagini/candlechart.svg");

    return map;
}
