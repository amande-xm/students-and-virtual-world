#include "TP3_GestionEtu.h"
#include <QDir>

TP3_GestionEtu::TP3_GestionEtu(QWidget *parent)
    : QMainWindow(parent), promo(nullptr)
{
    ui.setupUi(this);

    // Create Promotion
    promo = new Promotion( QDir::currentPath()+"/../data/promoDUT.csv");

    // Create Views and add connectors
    listView = new ViewList(promo, ui.listWidget);
    listForm = new ViewForms(promo, ui.lineEdit_remove_number, ui.lineEdit_add_BAC, ui.lineEdit_add_department, ui.lineEdit_add_number, ui.lineEdit_add_firstname, ui.lineEdit_add_lastname);
    pieChartView = new ViewPieChart(promo, ui.pieChart);


    // Handle Observers
    promo->addObserver(listView);
    promo->addObserver(listForm);
    promo->addObserver(pieChartView);

    connect(ui.pushButton_delete_list, SIGNAL(pressed()), listView, SLOT(remove()));
    connect(ui.pushButton_delete_number, SIGNAL(pressed()), listForm, SLOT(removeOne()));
    connect(ui.pushButton_addStudent, SIGNAL(pressed()), listForm, SLOT(addOne()));

}

TP3_GestionEtu::~TP3_GestionEtu(){
    delete promo;
}

