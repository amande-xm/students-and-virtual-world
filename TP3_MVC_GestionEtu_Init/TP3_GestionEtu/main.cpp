#include "TP3_GestionEtu.h"
#include "promotion.h"
#include <QApplication>
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Promotion promo("./../data/promoDUT.csv");
    qDebug() << promo;
    // Create Interface (data are loaded here)
    TP3_GestionEtu w;
    w.show();

    return a.exec();
}
