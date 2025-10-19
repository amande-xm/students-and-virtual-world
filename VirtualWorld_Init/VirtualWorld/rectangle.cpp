#include "rectangle.h"

Rectangle::Rectangle() : Shape()
{
    pos = QPointF(-1,-1);
    col = QColor::fromRgb(QRandomGenerator::global()->generate());
    width = std::rand()%100;
    height = std::rand()%100;
}

Rectangle::Rectangle(QPointF p, double height, double width, QColor c): Shape(p,c), width(width), height(height){
}

QGraphicsItem* Rectangle::getGraphicsItem(){
    // Note: handling Color by creating an inherited QGraphicsCustomEllipseItem class
    // and overriding paint() method (calling setPen(pen))

    // construct Rect Item from the default surrounding QRectF
    QGraphicsItem* item = new QGraphicsRectItem(pos.x()-width, pos.y()-height, width, height);
    item->setData(0,id);
    QPen mypen(this->getCol());
    dynamic_cast<QAbstractGraphicsShapeItem*>(item)->setPen(mypen);
    return item;
}

QString Rectangle::type()const{
    return "Rectangle";
}
