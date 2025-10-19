#pragma once
#include "shapemanager.h"
#include "controller.h"
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QTreeWidget>
#include <QDebug>
#include <iostream>

using namespace std;


class PaintView : public QGraphicsScene, public Observer//: public QObject
{
    Q_OBJECT
private:
    ShapeManager* shapeManager;
    QPointF mousePos;
    QString toolbox;

public:
    PaintView(ShapeManager* = nullptr);
    void updateModel() override;

protected:
    void drawForeground(QPainter* painter, const QRectF& rect) override;

public slots:
    void mousePressEvent(QGraphicsSceneMouseEvent* mouseEvent) override;
    void mouseReleaseEvent(QGraphicsSceneMouseEvent* mouseEvent) override;
    void mouseMoveEvent(QGraphicsSceneMouseEvent* mouseEvent) override;
    void groupShapes();
    void removeShapes();
};
