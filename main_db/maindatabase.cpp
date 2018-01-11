#include <main_db/maindatabase.h>
#include <fileoperations.h>
#include <exception.h>
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

void MainDatabase::FillData()
{
    QString dataDir = "/home/mike/Dev/testqt/data";
    QString catFilename = "categories.txt";
    QString
        catDir = dataDir + "/" + "categories",
        conDir = dataDir + "/" + "consumables",
        prodDir = dataDir + "/" + "products";
    QString filename = dataDir + "/" + catFilename;

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

    std::cout<<"Reading data... ";

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
    std::cout<<"OK"<<std::endl;
    std::cout<<"Inserting consumables... ";

    /* Insert consumables */
    std::for_each (consumables.begin(), consumables.end(), [&](QString consumable) {
        _d->Insert("consumables", {"name", "description"}, consumable.split("|"));
    });

    std::cout<<"OK"<<std::endl;
    std::cout<<"Inserting categories... ";

    /* Insert categories */
    std::for_each (categories.begin(), categories.end(), [&](QString cat) {
        _d->Insert("categories", {"name"}, { cat });
    });

    std::cout<<"OK"<<std::endl;
    std::cout<<"Inserting products... ";

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

    std::cout<<"OK"<<std::endl;
    std::cout<<"Building communication table... ";

    std::for_each(products.begin(), products.end(), [&](QString prodStr) {
        QStringList prodList = prodStr.split("@");
        QString prodName = *(prodList.begin() + 1);

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
            QSqlQuery query1 = _d->Select("consumables", {"id"}, "name = '" + conName + "'");
            if(!query1.size())
                throw Exception("Can not get consumable " + conName + " from db");
            QString conId = query1.value(0).toString();

            _d->Insert("prod_cons", {"product_id", "consumable_id", "consumable_unit", "consumable_value"},
                                    {prodId, conId, conUnit, conValue });
        });
    });

    std::cout<<"OK"<<std::endl;
    std::cout<<"Data insertion finished!";

    /**/
}
