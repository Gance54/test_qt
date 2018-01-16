#include "descriptiondialog.h"

DescriptionDialog::DescriptionDialog(QDialog *parent, DataBase *d, QString table, QString id) :
    QDialog(parent),
    ui(new Ui::DescriptionDialog)
{
    ui->setupUi(this);
    _table = table;
    _id = id;
    _d = d;

    QSqlQuery query = _d->Select(_table, {"name, description"}, "id = " + _id);
    QString title = query.value(0).toString();
    title.replace(0, 1, title[0].toUpper());
    this->setWindowTitle(title);
    ui->textDescription->setText(query.value(1).toString());
}

DescriptionDialog::~DescriptionDialog()
{
    delete ui;
}
