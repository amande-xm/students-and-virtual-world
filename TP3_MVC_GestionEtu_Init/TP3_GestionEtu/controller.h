#ifndef CONTROLLER_H
#define CONTROLLER_H
#include "promotion.h"


class Controller
{
protected:
    Promotion *promo;
public:
    Controller(Promotion *promo);
    virtual void control(QStringList& l)=0;
    virtual void controlOne(Student s)=0;
    virtual ~Controller() = default;
};

#endif // CONTROLLER_H
