#include "promotion.h"

/**
 * @brief Constructor of the Promotion Class to manage the List of student
 * @param filename, path to the data CSV file
*/
QList<Student> Promotion::getStudents() const
{
    return students;
}

Promotion::Promotion(QString filename)
{
    QFile file(filename);
    if(!file.open(QIODevice::ReadOnly | QIODevice::Text))
        return;
    QTextStream in(&file);
    while (!in.atEnd()){
        QString line = in.readLine();
        QStringList d = line.split(';');
        students.append(Student(d[0], d[1], d[2], d[3], d[4]));
    }
    file.close();
}



/**
 * @brief Function to add a student to the promotion list
 * @param etu The current student
*/
void Promotion::add(const Student &etu)
{
    students.append(etu);
    notifyObserver();
}

/**
 * @brief Function to remove a list of student
 * @param listName The list of the students text in the view list
*/
void Promotion::remove(const QString& listName)
{
    for (int i = 0; i<students.size(); i++){
        if(students[i].getText()==listName){
            students.removeAt(i);
        }
    }
    notifyObserver();
}

/**
 * @brief Function to remove a specific student
 * @param etu The student to remove
*/
void Promotion::remove(const Student &etu)
{
    int i = 0;
    foreach(Student s, students){
        if(s.getCardID() == etu.getCardID()){
            students.removeAt(i);
            notifyObserver();
            return;
        }
        i++;
    }
    notifyObserver();
}

/**
 * @brief Search the student according to his ID Card
 * @param cardID ID card of the student
 * @return Student
*/
Student Promotion::find(QString cardID) const
{
    foreach(Student s, students){
        if(s.getCardID() == cardID){
            return s;
        }
    }
    return Student();
}

/**
 * @brief Print the student information
*/
QDebug operator<<(QDebug  os, const Promotion& dt)
{
    for (const Student& student : dt.students)
    {
        os << student << "\n";
    }

    return os;
}

