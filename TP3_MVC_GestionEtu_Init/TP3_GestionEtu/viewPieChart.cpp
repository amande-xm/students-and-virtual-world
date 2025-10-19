#include "viewPieChart.h"

ViewPieChart::ViewPieChart(Promotion *promo, QWidget *widget) : promo(promo), widget(widget)
{
    widget->setLayout(new QVBoxLayout);
    update();
}
void ViewPieChart::update(){
    QString dep[102][2];
    int temp;
    for (int i =1; i<96; i++){
        dep[i-1][0] = QString::number(i);
    }
    for (int j =1; j<7; j++){
        dep [94+j][0] = "97" +QString::number(j);
    }
    dep[101][0] = "Autre";
    for (int m = 0; m<102; m++){
        dep[m][1] = "0";
    }
    for (int k = 0; k<promo->getStudents().length(); k++){
        for (int l = 0; l<102; l++){
            if(promo->getStudents().at(k).getDepartment()==dep[l][0]){
                temp = dep[l][1].toInt();
                temp++;
                dep[l][1] = QString::number(temp);
            }
        }
    }
    QPieSeries *series = new QPieSeries();
    int nb = 0;
    for (int n =0; n<102; n++){
        if(dep[n][1]!="0"){
            series->append(dep[n][0],dep[n][1].toInt());
            nb++;
        }
    }
    for (int p =0; p<nb; p++){
        QPieSlice *slice = series->slices().at(p);
        slice->setExploded();
        slice->setLabelVisible();
        slice->setPen(QPen(Qt::darkBlue, 2));
        slice->setBrush(Qt::darkGreen);
    }

    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("Répartition géographique");
    chart->legend()->hide();
    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);
    widget->layout()->addWidget(chartView);
}
