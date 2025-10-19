#include "paintview.h"
#include <QGraphicsItem>
#include <QGraphicsSceneMouseEvent>

PaintView::PaintView( ShapeManager* sm) : QGraphicsScene(), Observer(), shapeManager(sm)
{
}

void PaintView::drawForeground(QPainter* painter, const QRectF& rect)
{
    Q_UNUSED(rect)

    if (toolbox.isEmpty()) return;

    QGraphicsView* gv = (QGraphicsView*)this->parent();

    QPointF p1 = gv->mapToScene(QPoint(10, 10));

    painter->save();

    painter->setBrush(QBrush(QColor(229,255,204)));
    painter->setPen(Qt::black);

    painter->drawRect(p1.x() + 10, p1.y() + 10, toolbox.size() * 10, 20);
    painter->drawText(int(p1.x() + 14), int(p1.y() + 12), toolbox.size() * 10, 20, Qt::AlignLeft, toolbox);

    painter->restore();

    painter->setPen(Qt::red);

    for (QGraphicsItem *item : selectedItems()){
        painter->drawRect(item->sceneBoundingRect());
    }

}

void PaintView::updateModel()
{
    // Clear
    clear();

    // Get models
    QVector<Shape*> shapes = shapeManager->getShapes();
    for (Shape* shape : shapes)
    {
        QGraphicsItem* item = shape->getGraphicsItem();
        if (item != nullptr && !(shape->type()=="Group")){
            item->setAcceptDrops(true);
            item->setFlag(QGraphicsItem::ItemIsSelectable);
            addItem(item);
        } else if(item != nullptr && shape->type()== "Group"){
            item->setAcceptDrops(true);
            item->setFlag(QGraphicsItem::ItemIsSelectable);
            addItem(item);
        }
    }

    update();
}

void PaintView::mousePressEvent(QGraphicsSceneMouseEvent* mouseEvent)
{
    if ((mouseEvent->button() == Qt::LeftButton))
    {
        mousePos = mouseEvent->scenePos();
        toolbox = "mousePressEvent (" + QString::number(mousePos.x()) + "," + QString::number(mousePos.y()) + ")";
            for (auto s : items(mousePos)) {
                if (s->parentItem() == nullptr) // if in a Group, only handle top item
                {
                    s->setSelected(!s->isSelected());
                    s->setOpacity( 1.1-s->opacity()); //assuming default opacity=1. switch from 1. to 0.1, and conversely
                }
            }
    }
    update();
}


void PaintView::mouseMoveEvent(QGraphicsSceneMouseEvent* mouseEvent)
{
    if ( selectedItems().size() > 0 && (mouseEvent->buttons() & Qt::LeftButton) && (mouseEvent->modifiers() && Qt::ShiftModifier))
    {
        QPointF mousePosNew = mouseEvent->scenePos();

        toolbox = "mouseMoveEvent (" + QString::number(mousePosNew.x()) + "," + QString::number(mousePosNew.y()) + ")";
        QPointF mouseD = mousePosNew - mousePos;
        for (QGraphicsItem* item : selectedItems())
        {
            item->setCursor(QCursor(Qt::ClosedHandCursor));
            item->moveBy(mouseD.x(), mouseD.y());
        }
        mousePos = mousePosNew;
    }

    update();
}

void PaintView::mouseReleaseEvent(QGraphicsSceneMouseEvent* mouseEvent)
{
    toolbox = "mouseReleaseEvent";
    if(mouseEvent->modifiers() && Qt::ShiftModifier){
        // Call Controller to modify the model
        ControllerMoveShape(shapeManager).control(selectedItems());
        for (QGraphicsItem* item : selectedItems())
        {
            item->setCursor(QCursor(Qt::ArrowCursor));
            //        item->setSelected(false);
        }
        clearSelection();
    }

    update();
}

void PaintView::groupShapes(){
    if(selectedItems().size()!=0){
        QVector <Shape*> a;
        for (auto s : selectedItems()){
            a.append(shapeManager->getShape(s->data(0).toInt()));
        }
        ControllerGroup(shapeManager).control(a);
        update();
    }
}

void PaintView::removeShapes(){
    if(selectedItems().size()!=0){
        ControllerRemove(shapeManager).control(selectedItems());
        update();
    }
}
