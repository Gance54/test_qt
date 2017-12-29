#include <main_db/maindatabase.h>
#include <fileoperations.h>

MainDatabase::MainDatabase()
{
    QString dataDir = "data";
    QString catFilename = "categories.txt";
    QString
        catDir = "categories",
        conDir = "consumables",
        prodDir = "products";
    QStringList categories;
    QString filename;

    filename = dataDir + "/" + catFilename;

    FileOperations file(filename);
}
