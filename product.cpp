#include "product.h"

Product::Product(int productId, int regionId, ConnectivityManager *cManager, QString name)
{
    _id = productId;
    _cManager = cManager ? cManager : new ConnectivityManager();
    _name = name;

    QString url = QString(URL_MARKET) + QString::number(regionId) + "/" +
            QString(MARKET_ORDERS) + "/" + QString(DATASOURCE) + "&" +
            QString(PRODUCT_TYPE_ID) + QString("=") + QString::number(productId);

    QJsonArray ordersArray = QJsonDocument::fromJson(_cManager->Get(url)->readAll()).array();
    for(auto i = 0; i < ordersArray.count(); i++)
        AddOrder(ordersArray.at(i).toObject());

    url = QString(URL_MARKET) + QString::number(regionId) + "/" +
                QString(MARKET_HISTORY) + "/" + QString(DATASOURCE) + "&" +
                QString(PRODUCT_TYPE_ID) + QString("=") + QString::number(productId);

    QJsonArray ordersHistory = QJsonDocument::fromJson(_cManager->Get(url)->readAll()).array();
    for(auto i = 0; i < ordersHistory.count(); i++)
        AddDailyHistory(ordersHistory.at(i).toObject());
}

void Product::AddDailyHistory(QJsonObject json)
{
    DailyHistory history(json);
    _history.push_back(history);
}

void Product::AddOrder(QJsonObject json)
{
    bool isBuy = json["is_buy_order"].toBool();

    Order order(json);

    if(isBuy)
        _buyOrders.push_back(order);
    else
        _sellOrders.push_back(order);
}
