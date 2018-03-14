#include "listview.h"
#include "ui_listview.h"
#include <exception.h>
#include <database.h>
#include <descriptiondialog.h>
#include <iostream>
ListView::ListView(QDialog *parent) :
    QDialog(parent),
    ui(new Ui::ListView)
{
    ui->setupUi(this);
}

ListView::~ListView()
{
    delete ui;
}

void ListView::on_getMarketInfoButton_clicked()
{

}
