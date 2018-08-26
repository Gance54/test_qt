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
#include "connectivitymanager.h"

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
        QListWidgetItem *item = new QListWidgetItem();
        item->setText( productJson["name"].toString());
        item->setData(Qt::UserRole, productJson["id"].toInt());
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

void ListView::OnGetProductHistoryFinished()
{
    ui->productHistoryTextBrowser->clear();
    QJsonArray arr = _cManager->ReadJsonReply(sender()).array();
    QString text;

    for (auto i = 0; i < arr.count(); i++)
    {
        DailyHistory history(arr.at(i).toObject());

        text += history.GetDate() + ": \n" +
                "Capacity: " + QString::number(history.GetCapacity(), 'f', 2) + "\n" +
                "Volume: " + QString::number(history.GetVolume()) + "\n" +
                "Medium: " + QString::number(history.GetMedium(), 'f', 2) + "\n" +
                "Average: " + QString::number(history.GetAverage(), 'f', 2) + "\n" +
                "Higher: " + QString::number(history.GetHigher(), 'f', 2) + "\n" +
                "Lower: " + QString::number(history.GetLower(), 'f', 2) + "\n" +
                "Coef: " + QString::number(history.GetCoefficient(), 'f', 2) + "\n\n";


        /*QJsonObject object = arr.at(i).toObject();
        text += object["date"].toString() + " : " +
                QString::number(object["lowest"].toDouble(), 'f', 2) + ", " +
                QString::number(object["average"].toDouble(), 'f', 2) + ", " +
                QString::number(object["highest"].toDouble(), 'f', 2) + ". " +
                QString("Volume : ") + QString::number(object["volume"].toInt()) + "\n";*/
    }

    ui->productHistoryTextBrowser->setText(text);
}

void ListView::on_getMarketInfoButton_clicked()
{
    int regionId = (ui->listWidget->currentItem()->data(Qt::UserRole).toJsonObject())["region_id"].toInt();

    for (auto i = 0; i < ui->productListWidget->count(); i++)
    {
        int productId = ui->productListWidget->item(i)->data(Qt::UserRole).toInt();
        Product *product = new Product(productId, regionId, _cManager, ui->productListWidget->item(i)->text());
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
