#include "controllerremovel.h"

ControllerRemoveL::ControllerRemoveL(Promotion *promo) : Controller(promo)
{
}

void ControllerRemoveL::control(QStringList& l){
  for(QString s : l){
      promo->remove(s);
  }
}

void ControllerRemoveL::controlOne(Student s){
    promo->remove(s);
}

ControllerRemoveL::~ControllerRemoveL(){
}
