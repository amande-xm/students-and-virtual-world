#pragma once
#include "shape.h"
#include "circle.h"
#include "observer.h"
#include <QVector>
#include <QPointF>

/**
 * @brief The ShapeManager class
 * Handles management of the shapes displayed in the PaintView
 */
class ShapeManager : public Observable
{
private:

    /**
     * @brief shapes
     * Array of the shapes created by the user
     */
    QVector<Shape*> shapes;

public:
    ShapeManager();

    /**
     * @brief add
     * @param shape
     * Adds the shape to the QVector "shapes"
     */
    void add(Shape* shape);

    /**
     * @brief moveShape
     * @param id
     * @param pos
     * Puts the shape obtained by "id" to the new position "pos"
     */
    void moveShape(int id,QPointF pos);

    /**
     * @brief removeShape
     * @param id
     * Removes the shape obtained by "id" from the QVector "shapes"
     */
    void removeShape(int id);

    /**
     * @brief getShape
     * @param id
     * @return the shape identified by "id" stored in the QVector "shapes"
     */
    Shape* getShape(int id);

    /**
     * @brief getShapes
     * @return the complete array of shapes in "shapes" created by the user
     */
    const QVector<Shape*>& getShapes() const {return shapes;}
};

