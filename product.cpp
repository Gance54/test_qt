#include "product.h"

void Product::AddOrder(QJsonObject json)
{
    bool isBuy = json["is_buy_order"].toBool();

    Order order(json);

    if(isBuy)
        _buyOrders.push_back(order);
    else
        _sellOrders.push_back(order);
}
