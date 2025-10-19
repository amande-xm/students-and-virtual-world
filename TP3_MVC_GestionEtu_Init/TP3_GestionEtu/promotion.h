#pragma once
#include <QList>
#include <QDebug>
#include <QFile>
#include "student.h"
#include "observer.h"
class Observable;
/**
 * @brief Promotion manage the list of students
 * @author Fabrice Jaillet
*/
class Promotion : public Observable
{
private:
    QList<Student> students;

public:
    Promotion(QString filename);
    ~Promotion() {}

    void add(const Student&);
    void remove(const Student&);
    void remove(const QString &);

    Student find(QString) const;

    friend QDebug operator<<(QDebug os, const Promotion& dt);
    QList<Student> getStudents() const;
};

QDebug operator<<(QDebug os, const Promotion& dt);

