#pragma once
#include "promotion.h"
#include <QtCharts/QChartView>
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>
#include <QGroupBox>
#include <QBoxLayout>


/**
 * @brief Class to manage the PieChart View
 * @author Adrien Peytavie
*/
class ViewPieChart : public QObject, public Observer
{
private:
    Promotion *promo;
    QWidget *widget;
public:
    ViewPieChart(Promotion *promo, QWidget *widget);
    void update() override;
};
