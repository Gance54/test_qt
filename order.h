#ifndef ORDER_H
#define ORDER_H

#include <QString>
#include <QJsonObject>

class Order
{
public:
    Order(QJsonObject json);

private:
    int _id;
    int _locationId;
    int _systemId;
    int _volumeTotal;
    int _volumeRemained;
    float _price;
};

class DailyHistory
{
public:
    DailyHistory(QJsonObject json);

    double GetCoefficient();
    double GetMedium();
    double GetCapacity();
    double GetHigher();
    double GetLower();
    int GetVolume();
    QString GetDate();
    double GetAverage();

private:
    double _average;
    QString _date;
    double _highest;
    double _lowest;
    int _order_count;
    int _volume;

    double _medium;
    double _capacity;

    //coefficient of buy/sell orders
    // [-1..+1]
    // -1 - dominating buy orders
    // +1 - dominating sell orders
    double _bsCoefficient;
};
#endif // ORDER_H
