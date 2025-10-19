#pragma once
#include <QPointF>
#include <QGraphicsItem>
#include <QRandomGenerator>
#include <QColor>
#include "shape.h"
#include <QPen>


class Square : public Shape
{
private :
    double side;
public:
    Square();
    Square(QPointF p, double side, QColor c = QColor::fromRgb(QRandomGenerator::global()->generate()));
    QGraphicsItem* getGraphicsItem() override;

    void add(QVector<Shape*>&) override {}
    QString type() const override;
};

