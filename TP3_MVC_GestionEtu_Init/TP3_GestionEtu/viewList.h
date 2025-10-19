#pragma once
#include "promotion.h"
#include <QListWidget>
#include <QObject>
#include "controllerremovel.h"
/**
 * @brief Class to manage the QListWidget
 * @author Adrien Peytavie
*/
class ViewList : public QObject, public Observer
{
    Q_OBJECT
private :
    Promotion *promo;
    QListWidget *listWidget;
public:
    ViewList(Promotion* promo, QListWidget* listWidget);
   void update() override;

public slots:
   void remove();
};


