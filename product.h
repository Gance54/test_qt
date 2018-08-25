#ifndef PRODUCT_H
#define PRODUCT_H

#include <list>
#include "order.h"

class Product
{
public:
    Product(int id):_id(id){}
    void AddOrder(QJsonObject json);
private:

    int _id;
    std::list <Order> _buyOrders;
    std::list <Order> _sellOrders;

    //updatable fields
    QString _name;
};

#endif // PRODUCT_H
