#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "calendar.h"
#include "unistd.h"
#include <database.h>
#include <exception.h>
#include <memory>
#include <main_db/maindatabase.h>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
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

void MainWindow::on_InitDatabase_clicked()
{
    /*try {
        auto main_db = std::unique_ptr <MainDatabase> (new MainDatabase());
        main_db->FillData();
    }
    catch (Exception e) {
        e.show();
    }*/

    DBWorker *worker = new DBWorker();
    QThread *thread = new QThread;
    worker->moveToThread(thread);
    connect(thread, SIGNAL(started()), worker, SLOT(process()));
    thread->start();
    return;
}
