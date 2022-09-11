#include "barchart_model.h"

BarChartModel::BarChartModel(BarChartTableModel *data) : ChartModel(data)
{
    series=new QBarSeries;
    mapper=new QVBarModelMapper();

    mapper->setFirstBarSetColumn(0);
    mapper->setLastBarSetColumn(tableModel->columnCount());
    mapper->setFirstRow(0);
    mapper->setRowCount(tableModel->rowCount());
    mapper->setSeries(series);
    mapper->setModel(tableModel);
    chart->addSeries(series);

    for(int i=0; i < tableModel->rowCount(); ++i){

        QString qstr = tableModel->headerData(i,Qt::Vertical,Qt::DisplayRole).toString();
        categories<<qstr;

    }

    axisX=new QBarCategoryAxis();
    axisX->append(categories);
    chart->addAxis(axisX,Qt::AlignBottom);
    series->attachAxis(axisX);
    axisY= new QValueAxis();
    axisY->setRange(getMin(), getMax());
    chart->setTitle(tableModel->getData()->getTitle());
    chart->addAxis(axisY, Qt::AlignLeft);
    series->attachAxis(axisY);
    series->setLabelsVisible(true);
    connect(series,&QBarSeries::doubleClicked,this,&BarChartModel::cambiaNome);
}

void BarChartModel::updateInsertRow() {
    BarChartModel::mapper->setRowCount(tableModel->rowCount());
    BarChartModel::categories<<tableModel->headerData(tableModel->rowCount()-1,Qt::Vertical,Qt::DisplayRole).toString();
    BarChartModel::axisX->append(categories);
}

void BarChartModel::updateInsertColumn() {
    mapper->setLastBarSetColumn(tableModel->columnCount());
}

void BarChartModel::updateRemoveRow(int pos) {
    mapper->setRowCount(tableModel->rowCount());
    categories.removeAt(pos);
    axisX->clear();
    axisX->append(categories);
}

void BarChartModel::updateRemoveColumn(int pos) {
    mapper->setLastBarSetColumn(pos);
}

void BarChartModel::updateAxisY(){
    axisY->setRange(getMin(),getMax()+1);
}

int BarChartModel::getMax(){
    int max=series->barSets().at(0)->at(0);
    for(int i=0;i<series->barSets().size();++i)
        for(int j=0;j<series->barSets().at(i)->count();++j){
            qreal t=series->barSets().at(i)->at(j);
            if(t>max)
                max=t;
        }
    return max;
}

int BarChartModel::getMin(){
    int min=0;
    for(int i=0;i<series->barSets().size();++i)
        for(int j=0;j<series->barSets().at(i)->count();++j){
            qreal t=series->barSets().at(i)->at(j);
            if(t<min)
                min=t;
        }
    return min;
}

void BarChartModel::cambiaNome(int index,QBarSet *barset){
    QStringList name;
    name<<"Bar name";
    name<<"Set name";
    bool ok;
    QString scelta=QInputDialog::getItem(nullptr, tr("QInputDialog::getItem()"),
                                         tr("Scegli:"), name, 0, false, &ok);
    if(ok && !scelta.isEmpty()) {
        if(scelta.compare("Bar name")==0)
            for(int i=0;i<series->barSets().count();++i) {
                QBarSet* barSet=series->barSets().at(i);
                if(barset==barSet){
                    bool ok2;
                    QString nome=QInputDialog::getText(nullptr,tr("Nome"),tr("Nome:"),QLineEdit::Normal,tr(""),&ok2);
                    if(ok2 && nome.trimmed()!=""){
                        tableModel->setHeaderData(i,Qt::Horizontal,nome,Qt::EditRole);
                        barSet->setLabel(nome);
                    }
                }
            }
        else{
            bool ok3;
            QString nomeset=QInputDialog::getText(nullptr,tr("Nome"),tr("Nome:"),QLineEdit::Normal,tr(""),&ok3);
            if(ok3 && nomeset.trimmed()!="")
                tableModel->setHeaderData(index,Qt::Vertical,nomeset,Qt::EditRole);
            categories.replace(index,nomeset);
            axisX->replace(axisX->at(index),nomeset);
        }
    }
}

void BarChartModel::salvaJson(){
    QJsonObject mainObject;
    QJsonObject secondaryObject;
    mainObject.insert(QString::fromStdString("title"),tableModel->getData()->getTitle());
    mainObject.insert(QString::fromStdString("Type"),QString::fromStdString("barchart"));
    QJsonArray c;
    QJsonArray v;
    QList<QBarSet*>temp=series->barSets();
    for(int j=0;j<temp.at(0)->count();++j)
    {
        for(int i=0;i<temp.count();++i)
        {
            if(j>0)
                c.pop_front();
            else
                v.append(temp.at(i)->label());
            c.append(temp.at(i)->at(j));
        }
        secondaryObject.insert(categories.at(j),c);

    }

    mainObject.insert(QString::fromStdString("bars"),secondaryObject);
    mainObject.insert(QString::fromStdString("names"),v);

    QJsonDocument document;
    document.setObject( mainObject );
    bool ok;
    QString nomeFile=QInputDialog::getText(nullptr,tr("Salva con nome:"),tr("Nome file:"),QLineEdit::Normal,QDir::home().dirName(),&ok);

    QFile file( "../Charts_project/graficisalvati/"+nomeFile+".json");
    if(file.open( QIODevice::WriteOnly))
    {
        file.write(document.toJson());
    }
    else
            qWarning("Couldn't open save file.");
}

