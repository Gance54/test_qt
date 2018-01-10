#include "database.h"
#include <QMessageBox>
#include <exception.h>
#include <main_db/maindatabase.h>
#include <iostream>
#include <QSqlQuery>
#define DB_CONNESTION_PREFIX "sqlite_db_connection"
#define DB_FILENAME "database.dat"
#define DB_DRIVER "QSQLITE"
#define DESCRYPTION_SEPARATOR ","
#define FIELD_SEPARATOR " "

int DataBase::_total_connections = 0;

DataBase::DataBase(DbSet dbe, std::string dbPrefix, std::string filename,
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
        _dbValid = _IsDbValid();

        if(!_dbValid)
        {
            try {
                _Clear();
                _Init();
            }
            catch (Exception e) {
                e.show();
            }
        }
    }
    else
        throw Exception ("Failed to open db");

    _m.unlock();

    if(dbe >= DB_MAX)
        throw Exception ("There is no database with requested dbSet");

    _dbe = dbe;
}

QSqlError DataBase::_Init()
{
    if(_db.isOpen() && !_db.tables().count())
    {
        if(!_tables.count() || _tables.count() != _tableDescriptions.count())
            throw Exception(QString::fromStdString("Invalid database format"));

        for(auto t = _tables.begin(), d = _tableDescriptions.begin();
            t != _tables.end(), d != _tableDescriptions.end(); t++, d++)
        {
            QString query = QString::fromStdString("Create table '" + t->toStdString() + "' (" + d->toStdString() + ")");
            _Execute(query);
        }
    }
    else
        throw Exception("DB is not opened or already initialized");

    return QSqlError();
}

QSqlError DataBase::_Clear()
{
    if(!_db.isOpen())
        throw Exception("DB is not open", this);

    if(!_db.tables().size())
        return QSqlError();

    while(_db.tables().size()) {
        QString query("Drop table '");
        query.append(*(_db.tables().begin()));
        query.append("'");
        _Execute(query);
    }

    return QSqlError();
}

QSqlQuery DataBase::_Execute(QString queryString)
{
    QSqlQuery query (_db);
    std::cout<<"<<<<<<<<<<<<<<<<<<<<<<<<NEW REQUEST>>>>>>>>>>>>>>>>>>>>>>>>>>"<<std::endl;
    std::cout<<queryString.toStdString()<<std::endl;

    if(!query.exec(queryString))
        throw Exception("Error '" + query.lastError().text() +" on request '" + queryString + "'");

    return query;
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
     std::cout<<"DESTR!!!"<<std::endl;
}

QStringList DataBase::getTables()
{
    return _db.tables();
}

void DataBase::Insert(QString table, QStringList fields, QStringList values)
{
    QSqlQuery query (_db);
    QString queryString = "INSERT INTO " + table + " ('" + fields.join("','") + "') values('" +
            values.join("','") + "')";

    _Execute(queryString);
}

QSqlQuery DataBase::Select(QString table, QStringList fields, QString conditions)
{
    QString queryString = "SELECT " + fields.join(",") + " FROM " + table;
    if(!conditions.isEmpty())
        queryString += " WHERE " + conditions;

    QSqlQuery q = _Execute(queryString);
    if(!q.next())
        throw Exception("Failed to get valid position");
    return q;
}

void DataBase::ShowMessage(QString text)
{
    QMessageBox msgBox;
    msgBox.setText(text);
    msgBox.exec();
}

bool DataBase::_IsDbValid()
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
        throw Exception("Invalid database number");

    dbPrefix = descriptions[db].dbPrefix;
    dbFilename = descriptions[db].dbFilename;

    if(sizeof(descriptions[db].tables)/sizeof(descriptions[db].tables[0]) !=
       sizeof(descriptions[db].tableDescriptions)/sizeof(descriptions[db].tableDescriptions[0]))
        throw Exception("Invalid DB tables and descriptions");

    for(size_t i = 0; i < sizeof(descriptions[db].tableDescriptions)/sizeof(descriptions[db].tableDescriptions[0]); i++)
        if(descriptions[db].tableDescriptions[i][0].size() != descriptions[db].tableDescriptions[i][1].size())
            throw Exception("Incompatible DB initialization.");

    for(size_t i = 0; i < sizeof(descriptions[db].tables)/sizeof(descriptions[db].tables[0]); i++)
    {
        QString description;

        for(auto field = descriptions[db].tableDescriptions[i][0].begin(), desc = descriptions[db].tableDescriptions[i][1].begin();
            field != descriptions[db].tableDescriptions[i][0].end(), desc != descriptions[db].tableDescriptions[i][1].end();
            field++, desc++)
        {
            description.append(*field + QString::fromStdString(FIELD_SEPARATOR) + *desc);
            if(field != descriptions[db].tableDescriptions[i][0].end() - 1)
                description.append(DESCRYPTION_SEPARATOR);
        }

        tables.push_back(QString::fromStdString(descriptions[db].tables[i]));

        std::cout<<description.toStdString()<<";"<<std::endl;
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

    _db.reset(new DataBase(dbe, dbPrefix, dbFilename, tables, tableDescriptions));
}

std::unique_ptr<DataBase> DatabaseBuilder::get_db()
{
    return std::move(_db);
}
