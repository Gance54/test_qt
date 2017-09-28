#include "database.h"
#include <QMessageBox>
#include <exception.h>
#define DB_CONNESTION_PREFIX "sqlite_db_connection"
#define DB_FILENAME "database.dat"
#define DB_DRIVER "QSQLITE"


int DataBase::_total_connections = 0;

DataBase::DataBase(std::string dbPrefix, std::string filename,
                   QStringList dbTables, QStringList dbTableDescriptions)
{
    _m.lock();

    int currentConnections = _total_connections + 1;
    std::string connectionName = std::string(dbPrefix + std::to_string(currentConnections));
    _db = QSqlDatabase::addDatabase(QString::fromStdString(DB_DRIVER), QString::fromStdString(connectionName));
    _db.setDatabaseName(QString::fromStdString(filename));

    _tables = QStringList::fromVector(dbTables.toVector());
    _tableDescriptions = QStringList::fromVector(dbTableDescriptions.toVector());

    if (_db.open())
    {
        _total_connections = currentConnections;
        _dbValid = _isDbValid();

        if(!_dbValid)
        {
            try {
                _clear();
                _init();
            }
            catch (Exception e) {
                e.show();
            }
        }
    }
    else
        throw Exception ("Failed to open db");

    _m.unlock();
}

QSqlError DataBase::_init()
{
    if(_db.isOpen() && !_db.tables().count())
    {
        QSqlQuery q(_db);

        if(!_tables.count() || _tables.count() != _tableDescriptions.count())
            throw Exception(QString::fromStdString("Invalid database format"));

        for(auto t = _tables.begin(), d = _tableDescriptions.begin();
            t != _tables.end(), d != _tableDescriptions.end(); t++, d++)
        {
            QString query = QString::fromStdString("Create table '" + t->toStdString() + "' (" + d->toStdString() + ")");
            if (!q.exec(query))
                throw Exception(query + QString::fromStdString("\n") + q.lastError().text());
        }
    }
    else
        throw Exception("DB is not opened or already initialized");

    return QSqlError();
}

QSqlError DataBase::_clear()
{
    if(!_db.isOpen())
        throw Exception("DB is not open", this);

    if(!_db.tables().size())
        return QSqlError();

    QSqlQuery q(_db);

    while(_db.tables().size()) {
        QString query("Drop table '");
        query.append(*(_db.tables().begin()));
        query.append("'");
        if (!q.exec(query))
            throw Exception(q.lastError().text(), this);
    }

    return QSqlError();
}

DataBase::~DataBase()
{
     if(_db.isOpen())
     {
         _m.lock();
         _db.close();
         _total_connections--;
         _m.unlock();
     }

     _tables.clear();
     _tableDescriptions.clear();
}

QStringList DataBase::getTables()
{
    return _db.tables();
}

void DataBase::ShowMessage(QString text)
{
    QMessageBox msgBox;
    msgBox.setText(text);
    msgBox.exec();
}

bool DataBase::_isDbValid()
{
    bool valid = true;
    QStringList tables = _db.tables();
    if(tables.count() != _tables.count())
        return false;

    std::for_each(tables.begin(), tables.end(), [&](QString table) {
        if(!_tables.contains(table))
            valid = false;
    });

    std::for_each(_tables.begin(), _tables.end(), [&](QString table) {
        if(!tables.contains(table))
            valid = false;
    });

    if(!valid)
        return valid;

    return valid;
}

int DatabaseBuilder::SetDatabaseDescriptions(DbSet db,
                                             std::string &dbPrefix,
                                             std::string &dbFilename,
                                             QStringList &tables,
                                             QStringList &tableDescriptions)
{
    if(db >= DbSet::DB_MAX)
        return -1;

    dbPrefix = descriptions[db].dbPrefix;
    dbFilename = descriptions[db].dbFilename;

    if(sizeof(descriptions[db].tables)/sizeof(descriptions[db].tables[0]) !=
       sizeof(descriptions[db].tableDescriptions)/sizeof(descriptions[db].tableDescriptions[0]))
        return -1;

    for(size_t i = 0; i < sizeof(descriptions[db].tableDescriptions)/sizeof(descriptions[db].tableDescriptions[0]); i++)
        if(descriptions[db].tableDescriptions[i][0].size() != descriptions[db].tableDescriptions[i][1].size())
            return -1;

    for(size_t i = 0; i < sizeof(descriptions[db].tables)/sizeof(descriptions[db].tables[0]); i++)
    {
        QString description;

        for(auto field = descriptions[db].tableDescriptions[i][0].begin(), desc = descriptions[db].tableDescriptions[i][1].begin();
            field != descriptions[db].tableDescriptions[i][0].end(), desc != descriptions[db].tableDescriptions[i][1].end();
            field++, desc++)
        {
            description.append(*field + QString::fromStdString(" ") + *desc);
            if(field != descriptions[db].tableDescriptions[i][0].end() - 1)
                description.append(", ");
        }

        tables.push_back(QString::fromStdString(descriptions[db].tables[i]));

        tableDescriptions.push_back(description);
    }

    return 0;

}

QStringList DatabaseBuilder::GetTableFields(DbSet db,
                                            QString table)
{
    QStringList q;

    for(size_t i = 0; i < sizeof(descriptions[db].tables)/sizeof(descriptions[db].tables[0]); i++)
        if(descriptions[db].tables[i] == table.toStdString())
        {
            q = descriptions[db].tableDescriptions[i][0];
            break;
        }

    return q;
}

DatabaseBuilder::DatabaseBuilder(DbSet dbe)
{
    std::string dbPrefix, dbFilename;
    QStringList tables, tableDescriptions;

    if(SetDatabaseDescriptions(dbe, dbPrefix, dbFilename, tables, tableDescriptions))
        throw Exception("Failed to get DB properties");

    _db.reset(new DataBase(dbPrefix, dbFilename, tables, tableDescriptions));
}

std::unique_ptr<DataBase> &DatabaseBuilder::get()
{
    return _db;
}
