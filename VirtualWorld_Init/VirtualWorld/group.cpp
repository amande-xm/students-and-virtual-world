#include "group.h"

Group::Group() : Shape()
{

}


void Group::add(QVector<Shape*>& v){
    for(auto s : v){
        shapesGroup.append(s);
    }
}

QGraphicsItem* Group::getGraphicsItem(){
    /*QGraphicsItemGroup* g;
    for (Shape* shape : shapesGroup){
        g->addToGroup(shape->getGraphicsItem());
    }
    return g;
    */
}

QString Group::type()const {
    return "Group";
}

QVector<Shape *> Group::getShapesGroup() const
{
    return shapesGroup;
}
