#ifndef LISTVIEW_H
#define LISTVIEW_H
#include <QDialog>
#include <database.h>
#include "ui_listview.h"
#include <descriptiondialog.h>
namespace Ui {
class ListView;
}

class ListView : public QDialog
{
    Q_OBJECT

public:
    explicit ListView(QDialog *parent = 0);
    ~ListView();

private slots:
    void on_catListWidget_itemClicked(QListWidgetItem *item);
    void on_prodListWidget_itemClicked(QListWidgetItem *item);
    void on_prodListWidget_itemSelectionChanged();
    void on_compositionListWidget_itemDoubleClicked(QListWidgetItem *item);

private:
    Ui::ListView *ui;
    std::unique_ptr <DataBase> _d;
};

#endif // LISTVIEW_H
