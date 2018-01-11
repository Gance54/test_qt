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

private:
    std::unique_ptr <MainDatabase> _mainDb;

public slots:
    void process();
    void stop();
    void resume();

signals:
    void finished();
};

#endif // MAINDATABASE_H
