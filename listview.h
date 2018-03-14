#ifndef LISTVIEW_H
#define LISTVIEW_H
#include <QDialog>
#include "ui_listview.h"
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

    void on_getMarketInfoButton_clicked();

private:
    Ui::ListView *ui;
};

#endif // LISTVIEW_H
