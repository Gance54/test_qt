#ifndef FILEOPERATIONS_H
#define FILEOPERATIONS_H
#include <fstream>
#include <iostream>
#include <QStringList>

class FileOperations
{
public:
    FileOperations(QString filename);
    ~FileOperations();

    QStringList getData();
private:
    std::ifstream _pFile;
    QStringList _data;
};
#endif // FILEOPERATIONS_H
