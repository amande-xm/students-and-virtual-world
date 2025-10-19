#include "controlleradd.h"

ControllerAdd::ControllerAdd(Promotion *promo) : Controller(promo)
{

}

void ControllerAdd::control(QStringList& l){
    if( l.at(0)!=""){
        bool ok;
        int verif = l.at(0).toInt(&ok, 10);
        if (ok){
            if(l.at(1)!=""){
                if(l.at(2)!=""){
                        if(promo->find(l.at(0)).getCardID()==""){
                            promo->add(Student(l.at(0), l.at(1).toUpper(),l.at(2).toUpper(),l.at(3), l.at(4)));
                        }
                        else {
                            qDebug()<< "numéro d'étudiant déjà utilisé";
                        }
                } else if (l.at(2)==""){
                    qDebug()<<"veuillez entrer un nom";
                }
            } else if(l.at(1)=="") {
                qDebug() << "veuillez entrer un prénom";
            }
        }else {
            qDebug()<<"veuillez entrer un numéro étudiant valide";
        }
    } else if (l.at(0)==""){
        qDebug()<<"veuillez entrer un numéro étudiant";
    }



}

void ControllerAdd::controlOne(Student s){

}

ControllerAdd::~ControllerAdd(){
}

