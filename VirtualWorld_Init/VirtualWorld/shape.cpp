#include "shape.h"

int Shape::current_id=1; // added

QColor Shape::getCol() const
{
    return col;
}

Shape::Shape() : id(current_id++)
{
    pos = QPointF(-1, -1);
    col = QColor::fromRgb(QRandomGenerator::global()->generate());
}

Shape::Shape(QPointF p, QColor c) : id(current_id++)
{
    pos = p;
    col = c;
}

void Shape::setPos(QPointF newPos)
{
    pos = newPos;
}

void Shape::setCol(const QColor &newCol)
{
    col = newCol;
}

int Shape::getId() const
{
    return id;
}

