#ifndef DATABASE_H
#define DATABASE_H
#include <QtSql>
#include <mutex>
#include <QStringList>
#include <string>
#include <memory>
class DataBase
{
public:
    DataBase(std::string dbPrefix, std::string filename,
             QStringList dbTables, QStringList dbTableDescriptions);

    ~DataBase();
    QStringList getTables();
    static void ShowMessage(QString text);

private:
    static int _total_connections;
    bool _dbValid;
    QSqlDatabase _db;
    std::mutex _m;
    QStringList _tables;
    QStringList _tableDescriptions;

    bool _isDbValid();
    QSqlError _init();
    QSqlError _clear();
};

class DatabaseBuilder
{
public:
    enum DbSet{
        DB_MAIN = 0,

        DB_MAX
    };

    DatabaseBuilder(DbSet dbe);

    static int SetDatabaseDescriptions(DbSet db,
                                       std::string &dbPrefix,
                                       std::string &dbFilename,
                                       QStringList &tables,
                                       QStringList &tableDescriptions);

    static QStringList GetTableFields(DbSet db,
                                      QString table);


    std::unique_ptr<DataBase>& get();

private:
    std::unique_ptr <DataBase> _db;
};

static struct TableDescriptions
{
    std::string dbPrefix;
    std::string dbFilename;
    std::string tables [2];
    QStringList tableDescriptions [2][2];
} descriptions [DatabaseBuilder::DB_MAX] =
{
    "sqlite_db_connection",
    "database.dat",
    {
        "product",
        "image",
    },
    {
        {//product table
            {
                "id",
                "name",
                "description"
            },
            {
                "integer primary key",
                "varchar",
                "varchar"
            },
        },
        {//image table
            {
                "id",
                "description"
            },
            {
                "integer primary key",
                "varchar"
            },
        },
    }
};

#endif // DATABASE_H
