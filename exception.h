#ifndef EXCEPTION_H
#define EXCEPTION_H
#include <exception>
#include <QString>
#include <database.h>
class Exception : public std::exception
{
public:
    Exception(QString what, DataBase *db = NULL);

    void show() const throw();

private:
    QString _what;
};

#endif // EXCEPTION_H
