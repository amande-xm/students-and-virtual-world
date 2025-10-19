#include "shapefactory.h"

ShapeFactory::ShapeFactory()
{

}


Shape* ShapeFactory::createShape(int type, QColor col){
    switch(type){
    case -1:
        return new Circle(QPointF(std::rand() % 400 - 200, std::rand() % 400 - 200),std::rand() % 100, col);
        break;
    case -2:
        return new Square(QPointF(std::rand() % 400 - 200, std::rand() % 400 - 200),std::rand() % 100, col);
        break;
    case -3:
        return new Rectangle(QPointF(std::rand() % 400 - 200, std::rand() % 400 - 200),std::rand() % 100, std::rand() % 100, col);
        break;
    case -4:
        return new Group();
        break;
    }
}
