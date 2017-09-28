#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "calendar.h"
#include "unistd.h"
#include <database.h>
#include <exception.h>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    try {
        d = std::unique_ptr <DatabaseBuilder>(new DatabaseBuilder(DatabaseBuilder::DB_MAIN));
    }
    catch (Exception e) {
        e.show();
    }

    calendar = new Calendar();
    products = new ListView();
    products->setWindowTitle("Products");
}

MainWindow::~MainWindow()
{
    delete ui;
    delete calendar;
    delete products;
}

void MainWindow::on_Calendar_clicked()
{
    calendar->show();
}

void MainWindow::on_ProductsButton_clicked()
{
    products->show();
}
