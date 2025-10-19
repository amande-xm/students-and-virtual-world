#include "viewforms.h"

ViewForms::ViewForms(Promotion *promo, QLineEdit *lineEdit, QComboBox *BAC, QComboBox *dep, QLineEdit *number,QLineEdit *firstname, QLineEdit *lastname) : promo(promo), lineEdit(lineEdit), BAC(BAC), dep(dep), number(number), firstname(firstname), lastname(lastname)
{
    init();
    //    update();
}

void ViewForms::init(){
    QStringList listBac, listDep;
    listBac <<"S"<<"ES"<<"L"<<"STI"<<"STI2D"<<"STI2A"<<"STL"<<"ST2S"<<"STMG"<<"ST2TMD"<<"STHR"<<"STAV";
    for (int i =1; i<96; i++){
            listDep << QString::number(i);
    }
    for (int j =1; j<7; j++){
        listDep << "97" +QString::number(j);
    }
    listDep<<"Autre";
    BAC->addItems(listBac);
    dep->addItems(listDep);
}

void ViewForms::update(){
// update() method should contain something like
}

void ViewForms::removeOne(){
    QString a = lineEdit->text();
    if(a!=""){
        if(promo->find(a).getCardID()!=""){
            ControllerRemoveL controler(promo);
            controler.controlOne(promo->find(a));
        }
    }
    lineEdit->clear();
}

void ViewForms::addOne(){
    QStringList l;
    l.append(number->text());
    l.append(firstname->text());
    l.append(lastname->text());
    l.append(dep->currentText());
    l.append(BAC->currentText());
    ControllerAdd controler(promo);
    controler.control(l);
    number->clear();firstname->clear();lastname->clear();
}
