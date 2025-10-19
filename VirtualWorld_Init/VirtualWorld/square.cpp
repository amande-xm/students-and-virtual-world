#include "square.h"

Square::Square() : Shape()
{
    pos = QPointF(-1,-1);
    col = QColor::fromRgb(QRandomGenerator::global()->generate());
    side = std::rand()%100;
}

Square::Square(QPointF p, double side, QColor c): Shape(p,c), side(side){

}

QGraphicsItem* Square::getGraphicsItem(){
    // Note: handling Color by creating an inherited QGraphicsCustomEllipseItem class
    // and overriding paint() method (calling setPen(pen))

    // construct Rect Item from the default surrounding QRectF
    QGraphicsItem* item = new QGraphicsRectItem(pos.x()-side, pos.y()-side, side, side);
    item->setData(0,id);
    QPen mypen(this->getCol());
    dynamic_cast<QAbstractGraphicsShapeItem*>(item)->setPen(mypen);
    return item;
}

QString Square::type()const{
    return "Square";
}
