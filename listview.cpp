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

    QSqlQuery query;
    try {
        std::unique_ptr <DatabaseBuilder> db = std::unique_ptr <DatabaseBuilder>(new DatabaseBuilder(DB_MAIN));
        _d = db->get_db();
    }
    catch (Exception e) {
        e.show();
    }

    try
    {
        query = _d->Select("categories", {"id", "name"}, {});
    }
    catch (Exception e) {
        e.show();
    }

    while(1)
    {
        QVariant id = query.value(0);
        QVariant name = query.value(1);
        QListWidgetItem *item = new QListWidgetItem(ui->catListWidget);
        item->setData(Qt::DisplayRole, name);
        item->setData(Qt::UserRole, id);
        ui->catListWidget->addItem(item);
        if(!query.next())
            break;
    }
}

ListView::~ListView()
{
    delete ui;
}

void ListView::on_catListWidget_itemClicked(QListWidgetItem *item)
{
    if(!item)
        return;

    ui->prodListWidget->clear();

    QString catId = item->data(Qt::UserRole).toString();
    QSqlQuery query;
    try {
        query = _d->Select("products", {"id, name, description"}, "category_id = '" + catId + "'");
    }
    catch (Exception e) {
        e.show();
    }

    while(1)
    {
        QVariant name = query.value(1);
        QString id = query.value(0).toString();
        QString description = query.value(2).toString();
        QStringList data = { id, description };
        QListWidgetItem *newItem = new QListWidgetItem(ui->prodListWidget);
        newItem->setData(Qt::DisplayRole, name);
        newItem->setData(Qt::UserRole, data);
        if(!query.next())
            break;
    }
}

void ListView::on_prodListWidget_itemClicked(QListWidgetItem *item)
{
    if (!item)
        return;

    QString prodDescription = item->data(Qt::UserRole).toStringList().last();
    QString prodId = item->data(Qt::UserRole).toStringList().first();
    ui->descriptionText->setText(prodDescription);
    QSqlQuery query;
    try {
        query = _d->Select("prod_cons", { "consumable_id", "consumable_unit", "consumable_value" }, "product_id = " + prodId);
        while(1)
        {
            QString conId = query.value(0).toString();
            QString conUnit = query.value(1).toString();
            QString conValue = query.value(2).toString();
            QSqlQuery queryInternal = _d->Select("consumables", {"name"}, "id = " + conId);
            QString conName = queryInternal.value(0).toString();
            QListWidgetItem *newItem = new QListWidgetItem(ui->compositionListWidget);
            newItem->setData(Qt::DisplayRole, QVariant(conName + ": " + conValue + " " + conUnit));
            newItem->setData(Qt::UserRole, QVariant(conId));
            if(!query.next())
                break;
        }
    }
    catch (Exception e) {
        e.show();
    }
}

void ListView::on_prodListWidget_itemSelectionChanged()
{
    ui->descriptionText->clear();
    ui->compositionListWidget->clear();
}

void ListView::on_compositionListWidget_itemDoubleClicked(QListWidgetItem *item)
{
    try {
        DescriptionDialog *dd = new DescriptionDialog(0, _d.get(), "consumables", item->data(Qt::UserRole).toString());
        dd->show();
    }
    catch (Exception e) {
        e.show();
    }
}
