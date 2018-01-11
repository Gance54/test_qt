#ifndef MAINDATABASE_H
#define MAINDATABASE_H
#include <database.h>

class MainDatabase {
public:
    MainDatabase();
    ~MainDatabase(){}

    void FillData();
    void Block();
    void Unblock();

private:
    std::unique_ptr <DataBase> _d;
    std::unique_ptr <DatabaseBuilder> db;
};

class DBWorker : public QObject {
    Q_OBJECT
public:
    DBWorker(){}
    ~DBWorker(){}

    void stop();
    void resume();
private:
    std::unique_ptr <MainDatabase> _mainDb;

public slots:
    void process();


signals:
    void finished();
};

#endif // MAINDATABASE_H
