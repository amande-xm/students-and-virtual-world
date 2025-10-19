#ifndef CONTROLLERADD_H
#define CONTROLLERADD_H
#include "controller.h"
#include <QDebug>


class ControllerAdd : public Controller
{
public:
    ControllerAdd(Promotion *promo);
    void control(QStringList& l) override;
    void controlOne(Student s) override;
    ~ControllerAdd();
};

#endif // CONTROLLERADD_H
