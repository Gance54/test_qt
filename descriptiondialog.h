#ifndef DESCRIPTIONDIALOG_H
#define DESCRIPTIONDIALOG_H
#include <ui_description.h>
#include <database.h>

namespace Ui {
class DescriptionDialog;
}

class DescriptionDialog : public QDialog
{
    Q_OBJECT

public:
    explicit DescriptionDialog(QDialog *parent,
                               DataBase *d, QString table, QString id);
    ~DescriptionDialog();

private slots:

private:
    Ui::DescriptionDialog *ui;
    QString _id;
    QString _table;
    DataBase *_d;
};

#endif // DESCRIPTIONDIALOG_H
