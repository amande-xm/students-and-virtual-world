#pragma once
#include <QPointF>
#include <QGraphicsItem>
#include <QRandomGenerator>
#include <QColor>
#include "shape.h"
#include <QPen>


class Rectangle : public Shape
{
private:
    double width, height;
public:
    Rectangle();
    Rectangle(QPointF p, double width, double height, QColor c = QColor::fromRgb(QRandomGenerator::global()->generate()));
    QGraphicsItem* getGraphicsItem() override;

    void add(QVector<Shape*>&) override {}
    QString type() const override;
};

