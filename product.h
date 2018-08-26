#ifndef PRODUCT_H
#define PRODUCT_H

#include <list>
#include "order.h"
#include "connectivitymanager.h"

class Product
{
public:
    Product(int productId, int regionId, ConnectivityManager *cManager, QString name);
    QString getName() { return _name; }
    int getId() { return _id; }

    void AddOrder(QJsonObject json);
    void AddDailyHistory(QJsonObject json);
private:

    int _id;
    QList <Order> _buyOrders;
    QList <Order> _sellOrders;
    QList <DailyHistory> _history;
    QString _name;

    ConnectivityManager *_cManager;
};

#endif // PRODUCT_H
