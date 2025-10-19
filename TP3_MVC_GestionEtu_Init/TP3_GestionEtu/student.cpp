#include "student.h"

/**
 * @brief Constructor of the Sudent class
*/
Student::Student(QString cardID, QString firstname, QString lastname, QString department, QString bac):
    cardID(cardID), firstname(firstname), lastname(lastname), department(department), bac(bac)
{
}

/**
 * @brief Print the student information
*/
QDebug operator<<(QDebug os, const Student& dt)
{
    os << dt.cardID << " " << dt.firstname << " " << dt.lastname << " " << dt.bac << " " << dt.department;

    return os;
}
