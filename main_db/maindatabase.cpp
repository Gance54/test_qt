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
            product.push_back("Cat=" + cat);
            product.push_back("Name=" + pname);
            productData.erase(productData.begin()); /* erase first line */
            std::for_each(productData.begin(), productData.end(), [&](QString l) {
                if(!l.contains("Requiredpattern"))
                    product.push_back("Description=" + l);
                else
                {
                    QStringList productStrings = l.split("|");
                    if(productStrings.size() != 5)
                        throw Exception ("Failed to get product description from " + pname + ".txt");

                    productStrings.erase(productStrings.begin());
                    productStrings.erase(productStrings.begin());
                    QString conName = productStrings.first();
                    /* get consumables data */
                    if(!consumables.contains(conName))
                    {
                        FileOperations f2(conDir + "/" + conName + ".txt");
                        QStringList conData = f2.getData();
                        if(conData.size() != 1)
                            throw Exception("Failed to get data for consumable " + conName + " from product " + pname);
                        consumables.push_back("Name=" + conName + ";Description=" + conData.first());
                    }
                    product.push_back("Comp=" + productStrings.join("|"));
                }
            });
            products.push_back(product.join(";"));
        });
    });
}
