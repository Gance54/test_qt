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

    void on_changeButton_clicked();
    void on_buttonBox_accepted();
    void on_textDescription_textChanged();
    void on_buttonBox_rejected();

private:
    Ui::DescriptionDialog *ui;
    QString _id;
    QString _table;
    QString _desc;
    QString _changedDesc;
    DataBase *_d;
};

#endif // DESCRIPTIONDIALOG_H
