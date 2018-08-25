#ifndef PRODUCT_H
#define PRODUCT_H

#include <list>
#include "order.h"
#include "connectivitymanager.h"

class Product
{
public:
    Product(int id, ConnectivityManager *cManager, QString name):_id(id)
    {
        _cManager = cManager ? cManager : new ConnectivityManager();
        _name = name;
    }

    QString getName() { return _name; }
    int getId() { return _id; }

    void AddOrder(QJsonObject json);
private:

    int _id;
    std::list <Order> _buyOrders;
    std::list <Order> _sellOrders;
    QString _name;

    ConnectivityManager *_cManager;
};

#endif // PRODUCT_H
