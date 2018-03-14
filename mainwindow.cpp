#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "unistd.h"
#include <memory>
#include <iostream>

LabelMapper gdbLabels;
LabelMapper gdbTransactionLabels;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

}

MainWindow::~MainWindow()
{
    std::cout<<"Main window destructor"<<std::endl;
    delete ui;
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
