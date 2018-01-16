#ifndef DATABASE_H
#define DATABASE_H
#include <QtSql>
#include <mutex>
#include <QStringList>
#include <QThread>
#include <QObject>
#include <string>
#include <memory>
#define PRIMARY_KEY_STR " primary key"
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
    void Insert(QString table, QStringList fields, QStringList values);
    QSqlQuery Select(QString table, QStringList fields, QString conditions);
    void Update(QString table, QStringList fields, QString conditions);

    static void ShowMessage(QString text);
    void Block();
    void Unblock();
    bool IsBlocked();

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
    QSqlQuery _Execute(QString queryString);
    int _transaction_count;
    bool _blocked;
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
    std::string tables [5];
    //tableDescriptions[TABLES][FIELD_NAME_LIST;FIELD_TYPE_LIST]
    QStringList tableDescriptions [5][2];
} descriptions [DB_MAX] =
{
    "sqlite_db_connection",
    "database.dat",
    {
        "products",
        "categories",
        "consumables",
        "prod_cons",
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
            },
            {
                "integer" PRIMARY_KEY_STR,
                "varchar",
                "varchar",
                "integer",
                "integer",
            },
        },
        {//categories table
            {
                "id",
                "name",
                "description"
            },
            {
                "integer" PRIMARY_KEY_STR,
                "varchar",
                "varchar"
            }
        },
        {//consumables table
            {
                "id",
                "name",
                "description"
            },
            {
                "integer" PRIMARY_KEY_STR,
                "varchar",
                "varchar"
            }
        },
        {//prod_cons table
            {
                "id",
                "product_id",
                "consumable_id",
                "consumable_unit",
                "consumable_value"
            },
            {
                "integer" PRIMARY_KEY_STR,
                "integer",
                "integer",
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
                "integer" PRIMARY_KEY_STR,
                "varchar"
            },
        },
    }
};

#endif // DATABASE_H
