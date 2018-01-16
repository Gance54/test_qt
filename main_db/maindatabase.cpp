#include <main_db/maindatabase.h>
#include <fileoperations.h>
#include <exception.h>
#include <mainwindow.h>
#include <QRegExp>
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

void MainDatabase::Block()
{
    _d->Block();
}


void MainDatabase::Unblock()
{
    _d->Unblock();
}

typedef struct consSstruct {
    QString id;
    QString name;
} ConsStruct;

void MainDatabase::FillData()
{
    QString dataDir = "/home/mike/Dev/testqt/data";
    QString catFilename = "categories.txt";
    QString
        catDir = dataDir + "/" + "categories",
        conDir = dataDir + "/" + "consumables",
        prodDir = dataDir + "/" + "products";
    QString filename = dataDir + "/" + catFilename;

    gdbLabels.UpdateLabels("Initialization of input data...", "grey");

    QStringList data;
    FileOperations file(filename);
    QStringList
            categories,
            products,
            consumables;

    /* get categories data */
    data = file.getData();
    std::for_each (data.begin(), data.end(), [&](QString cat) {
        QStringList c = cat.split("=");
        categories.push_back(c.last());
    });
    data.clear();

    /* get products data */
    std::for_each (categories.begin(), categories.end(), [&](QString cat) {
        FileOperations f(catDir + "/" + cat + ".txt");
        data = f.getData();
        data.erase(data.begin());

        std::for_each(data.begin(), data.end(), [&](QString line) {
            QStringList text = line.split("=");
            if(text.size() != 2)
                throw Exception ("Failed to get data for category " + cat + "and line " + line);

            QString pname = text.last();
            pname.replace("/", "-");
            FileOperations f1(prodDir + "/" + pname + ".txt");
            QStringList productData = f1.getData();
            QStringList product;
            QStringList productCons;
            product.push_back(cat);
            product.push_back(pname);
            productData.erase(productData.begin()); /* erase first line */
            std::for_each(productData.begin(), productData.end(), [&](QString l) {
                if(!l.contains("Requiredpattern"))
                    product.push_back(l);
                else
                {
                    QStringList productStrings = l.split("|");
                    if(productStrings.size() != 5)
                        throw Exception ("Failed to get product description from " + pname + ".txt");

                    /* erase Requiredpattern and link */
                    productStrings.erase(productStrings.begin());
                    productStrings.erase(productStrings.begin());

                    /* get consumables data */
                    QString conName = productStrings.first();

                    bool present = false;
                    std::for_each(consumables.begin(), consumables.end(), [&](QString cons){
                        QStringList consLst = cons.split("|");
                        if((consLst.first()).contains(conName))
                        {
                            present = true;
                        }
                    });

                    if(!present)
                    {
                        FileOperations f2(conDir + "/" + conName + ".txt");
                        QStringList conData = f2.getData();
                        if(conData.size() != 1)
                            throw Exception("Failed to get data for consumable " + conName + " from product " + pname);
                        /* consumables format = "name|description" */
                        consumables.push_back(conName + "|" + conData.first());
                    }
                    productCons.push_back(productStrings.join("|"));
                }
            });
            product.push_back(productCons.join(";"));
            /* products format = "cat@name@description@con1;con2;..;con#" */
            /* con# format:name|unit|value*/
            products.push_back(product.join("@"));
        });
    });
    gdbLabels.UpdateLabels("Inserting consumables...", "grey");

    /* Insert consumables */
    std::for_each (consumables.begin(), consumables.end(), [&](QString consumable) {
        _d->Insert("consumables", {"name", "description"}, consumable.split("|"));
    });

    QSqlQuery conQuery = _d->Select("consumables", {"id", "name"}, {});
    QList <ConsStruct> ConsList;
    while(1)
    {
        ConsList.push_back({ conQuery.value(0).toString(), conQuery.value(1).toString() });
        if(!conQuery.next())
            break;
    }

    gdbLabels.UpdateLabels("Inserting categories...", "grey");

    /* Insert categories */
    std::for_each (categories.begin(), categories.end(), [&](QString cat) {
        _d->Insert("categories", {"name"}, { cat });
    });

    gdbLabels.UpdateLabels("Inserting products...", "grey");

    /* Insert products */
    std::for_each(products.begin(), products.end(), [&](QString prodStr){
        QStringList prodList = prodStr.split("@");
        bool isDescPresent = prodList.size() == 4 ? true : false;
        QString cat = prodList.first();
        QSqlQuery query = _d->Select("categories", {"id"}, "name = '" + cat + "'");
        if(!query.size())
            throw Exception("Can not get category " + cat + " from db");

        QString catId = query.value(0).toString();
        QString prodName = *(prodList.begin() + 1);
        QString prodDescr;
        if(isDescPresent)
            prodDescr = *(prodList.begin() + 2);
        else
            prodDescr.clear();

        _d->Insert("products", {"name", "description", "category_id"},
                               {prodName, prodDescr, catId});
    });

    std::for_each(products.begin(), products.end(), [&](QString prodStr) {
        QStringList prodList = prodStr.split("@");
        QString prodName = *(prodList.begin() + 1);
        gdbLabels.UpdateLabels("Building communication table for " + prodName + "...", "grey");
        QSqlQuery query = _d->Select("products", {"id"}, "name = '" + prodName + "'");
        if(!query.size())
            throw Exception("Can not get product " + prodName + " from db");
        QString prodId = query.value(0).toString();

        QStringList consList = (prodList.last()).split(";");
        std::for_each(consList.begin(), consList.end(), [&](QString conData) {
            QStringList conDataList = conData.split("|");
            if(conDataList.size() != 3)
                throw Exception ("Invalid consumable data description for " + conData);

            QString conName = conDataList.first();
            QString conUnit = *(conDataList.begin() + 1);
            QString conValue = *(conDataList.begin() + 2);


            QString conId;
            for(int i = 0; i < ConsList.size(); i++)
            {
                auto con = ConsList.begin() + i;
                if(con->name == conName)
                {
                    conId = con->id;
                    break;
                }
            }

            if(conId.isEmpty())
                throw Exception("Failed to get consumable ID for "+ conName + "!!");

            _d->Insert("prod_cons", {"product_id", "consumable_id", "consumable_unit", "consumable_value"},
                                    {prodId, conId, conUnit, conValue });
        });
    });

    gdbLabels.UpdateLabels("Online", "green");

    /**/
}

void DBWorker::process()
{
    try {
        _mainDb = std::unique_ptr <MainDatabase> (new MainDatabase());
        _mainDb->FillData();
    }
    catch (Exception e) {
        e.show();
    }

    emit finished();
    return;
}

void DBWorker::stop()
{
    try {
        _mainDb->Block();
    }
    catch (Exception e) {
        e.show();
    }
}

void DBWorker::resume()
{
    try {
        _mainDb->Unblock();
    }
    catch (Exception e) {
        e.show();
    }
}
