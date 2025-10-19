#include "viewList.h"

ViewList::ViewList(Promotion* promo, QListWidget* listWidget) : promo(promo), listWidget(listWidget)
{
    update();
}

void ViewList::update(){
    listWidget->clear();
    for(int i =0; i<(promo->getStudents().length()); i++){
        listWidget->addItem(promo->getStudents().at(i).getText());
    }
}

void ViewList::remove(){
    QList<QListWidgetItem*> items = listWidget->selectedItems();
    QStringList listStringSelected;
    for (QListWidgetItem *item : items){
        listStringSelected.append(item->text());
    }
    ControllerRemoveL controler(promo);
    controler.control(listStringSelected);
}
