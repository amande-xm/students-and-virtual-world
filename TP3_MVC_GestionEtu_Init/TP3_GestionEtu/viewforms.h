#pragma once
#include "promotion.h"
#include <QLineEdit>
#include <QStringList>
#include <QObject>
#include <QDebug>
#include <QComboBox>
#include "controlleradd.h"
#include "controllerremovel.h"


class ViewForms : public QObject, public Observer
{
    Q_OBJECT
private:
    Promotion *promo;
    QLineEdit *lineEdit;
    QComboBox *BAC;
    QComboBox *dep;
    QLineEdit *number;
    QLineEdit *firstname;
    QLineEdit *lastname;

public:
    ViewForms(Promotion *promo, QLineEdit *lineEdit, QComboBox *BAC, QComboBox *dep, QLineEdit *number, QLineEdit *firstname, QLineEdit *lastname);
    void init();
    void update() override;

public slots:
    void removeOne();
    void addOne();
};


