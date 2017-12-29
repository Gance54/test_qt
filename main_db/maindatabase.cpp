#include <main_db/maindatabase.h>
#include <fileoperations.h>
#include <exception.h>
MainDatabase::MainDatabase()
{
    try {
        db = std::unique_ptr <DatabaseBuilder>(new DatabaseBuilder(DB_MAIN));
        _d = db->get_db();
    }
    catch (Exception e) {
        e.show();
    }
}

void MainDatabase::FillData()
{
    QString dataDir = "data";
    QString catFilename = "categories.txt";
    QString
        catDir = "categories",
        conDir = "consumables",
        prodDir = "products";
    QString filename;

    filename = dataDir + "/" + catFilename;

    FileOperations file(filename);
    QStringList categories = file.getData();

    std::for_each (categories.begin(), categories.end(), [&](QString cat) {
        QStringList c = cat.split("=");
        _d->Insert("categories", {"name"}, {c.last()});
    });


}
