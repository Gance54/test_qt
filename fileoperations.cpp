#include <fileoperations.h>
#include <exception.h>
#include <iostream>
FileOperations::FileOperations(QString filename)
{
    _pFile.open(filename.toStdString());
    if(!_pFile.is_open())
        throw Exception("Failed to open " + filename);

    while(!_pFile.eof())
    {
        std::string line;
        std::getline(_pFile, line);
        _data.push_back(QString::fromStdString(line));
    }
}

FileOperations::~FileOperations()
{
    _pFile.close();
}

QStringList FileOperations::getData()
{
    return _data;
}
