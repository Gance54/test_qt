#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "calendar.h"
#include "unistd.h"
#include <database.h>
#include <exception.h>
#include <memory>
#include <main_db/maindatabase.h>
#include <iostream>

LabelMapper gdbLabels;
LabelMapper gdbTransactionLabels;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    gdbLabels.RegisterLabel(ui->DbStatusLabel);
    gdbTransactionLabels.RegisterLabel(ui->DbTransactionsCountLabel);
    _object = NULL;
    products = NULL;
    calendar = NULL;
}

MainWindow::~MainWindow()
{
    std::cout<<"Main window destructor"<<std::endl;
    delete ui;
    delete calendar;
    delete products;
    if(_object)
        delete (DBWorker *)_object;
}

void MainWindow::on_Calendar_clicked()
{
    if(!calendar)
    {
        calendar = new Calendar();
    }
    calendar->show();
}

void MainWindow::on_ProductsButton_clicked()
{
    if(!products)
    {
        products = new ListView();
        products->setWindowTitle("MarketInfo");
    }
    products->show();
}

void MainWindow::on_InitDatabase_clicked()
{

}

void MainWindow::on_lockButton_clicked()
{

}

void MainWindow::on_unlockButton_clicked()
{

}
