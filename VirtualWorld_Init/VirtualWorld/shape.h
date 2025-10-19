#pragma once
#include <QPointF>
#include <QGraphicsItem>
#include <QRandomGenerator>
#include <QColor>

class Shape
{
protected:
    QPointF pos; // center of the shape
    QColor col; // color of the shape
    int id; // its id
    static int current_id; // number of shapes already created => next id

public:
    Shape();
    Shape(QPointF, QColor c = QColor::fromRgb(QRandomGenerator::global()->generate()));
    virtual QGraphicsItem* getGraphicsItem()=0;
    virtual void add(QVector<Shape*>& v) = 0;
    virtual QString type() const=0;
    void setPos(QPointF newPos);
    void setCol(const QColor &newCol);
    int getId() const;
    QColor getCol() const;
};
