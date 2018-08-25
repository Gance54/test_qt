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
#define MARKET_HISTORY "history"
#define MARKET_TYPES "types"

#define PRODUCT_TYPE_ID "type_id"

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
        Product *product = new Product(productJson["id"].toInt(), _cManager,
                productJson["name"].toString());
        QListWidgetItem *item = new QListWidgetItem();
        item->setText(product->getName());
        item->setData(Qt::UserRole, product->getId());
        ui->productListWidget->addItem(item);
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

void ListView::OnGetProductOrdersFinished()
{
    QJsonArray arr = _cManager->ReadJsonReply(sender()).array();
    /*for (auto i = 0; i < arr.count(); i++)
    {
        QJsonObject object = arr.at(i);

    }*/
}

void ListView::OnGetProductHistoryFinished()
{
    ui->productHistoryTextBrowser->clear();
    QJsonArray arr = _cManager->ReadJsonReply(sender()).array();
    QString text;

    for (auto i = 0; i < arr.count(); i++)
    {
        QJsonObject object = arr.at(i).toObject();
        text += object["date"].toString() + " : " +
                QString::number(object["lowest"].toDouble(), 'f', 2) + ", " +
                QString::number(object["average"].toDouble(), 'f', 2) + ", " +
                QString::number(object["highest"].toDouble(), 'f', 2) + ". " +
                QString("Volume : ") + QString::number(object["volume"].toInt()) + "\n";
    }

    ui->productHistoryTextBrowser->setText(text);
}

void ListView::on_getMarketInfoButton_clicked()
{
    for (auto i = 0; i < ui->productListWidget->count(); i++)
    {
        itemId = ui->productListWidget->item(i)->data(Qt::UserRole).toInt();
        QString url = QString(URL_MARKET) + QString::number(regionId) + "/" +
                QString(MARKET_ORDERS) + "/" + QString(DATASOURCE) + "&" +
                QString(PRODUCT_TYPE_ID) + QString("=") + QString::number(productId);

        QNetworkReply *r = _cManager->Get(url);
        connect(r, SIGNAL(finished()), this, SLOT(OnGetProductOrdersFinished()));
    }
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
        QString url = QString(URL_REGION_INFO) + regions.at(i) + "/" +
                QString(DATASOURCE) + "&" + QString(LANGUAGE);
        QNetworkReply *r = _cManager->Get(url);
        connect(r, SIGNAL(finished()), this, SLOT(OnGetRegionInfoFinished()));
    }
}

void ListView::on_listWidget_itemClicked(QListWidgetItem *item)
{
    ui->productListWidget->clear();
    if(!item)
    {
        DropMessageBox("Please select region, bitch");
        return;
    }

    QJsonObject regionData = item->data(Qt::UserRole).toJsonObject();
    QString url = QString(URL_MARKET) + QString::number(regionData["region_id"].toInt())
            + "/" + MARKET_TYPES + "/" DATASOURCE;

    QNetworkReply *r = _cManager->Get(url);
    connect(r, SIGNAL(finished()), this, SLOT(OnGetProductListFinished()));
}

void ListView::on_productListWidget_itemClicked(QListWidgetItem *item)
{
    ui->productHistoryTextBrowser->clear();
    ui->productTextBrowser->clear();
    int regionId = (ui->listWidget->currentItem()->data(Qt::UserRole).toJsonObject())["region_id"].toInt();
    int productId = item->data(Qt::UserRole).toInt();
    QString url = QString(URL_MARKET) + QString::number(regionId) + "/" +
            QString(MARKET_HISTORY) + "/" + QString(DATASOURCE) + "&" +
            QString(PRODUCT_TYPE_ID) + QString("=") + QString::number(productId);

    QNetworkReply *r = _cManager->Get(url);
    connect(r, SIGNAL(finished()), this, SLOT(OnGetProductHistoryFinished()));
}
