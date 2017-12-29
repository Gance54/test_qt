#ifndef DATABASE_H
#define DATABASE_H
#include <QtSql>
#include <mutex>
#include <QStringList>
#include <string>
#include <memory>

enum DbSet{
    DB_MAIN = 0,

    DB_MAX
};

class DataBase
{
public:
    DataBase(DbSet dbe, std::string dbPrefix, std::string filename,
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
    DbSet _dbe;

    bool _IsDbValid();
    QSqlError _Init();
    QSqlError _Clear();
};

class DatabaseBuilder
{
public:

    DatabaseBuilder(DbSet dbe);

    static int SetDatabaseDescriptions(DbSet db,
                                       std::string &dbPrefix,
                                       std::string &dbFilename,
                                       QStringList &tables,
                                       QStringList &tableDescriptions);

    static QStringList GetTableFields(DbSet db,
                                      QString table);


    std::unique_ptr<DataBase> get_db();

private:
    std::unique_ptr <DataBase> _db;
};

static struct TableDescriptions
{
    std::string dbPrefix;
    std::string dbFilename;
    std::string tables [4];
    QStringList tableDescriptions [4][2];
} descriptions [DB_MAX] =
{
    "sqlite_db_connection",
    "database.dat",
    {
        "products",
        "categories",
        "consumables",
        "images",
    },
    {
        {//products table
            {
                "id",
                "name",
                "description",
                "category_id",
                "image_id",
                "consumables",
            },
            {
                "integer primary key",
                "varchar",
                "varchar",
                "integer",
                "integer",
                "varchar",
            },
        },
        {//categories table
            {
                "id",
                "name",
                "description"
            },
            {
                "integer primary key",
                "varchar",
                "varchar"
            }
        },
        {//comsumables table
            {
                "id",
                "name",
                "description"
            },
            {
                "integer primary key",
                "varchar",
                "varchar"
            }
        },
        {//images table
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
