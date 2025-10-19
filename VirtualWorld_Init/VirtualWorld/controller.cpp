#include "controller.h"
#include "shapemanager.h"
#include <QPen>

#include <cstdlib>
#include <iostream>
#include <ctime>

ControllerAdd::ControllerAdd(ShapeManager* sm) : shapeManager(sm)
{}

void ControllerAdd::control(int type, QColor col)
{
    if (shapeManager == nullptr) return;

    // Add Shape
    // TODO : call Factory here!
    ShapeFactory* sf = new ShapeFactory();
    shapeManager->add(sf->createShape(type, col));
}

ControllerMoveShape::ControllerMoveShape(ShapeManager* sm) : shapeManager(sm)
{}

void ControllerMoveShape::control(const QVector<QGraphicsItem*>& items)
{
    if (shapeManager == nullptr) return;

    // Move Shape
    for (QGraphicsItem* item : items)
    {
        QVariant variant = item->data(0);
        int id = variant.toInt();

        Shape* shape = shapeManager->getShape(id);
        if (shape!=nullptr)
        {
            QRectF rect = item->boundingRect();
            shape->setPos(item->scenePos() + rect.center());
            for (auto child:item->childItems())
            {
                int iid = child->data(0).toInt();
                shapeManager->getShape(iid)->setPos(child->scenePos()+child->boundingRect().center());
            }
        }
    }
    shapeManager->notifyObserver();
}

ControllerGroup::ControllerGroup(ShapeManager* sm) : shapeManager(sm)
{}

void ControllerGroup::control(QVector<Shape*>& items){
    if (shapeManager == nullptr) return;
    ShapeFactory* sf = new ShapeFactory();
    Shape *g = sf->createShape(-4,QColor::fromRgb(QRandomGenerator::global()->generate()) );
    g->add(items);
    shapeManager->add(g);
    shapeManager->notifyObserver();
}

ControllerRemove::ControllerRemove(ShapeManager *sm) : shapeManager(sm){}

void ControllerRemove::control(QList<QGraphicsItem *> list)
{
    for (auto a : list){
        shapeManager->removeShape(a->data(0).toInt());
    }
    shapeManager->notifyObserver();
}
