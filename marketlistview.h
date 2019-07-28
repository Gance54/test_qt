#ifndef LISTVIEW_H
#define LISTVIEW_H
#include <QDialog>
#include "ui_marketlistview.h"
#include "product.h"
#include "connectivitymanager.h"
#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkRequest>
#include <QtNetwork/QNetworkReply>
#include <QThread>
#include <QMutex>

namespace Ui {
class MarketListView;
}

class MarketHashView : public Ui::MarketListView {};

class MarketListView : public QDialog
{
    Q_OBJECT

public:
    explicit MarketListView(QDialog *parent = nullptr);
    ~MarketListView();
    static void DropMessageBox(QString text);

private slots:

    void on_filterMarketInfoButton_clicked();
    void on_GetRegions_clicked();

    /* callbacks */
    void OnGetRegionInfoFinished();

    void on_listWidget_itemClicked(QListWidgetItem *item);
    void on_productListWidget_itemClicked(QListWidgetItem *item);

    void on_resetButton_clicked();

    void on_loadMarketInfoButton_clicked();

private:
    MarketHashView *ui;
    ConnectivityManager *_cManager;
    QList <Product*> _products;

    static void _LoadProductPageConcurrent(QJsonArray ordersArray, MarketHashView *u);

    void _GetProductList(int regionId);
    void _LoadAllProducts(int regionId);
};

#endif // LISTVIEW_H
