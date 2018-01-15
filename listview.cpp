#include "listview.h"
#include "ui_listview.h"
#include <exception.h>
#include <database.h>

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
    QSqlQuery query;
    if(!item)
        return;

    ui->prodListWidget->clear();

    QString catId = item->data(Qt::UserRole).toString();
    try {
        query = _d->Select("products", {"id, name"}, "category_id = '" + catId + "'");
    }
    catch (Exception e) {
        e.show();
    }

    while(1)
    {
        QVariant id = query.value(0);
        QVariant name = query.value(1);
        QListWidgetItem *newItem = new QListWidgetItem(ui->prodListWidget);
        newItem->setData(Qt::DisplayRole, name);
        newItem->setData(Qt::UserRole, id);
        ui->prodListWidget->addItem(newItem);
        if(!query.next())
            break;
    }
}
