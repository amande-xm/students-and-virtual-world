#pragma once
#include <QPointF>
#include <QGraphicsItem>
#include <QRandomGenerator>
#include <QColor>
#include "shape.h"


class Group : public Shape
{
protected:
    QVector<Shape*> shapesGroup;
public:
    Group();
    void add(QVector<Shape*>& v);
    QGraphicsItem* getGraphicsItem();
    QString type() const;
    QVector<Shape *> getShapesGroup() const;
};

