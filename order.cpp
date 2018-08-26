#include "order.h"

Order::Order(QJsonObject json)
{
    _id = json["id"].toInt();
    _locationId = json["location_id"].toInt();
    _price = json["price"].toDouble();
    _systemId = json["system_id"].toInt();
    _volumeRemained = json["volume_remain"].toInt();
    _volumeTotal = json["volume_total"].toInt();
}

DailyHistory::DailyHistory(QJsonObject json)
{
    _average = json["average"].toDouble();
    _date = json["date"].toString();
    _highest = json["highest"].toDouble();
    _lowest = json["lowest"].toDouble();
    _order_count = json["order_count"].toInt();
    _volume = json["volume"].toInt();

    _medium = (_highest + _lowest)/2;
    _capacity = _average * _volume;

    double diff = (_highest - _lowest)/(double)2;

    _bsCoefficient = diff ? (_average - _medium)/diff : 0;
}

double DailyHistory::GetCoefficient() { return _bsCoefficient; }
double DailyHistory::GetHigher() { return _highest; }
double DailyHistory::GetLower() { return _lowest; }
double DailyHistory::GetMedium() { return _medium; }
double DailyHistory::GetAverage() { return _average; }
double DailyHistory::GetCapacity() { return _capacity; }
int DailyHistory::GetVolume() { return _volume; }
QString DailyHistory::GetDate() { return _date; }

