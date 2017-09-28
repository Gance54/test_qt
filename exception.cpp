#include "exception.h"
#include <QMessageBox>

Exception::Exception(QString what, DataBase *db)
{
    _what = what;
    if(db)
    {
        QStringList tables = db->getTables();

        _what.append("Tables count = ");
        _what.append(QString::fromStdString(std::to_string(tables.count())));
        _what.append("\nTables are:");

        std::for_each(tables.begin(), tables.end(), [&](QString t){
            _what.append("\n");
            _what.append(t);
        });
    }
}

void Exception::show() const throw()
{
    QMessageBox msgBox;
    msgBox.setText(_what);
    msgBox.exec();
}
