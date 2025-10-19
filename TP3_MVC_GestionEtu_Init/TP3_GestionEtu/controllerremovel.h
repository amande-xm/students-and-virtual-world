#ifndef CONTROLLERREMOVEL_H
#define CONTROLLERREMOVEL_H
#include "controller.h"
#include <QDebug>


class ControllerRemoveL : public Controller
{
public:
    ControllerRemoveL(Promotion *promo);
    void control(QStringList& l) override;
    void controlOne(Student s) override;
    ~ControllerRemoveL();
};

#endif // CONTROLLERREMOVEL_H
