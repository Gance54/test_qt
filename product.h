#ifndef PRODUCT_H
#define PRODUCT_H

#include <list>
#include "order.h"
#include "connectivitymanager.h"
#include <QtCharts/QChartView>
#include <QtCharts/QLineSeries>

QT_CHARTS_USE_NAMESPACE

class Product
{
public:
    enum ChartType {
        CHART_HISTORY,
        CHART_MARKET_STATUS,

        CHART_MAX
    };

    Product(int productId, int regionId, ConnectivityManager *cManager, QString name, int historyDays);
    QString getName() { return _name; }
    int getId() { return _id; }

    void AddOrder(QJsonObject json);
    void AddDailyHistory(QJsonObject json);

    int GetVolumeTotal() { return _volumeTotal; }
    int GetVolimeRemained() { return _volumeRemained; }
    double GetSellPrice () { return _sellPrice; }
    double GetBuyPrice () { return _buyPrice; }
    int GetAverageVolume () { return _averageVolume; }
    QList <DailyHistory> getHistory(){ return _history; }
    QString GetHistoryInfo(int days);
    void FillProductChart(QChart *chart, ChartType type);
    bool isApplicable();

private:

    int _id;
    QList <Order> _buyOrders;
    QList <Order> _sellOrders;
    QList <DailyHistory> _history;
    QString _name;
    ConnectivityManager *_cManager;

    int _volumeRemained;
    int _volumeTotal;
    double _buyPrice;
    double _sellPrice;
    int _averageVolume;
    double _averageCapacity;
    double _average_history_price;

    void _FillHistoryChart(QChart * chart);
};

#endif // PRODUCT_H
