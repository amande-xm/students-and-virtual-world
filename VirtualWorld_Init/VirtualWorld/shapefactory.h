#pragma once
#include <QPointF>
#include <QGraphicsItem>
#include <QRandomGenerator>
#include <QColor>
#include "shape.h"
#include "square.h"
#include "circle.h"
#include "rectangle.h"
#include "group.h"

class ShapeFactory
{
public:
    ShapeFactory();
    Shape* createShape(int type, QColor col);
    ~ShapeFactory();
};
