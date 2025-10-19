#pragma once
#include "shapemanager.h"
#include <QPointF>
#include "shapefactory.h"
#include <iostream>
#include <paintview.h>
#include "group.h"
#include <QColor>

using namespace std;

class ControllerAdd
{
    ShapeManager* shapeManager;
public:
    ControllerAdd(ShapeManager* = nullptr);
    void control(int type, QColor col);
};

class ControllerMoveShape
{
    ShapeManager* shapeManager;
public:
    ControllerMoveShape(ShapeManager* = nullptr);
    void control(const QVector<QGraphicsItem *> &);
};

class ControllerGroup
{
    ShapeManager* shapeManager;
public:
    ControllerGroup(ShapeManager* = nullptr);
    void control(QVector<Shape*>& items);
};

class ControllerRemove
{
    ShapeManager* shapeManager;
public:
    ControllerRemove(ShapeManager* = nullptr);
    void control(QList <QGraphicsItem*> list);
};
