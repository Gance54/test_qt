#ifndef LISTVIEW_H
#define LISTVIEW_H
#include <QDialog>
#include <database.h>

namespace Ui {
class ListView;
}

class ListView : public QDialog
{
    Q_OBJECT

public:
    explicit ListView(QDialog *parent = 0);
    ~ListView();

private:
    Ui::ListView *ui;
    std::unique_ptr <DataBase> _d;
};

#endif // LISTVIEW_H
