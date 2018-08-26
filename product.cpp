#include "product.h"
#include "listview.h"
#include <QColor>
#define JITA_ID 30000142

Product::Product(int productId, int regionId, ConnectivityManager *cManager, QString name, int historyDays)
{
    int totalHistoryVolume = 0;
    double totalHistoryCapacity = 0;
    if(!historyDays)
        historyDays = 30;
    _id = productId;
    _cManager = cManager ? cManager : new ConnectivityManager();
    _name = name;
    _buyPrice = 0;
    _sellPrice = 0;
    _volumeTotal = 0;
    _volumeRemained = 0;

    QString url = QString(URL_MARKET) + QString::number(regionId) + "/" +
            QString(MARKET_ORDERS) + "/" + QString(DATASOURCE) + "&" +
            QString(PRODUCT_TYPE_ID) + QString("=") + QString::number(productId);

    QJsonArray ordersArray = _cManager->dGet(url).array();
    for(auto i = 0; i < ordersArray.count(); i++)
        AddOrder(ordersArray.at(i).toObject());

    url = QString(URL_MARKET) + QString::number(regionId) + "/" +
                QString(MARKET_HISTORY) + "/" + QString(DATASOURCE) + "&" +
                QString(PRODUCT_TYPE_ID) + QString("=") + QString::number(productId);

    QJsonArray ordersHistory = _cManager->dGet(url).array();

    if(historyDays >= ordersHistory.count())
    {
        ListView::DropMessageBox("History for " + QString::number(historyDays) + " not available");
        return;
    }

    for(auto i = ordersHistory.count() - 1; i >= ordersHistory.count() - historyDays; i--)
        AddDailyHistory(ordersHistory.at(i).toObject());

    for (auto i = 0; i < _buyOrders.count(); i++)
    {
        Order o = _buyOrders.at(i);
        double buyPrice = o.getPrice();

        if(_buyPrice < buyPrice)
            _buyPrice = buyPrice;

        _volumeTotal += o.GetVolumeTotal();
        _volumeRemained += o.GetVolumeRemained();
    }

    if(_sellOrders.count())
    {
        Order o = _sellOrders.at(0);
        _sellPrice = o.getPrice();
    }

    for (auto i = 0; i < _sellOrders.count(); i++)
    {
        Order o = _sellOrders.at(i);
        double sellPrice = o.getPrice();

        if(_sellPrice > sellPrice)
            _sellPrice = sellPrice;

        _volumeTotal += o.GetVolumeTotal();
        _volumeRemained += o.GetVolumeRemained();
    }

    for (auto i = 0; i < _history.count(); i++)
    {
        DailyHistory h = _history.at(i);
        totalHistoryVolume += h.GetVolume();
        totalHistoryCapacity += h.GetCapacity();
    }

    _averageVolume = totalHistoryVolume/_history.count();
    _averageCapacity = totalHistoryCapacity/_history.count();
}

void Product::AddDailyHistory(QJsonObject json)
{
    DailyHistory history(json);
    _history.push_back(history);
}

QString Product::GetHistoryInfo(int days)
{
    if(days > _history.count())
        return QString("No history saved for " + QString::number(days) + " days");

    QString text;
    for (auto i = 0; i <days; i++)
    {
        DailyHistory dh = _history.at(i);
        text += "Date: " + dh.GetDate() + "\n";
        text += "Volume: " + QString::number(dh.GetVolume()) + "\n";
        text += "    Highest: " + QString::number(dh.GetHigher(), 'f', 2) + "\n";
        text += "    Lowest: " + QString::number(dh.GetLower(), 'f', 2) + "\n";
        text += "        Average: " + QString::number(dh.GetAverage(), 'f', 2) + "\n";
        text += "        Medium: " + QString::number(dh.GetMedium(), 'f', 2) + "\n";
        text += "            Koeficient: " + QString::number(dh.GetCoefficient(), 'f', 2) + "\n\n";
    }

    return text;
}

void Product::_FillHistoryChart(QChart *chart)
{
     QLineSeries *averageSeries = new QLineSeries();
     QLineSeries *mediumSeries = new QLineSeries();
     averageSeries->setName("Average");
     averageSeries->setColor(QColor("green"));
     mediumSeries->setName("Medium");
     mediumSeries->setColor(QColor("red"));

     for (auto i = _history.count() -1 ; i >= 0; i--)
     {
         DailyHistory dh = _history.at(i);
         averageSeries->append(i, dh.GetAverage());
         mediumSeries->append(i, dh.GetMedium());
     }

     chart->addSeries(averageSeries);
     chart->addSeries(mediumSeries);
}

void Product::FillProductChart(QChart *chart, ChartType type)
{
    if(type == ChartType::CHART_HISTORY)
        return _FillHistoryChart(chart);
}

bool Product::isApplicable()
{
    double diff = _sellPrice - _buyPrice;
    double koef = 0.15;
    if(_averageVolume < 50)
        return false;

    if(_averageCapacity < 10000000000)
        return false;

    if(diff <= 0)
        return false;

    if(diff/_buyPrice < koef)
        return false;

    return true;
}

void Product::AddOrder(QJsonObject json)
{
    bool isBuy = json["is_buy_order"].toBool();

    Order order(json);

    if(isBuy)
        _buyOrders.push_back(order);
    else
    {
        if(order.GetSystemId() == JITA_ID)
            _sellOrders.push_back(order);
    }
}
