#include "listview.h"
#include "ui_listview.h"
#include <cstdlib>
#include <iostream>
#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkRequest>
#include <QtNetwork/QNetworkReply>
#include <QtNetwork/QSsl>
#include <QMutex>
#include <QMutexLocker>
#include <QMessageBox>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <cstdio>

#include "product.h"

#define DATASOURCE "?datasource=tranquility"
#define LANGUAGE "language=en-us"
#define URL_UNIVERSE_NAMES "https://esi.evetech.net/latest/universe/names/"

#define URL_CHARACTER_PUBLIC_DESCRIPTION "https://esi.evetech.net/latest/characters/"
#define URL_REGIONS "https://esi.evetech.net/latest/universe/regions/"
#define URL_REGION_INFO "https://esi.evetech.net/latest/universe/regions/"

#define URL_MARKET "https://esi.evetech.net/latest/markets/"
#define MARKET_ORDERS "orders"
#define MARKET_ACTIVE_PRODUCTS "types"

#define ORDER_TYPE_SELL "sell"
#define ORDER_TYPE_BUY "buy"
#define ORDER_PAGE "page"
/*https://esi.evetech.net/latest/markets/10000043/orders/?datasource=tranquility&order_type=sell&page=1*/

ListView::ListView(QDialog *parent) :
    QDialog(parent),
    ui(new Ui::ListView)
{
    ui->setupUi(this);
    _cManager = new ConnectivityManager();
}

ListView::~ListView()
{
    delete ui;
}

void ListView::DropMessageBox(QString text)
{
    QMessageBox mb;
    mb.setText(text);
    mb.exec();
}

void ListView::OnGetProductNamesFinished()
{
    QJsonArray productsArray = _cManager->ReadJsonReply(sender()).array();

    if(productsArray.isEmpty())
    {
        DropMessageBox("Can not get at least 1 name as array");
        return;
    }

    for(auto i=0; i < productsArray.count(); i++)
    {
        QJsonObject productJson = productsArray.at(i).toObject();
        Product *product = new Product(productJson["id"].toInt(), _cManager, productJson["name"].toString());
        QListWidgetItem *item = new QListWidgetItem();
        item->setText(product->getName());
        item->setData(Qt::UserRole, product->getId());
        ui->ordersListWidget->addItem(item);
    }
}

void ListView::OnGetProductListFinished()
{
    QJsonArray productIdsArr = _cManager->ReadJsonReply(sender()).array();
    if(productIdsArr.isEmpty())
    {
        DropMessageBox("Failed to get active products in selected region");
        return;
    }

    QJsonArray uniqueIds;

    for(auto i = 0; i < productIdsArr.count(); i++)
    {
        QJsonValue val = productIdsArr.at(i);
        if(!uniqueIds.contains(val))
            uniqueIds.append(val);
    }

    QString url = QString(URL_UNIVERSE_NAMES) + QString(DATASOURCE);
    QNetworkReply *r = _cManager->Post(url, QJsonDocument(uniqueIds));
    connect(r, SIGNAL(finished()), this, SLOT(OnGetProductNamesFinished()));
}

void ListView::on_getMarketInfoButton_clicked()
{
    ui->ordersListWidget->clear();
    QListWidgetItem *item = ui->listWidget->currentItem();
    if(!item)
    {
        DropMessageBox("Please select region, bitch");
        return;
    }

    QJsonObject regionData = item->data(Qt::UserRole).toJsonObject();
    QString url = QString(URL_MARKET) + QString::number(regionData["region_id"].toInt()) + "/" + MARKET_ACTIVE_PRODUCTS + "/" DATASOURCE;

    QNetworkReply *r = _cManager->Get(url);
    connect(r, SIGNAL(finished()), this, SLOT(OnGetProductListFinished()));
}

void ListView::OnGetRegionInfoFinished()
{
    QJsonObject obj = _cManager->ReadJsonReply(sender()).object();
    QListWidgetItem *item = new QListWidgetItem();
    item->setText(obj["name"].toString());
    item->setData(Qt::UserRole, obj);
    ui->listWidget->addItem(item);
}


void ListView::on_GetRegions_clicked()
{
    QStringList regions = {"10000002","10000043"};

    for(auto i=0; i < regions.count(); i++)
    {
        QString url = QString(URL_REGION_INFO) + regions.at(i) + "/" + QString(DATASOURCE) + "&" + QString(LANGUAGE);
        QNetworkReply *r = _cManager->Get(url);
        connect(r, SIGNAL(finished()), this, SLOT(OnGetRegionInfoFinished()));
    }
}

