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

#define DAYS 200

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

void ListView::on_getMarketInfoButton_clicked()
{
    int regionId = (ui->listWidget->currentItem()->data(Qt::UserRole).toJsonObject())["region_id"].toInt();
    for (auto i = 0; i < ui->productListWidget->count(); i++)
    {
        ui->statusLabel->setText("Left " + QString::number(i) + " out of " + QString::number(ui->productListWidget->count()));
        QListWidgetItem *item = ui->productListWidget->item(i);
        int productId = item->data(Qt::UserRole).toInt();
        Product *product = new Product(productId, regionId, _cManager, item->text(), 0);
        if(!product->isApplicable())
        {
            delete item;
            i--;
        }
        delete product;
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

void ListView::GetProductList(int regionId)
{
    int page = 1;
    int pageSize = 0;
    QJsonArray uniqueIds;

    while(true)
    {
        QString url = QString(URL_MARKET) + QString::number(regionId)
                + "/" + MARKET_TYPES + "/" DATASOURCE + "&page=" + QString::number(page);

        QJsonArray productIdsArr = _cManager->dGet(url).array();
        QJsonArray CurrentIdsArr;
        if(productIdsArr.isEmpty())
        {
            if(page == 1)
            {
                DropMessageBox("Can not get product ids for the first page!");
                return;
            }
            return;
        }

        if(!pageSize)
            pageSize = productIdsArr.count();

        for(auto i = 0; i < productIdsArr.count(); i++)
        {
            QJsonValue val = productIdsArr.at(i);
            if(!uniqueIds.contains(val))
            {
                uniqueIds.append(val);
                CurrentIdsArr.append(val);
            }
        }

        url = QString(URL_UNIVERSE_NAMES) + QString(DATASOURCE);
        QJsonArray productsArray = _cManager->dPost(url, QJsonDocument(CurrentIdsArr)).array();
        for(auto i=0; i < productsArray.count(); i++)
        {
            QJsonObject productJson = productsArray.at(i).toObject();
            QListWidgetItem *item = new QListWidgetItem();
            item->setText( productJson["name"].toString());
            item->setData(Qt::UserRole, productJson["id"].toInt());
            ui->productListWidget->addItem(item);
        }

        ui->statusLabel->setText("Loading... Page " + QString::number(page) + ". Total: " + QString::number(uniqueIds.count()));
        page++;
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
    int regionId = regionData["region_id"].toInt();
    GetProductList(regionId);
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

    Product product(productId, regionId, _cManager, item->text(), DAYS);

    QString text = product.GetHistoryInfo(DAYS);
    ui->productHistoryTextBrowser->setText(text);

    QChart *chart = new QChart();
    product.FillProductChart(chart, Product::CHART_HISTORY);
    chart->createDefaultAxes();
    chart->setTitle(item->text() + " market history");
    QChartView *chartView = new QChartView(chart);
    chartView->resize(700, 400);
    chartView->show();
}

void ListView::on_productListWidget_itemDoubleClicked(QListWidgetItem *item)
{

}
