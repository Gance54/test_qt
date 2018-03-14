#include "descriptiondialog.h"
#include "exception.h"
DescriptionDialog::DescriptionDialog(QDialog *parent, DataBase *d, QString table, QString id) :
    QDialog(parent),
    ui(new Ui::DescriptionDialog)
{
    ui->setupUi(this);
    _table = table;
    _id = id;
    _d = d;

    QSqlQuery query;
    try {
        query = _d->Select(_table, {"name, description"}, "id = " + _id);
    }
    catch (Exception e) {
        throw e;
    }
    QString title = query.value(0).toString();
    _desc = query.value(1).toString();
    title.replace(0, 1, title[0].toUpper());
    this->setWindowTitle(title);
    ui->textDescription->setText(_desc);
}

DescriptionDialog::~DescriptionDialog()
{
    delete ui;
}

void DescriptionDialog::on_changeButton_clicked()
{
    ui->textDescription->setReadOnly(false);
}

void DescriptionDialog::on_buttonBox_accepted()
{
    if(!_changedDesc.isEmpty() && _changedDesc != _desc)
    {
        try {
            _d->Update(_table, { "description = '" + _changedDesc +"'" }, "id = " + _id);
        }
        catch (Exception e) {
            e.show();
        }
    }
}

void DescriptionDialog::on_textDescription_textChanged()
{
    _changedDesc = ui->textDescription->toPlainText();
}

void DescriptionDialog::on_buttonBox_rejected()
{
    ui->textDescription->setText(_desc);
    ui->textDescription->setReadOnly(true);
}
