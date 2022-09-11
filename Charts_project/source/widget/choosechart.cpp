#include "choosechart.h"

ChooseChart::ChooseChart(const QString& name, const QString& imgPath, QWidget* parent) : QWidget(parent) {
    QVBoxLayout* layout = new QVBoxLayout;

    label = new QLabel(name, this);
    label->setAlignment(Qt::AlignCenter);
    QFont font = label->font();
    font.setPointSize(15);
    font.setBold(true);
    label->setFont(font);
    //label->setFixedSize(50,50);

    QLabel* img = new QLabel(this);
    pic = QPixmap(imgPath);
    pic = pic.scaledToHeight(300);
    img->setPixmap(pic);
    //img->setFixedSize(300,300);

    button = new QPushButton(name, this);
    button->setObjectName(name);
    //button->setFixedSize(150,70);
    connect(button,&QPushButton::released,this,&ChooseChart::creaChartSlot);

    layout->addWidget(label);
    layout->addWidget(img);
    layout->addWidget(button);
    //layout->addStretch();

    setLayout(layout);
}


void ChooseChart::creaChartSlot(){
    emit creaChartSignal(button->objectName());
}

