#include "virtualworld.h"
#include "controller.h"
#include <QDebug>

VirtualWorld::VirtualWorld(QWidget *parent, ShapeManager* sm)
    : QMainWindow(parent), shapeManager(sm)
{
    ui.setupUi(this);

    // Paint View
    paintview = new PaintView(shapeManager);
    shapeManager->addObserver(paintview);
    ui.graphicsView->setScene(paintview);
    paintview->setParent(ui.graphicsView);

    // Tree View
    treeview = new TreeView(shapeManager, ui.treeWidget);
    shapeManager->addObserver(treeview);

    // Connect buttons
    connect(ui.Object_AddButton, &QPushButton::pressed, this, &VirtualWorld::addShape);
    connect(ui.Object_GroupButton, &QPushButton::pressed, paintview, &PaintView::groupShapes);
    //    connect(ui.Object_UnGroupButton, &QPushButton::pressed, paintview, &PaintView::unGroupShapes);
    connect(ui.Object_RemoveButton, &QPushButton::pressed, paintview, &PaintView::removeShapes);

    // Handling colors here
    //    connect(ui.Object_ColorButton, &QPushButton::pressed, this, &VirtualWorld::colorShape);

}

VirtualWorld::~VirtualWorld()
{
    delete shapeManager;
}

void VirtualWorld::addShape()
{
    if(ui.radioButton_Circle->isChecked()){
        ControllerAdd(shapeManager).control(-1, QColor::fromRgb(QRandomGenerator::global()->generate()));
    }
    if(ui.radioButton_Square->isChecked()){
        ControllerAdd(shapeManager).control(-2, QColor::fromRgb(QRandomGenerator::global()->generate()));
    }
    if(ui.radioButton_Rectangle->isChecked()){
        ControllerAdd(shapeManager).control(-3, QColor::fromRgb(QRandomGenerator::global()->generate()));
    }
    // TODO: transmit shape type (from QButtonGroup), for the Fabric...

}
