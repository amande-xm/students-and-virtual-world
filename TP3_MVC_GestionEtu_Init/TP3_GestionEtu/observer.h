#pragma once
#include <QList>
#include <QDebug>

class Observer {
public:
    virtual ~Observer() = default;
    virtual void update() = 0;
};

class Observable {
protected:
    QList<Observer*> observers;
public:
    virtual ~Observable() = default;
    void addObserver(Observer* o) {observers.append(o); }
    void removeObserver(Observer* observer) { observers.removeAll(observer); }
    void notifyObserver() const {
        for (Observer *o : observers){
            o->update();
        }
      }
};
