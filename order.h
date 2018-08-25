#ifndef ORDER_H
#define ORDER_H

#include <QString>
#include <QJsonObject>

class Order
{
public:
    Order(QJsonObject json){}

private:
    int _id;
    int _locationId;
    int _systemId;
    int _volumeTotal;
    int _volumeRemained;
    float _price;
};
#endif // ORDER_H
