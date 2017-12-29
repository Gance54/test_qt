#ifndef MAINDATABASE_H
#define MAINDATABASE_H
#include <database.h>

class MainDatabase {
public:
    MainDatabase();
    ~MainDatabase(){}

    void FillData();

private:
    std::unique_ptr <DataBase> _d;
    std::unique_ptr <DatabaseBuilder> db;
};

#endif // MAINDATABASE_H
