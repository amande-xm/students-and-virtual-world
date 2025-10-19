#include "circle.h"

Circle::Circle() : Shape()
{
    pos = QPointF(-1, -1);
    col = QColor::fromRgb(QRandomGenerator::global()->generate());
    radius = std::rand() % 100;
}

Circle::Circle(QPointF p, double radius, QColor c): Shape(p, c), radius(radius){
}

QGraphicsItem* Circle::getGraphicsItem(){
    // Note: handling Color by creating an inherited QGraphicsCustomEllipseItem class
    // and overriding paint() method (calling setPen(pen))

    // construct Ellipse Item from the default surrounding QRectF
    QGraphicsItem* item = new QGraphicsEllipseItem(pos.x()-radius, pos.y()-radius, radius*2., radius*2.);
    item->setData(0,id);
    QPen mypen(this->getCol());
    dynamic_cast<QAbstractGraphicsShapeItem*>(item)->setPen(mypen);
    return item;
}

QString Circle::type() const{
    return "Circle";
}

