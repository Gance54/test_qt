#ifndef PRODUCT_H
#define PRODUCT_H

#include <list>
#include "order.h"
#include "connectivitymanager.h"
#include <QtCharts/QChartView>
#include <QtCharts/QLineSeries>
#include <QMutex>
QT_CHARTS_USE_NAMESPACE

#define DEFAULT_DAYS 30

class Product
{
public:
    enum ChartType {
        CHART_HISTORY,
        CHART_MARKET_STATUS,

        CHART_MAX
    };

    Product(int productId, int regionId, QString name, int historyDays = DEFAULT_DAYS);
    ~Product() {}
    void LoadProductInfo();
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
    QMutex *GetMutex();

private:

    bool _loaded;
    int _id;
    int _regionId;
    int _historyDays;
    QList <Order> _buyOrders;
    QList <Order> _sellOrders;
    QList <DailyHistory> _history;
    QString _name;
    QMutex _mutex;

    int _volumeRemained;
    int _volumeSellRemained;
    int _volumeBuyRemained;
    int _volumeTotal;
    double _buyPrice;
    double _sellPrice;
    int _averageVolume;
    double _averageCapacity;
    double _average_history_price;

    void _FillHistoryChart(QChart * chart);
    void _LoadCheck();
};

#endif // PRODUCT_H
