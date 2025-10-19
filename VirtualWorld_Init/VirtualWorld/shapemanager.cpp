#include "shapemanager.h"


ShapeManager::ShapeManager() : Observable()
{}

void ShapeManager::add(Shape* shape)
{
    if (shape == nullptr) return;

    shapes.append(shape);
    notifyObserver();
}


void ShapeManager::moveShape(int id, QPointF pos)
{
    Shape* shape= getShape(id);
    if (shape == nullptr) return;

    shape->setPos(pos);
}

void ShapeManager::removeShape(int id)
{
    for (int i = 0; i< shapes.length(); i++){
        if(shapes[i]->getId() == id){
            shapes.removeAt(i);
        }
    }
}

Shape* ShapeManager::getShape(int id)
{
    for (Shape* shape : shapes)
    {
        if (shape->getId() == id)
        {
            return shape;
        }
    }
    return nullptr;
}
