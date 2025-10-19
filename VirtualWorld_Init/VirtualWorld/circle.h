#pragma once
#include <QPointF>
#include <QGraphicsItem>
#include <QRandomGenerator>
#include <QColor>
#include "shape.h"
#include <QPen>


class Circle : public Shape
{
private:
    double radius;
public:
    Circle();
    Circle(QPointF p, double radius, QColor c = QColor::fromRgb(QRandomGenerator::global()->generate()));
    QGraphicsItem* getGraphicsItem() override;
    void add(QVector<Shape*>&) override {}
    QString type() const override;
};


