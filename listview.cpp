#include "listview.h"
#include "ui_listview.h"
#include <listviewitem.h>
#include <exception.h>
#include <database.h>

ListView::ListView(QDialog *parent) :
    QDialog(parent),
    ui(new Ui::ListView)
{
    ui->setupUi(this);
    try {
        std::unique_ptr <DatabaseBuilder> db = std::unique_ptr <DatabaseBuilder>(new DatabaseBuilder(DB_MAIN));
        _d = db->get_db();
    }
    catch (Exception e) {
        e.show();
    }

    QSqlQuery query = _d->Select("categories", {"id", "name"}, {});
    while(1)
    {
        ListViewItem *item = new ListViewItem(ui->catListWidget, query.value(1).toString(), query.value(0).toString());
        ui->catListWidget->addItem(item);
        if(!query.next())
            break;
    }
}

ListView::~ListView()
{
    delete ui;
}
