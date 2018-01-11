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
    _object = NULL;
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
    DBWorker *worker = new DBWorker();
    QThread *thread = new QThread;
    worker->moveToThread(thread);
    connect(thread, SIGNAL(started()), worker, SLOT(process()));
    RegisterObject(worker);
    thread->start();
    return;
}

void MainWindow:: RegisterObject(void *ptr)
{
    _object = ptr;
}

void MainWindow::on_lockButton_clicked()
{
    DBWorker *worker = reinterpret_cast<DBWorker *>(_object);
    worker->stop();
}

void MainWindow::on_unlockButton_clicked()
{
    DBWorker *worker = reinterpret_cast<DBWorker *>(_object);;
    worker->resume();
}
