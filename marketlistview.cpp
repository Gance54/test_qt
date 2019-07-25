#include "marketlistview.h"
#include "ui_marketlistview.h"
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
#include <QtConcurrentRun>
#include <cstdio>
#include "product.h"
#include "connectivitymanager.h"
#include "productlistwidgetitem.h"

#define DAYS 200

MarketListView::MarketListView(QDialog *parent) :
    QDialog(parent),
    ui(new Ui::MarketListView)
{
    ui->setupUi(this);
    _cManager = new ConnectivityManager();
}

MarketListView::~MarketListView()
{
    delete ui;
}

void MarketListView::DropMessageBox(QString text)
{
    QMessageBox mb;
    mb.setText(text);
    mb.exec();
}

void MarketListView::on_filterMarketInfoButton_clicked()
{
    int total = ui->productListWidget->count();
    int found = 0;

    for (auto i = 0; i < total; i++)
    {
        ProductListWidgetItem *pItem = dynamic_cast<ProductListWidgetItem*>(ui->productListWidget->item(i));
        Product *product = pItem->GetProduct();

        ui->statusLabel->setText("Applicable " + QString::number(found) + " from " +
                                 QString::number(i) + " out of " + QString::number(total));
        if(!product->isApplicable())
            pItem->setHidden(true);
        else
            found++;

        ui->statusLabel->setText("Applicable " + QString::number(found) + " from " +
                                 QString::number(i) + " out of " + QString::number(total));
    }
}

void MarketListView::OnGetRegionInfoFinished()
{
    QJsonObject obj = _cManager->ReadJsonReply(sender()).object();
    QListWidgetItem *item = new QListWidgetItem();
    item->setText(obj["name"].toString());
    item->setData(Qt::UserRole, obj);
    ui->listWidget->addItem(item);
}

void MarketListView::on_GetRegions_clicked()
{
    QStringList regions = {"10000002","10000043", "10000042"};

    for(auto i=0; i < regions.count(); i++)
    {
        QString url = QString(URL_REGION_INFO) + regions.at(i) + "/" +
                QString(DATASOURCE) + "&" + QString(LANGUAGE);
        QNetworkReply *r = _cManager->Get(url);
        connect(r, SIGNAL(finished()), this, SLOT(OnGetRegionInfoFinished()));
    }
}

void MarketListView::_LoadSingleProductConcurrent(QMutex *mutex, Ui::MarketListView *u, Product *p)
{
    p->LoadProductInfo();
    ProductListWidgetItem *item = new ProductListWidgetItem(p);
    mutex->lock();
    u->productListWidget->addItem(item);
    u->statusLabel->setText("Loaded " + QString::number(u->productListWidget->count()) + " objects...");
    mutex->unlock();
}

void MarketListView::_LoadAllProducts(int regionId)
{
    int pages = 1;
    int total_orders = 0;

    while (true)
    {
        QString url = QString(URL_MARKET) + QString::number(regionId) + "/" +
              QString(MARKET_ORDERS) + "/" + QString(DATASOURCE) +
              QString("&order_type=all&page=") + QString::number(pages);

        QJsonArray ordersArray = _cManager->dGet(url).array();
        int total_on_page = ordersArray.count();
        int loaded = 0;

        if (ordersArray.isEmpty())
        {
            if (pages == 1)
            {
                DropMessageBox("Failed to load products.");
                return;
            }

            DropMessageBox("Loaded all orders!");
            break;
        }

        for (auto i = 0; i < ordersArray.count(); i++)
        {
            QJsonObject orderJson = ordersArray.at(i).toObject();
            for (auto j = 0; j < ui->productListWidget->count(); j++)
            {
                ProductListWidgetItem *pItem = dynamic_cast<ProductListWidgetItem*>(ui->productListWidget->item(j));
                Product *product = pItem->GetProduct();
                if(product->getId() == orderJson["type_id"].toInt())
                {
                    product->AddOrder(orderJson);
                    loaded++;
                    ui->statusLabel->setText("Loaded " + QString::number(loaded) + " from " + QString::number(total_on_page) +
                                             " orders on page " + QString::number(pages));
                }
            }
        }

        total_orders += loaded;

        ui->itemStatusLabel->setText("Loaded " + QString::number(total_orders) + " orders from " +
                                     QString::number(pages) + " pages.");
        pages++;
    }
}

void MarketListView::_GetProductList(int regionId)
{
    int pages = 1;
    int totalCount = 0;
    QJsonArray uniqueIds;

    while (true)
    {
        QString url = QString(URL_MARKET) + QString::number(regionId)
                + "/" + MARKET_TYPES + "/" DATASOURCE + "&page=" + QString::number(pages);

        QJsonArray productIdsArr = _cManager->dGet(url).array();
        if(productIdsArr.isEmpty())
        {
            if(pages == 1)
            {
                DropMessageBox("Can not get product ids for the first page!");
                return;
            }

            break;
        }

        url = QString(URL_UNIVERSE_NAMES) + QString(DATASOURCE);
        QJsonArray productsArray = _cManager->dPost(url, QJsonDocument(productIdsArr)).array();
        int count = productsArray.count();
        for(auto i=0; i < count; i++)
        {
            QJsonObject productJson = productsArray.at(i).toObject();
            Product *p = new Product(productJson["id"].toInt(), regionId, productJson["name"].toString(), DAYS);
            //QtConcurrent::run(_LoadSingleProductConcurrent, &_mutex, ui, p);

            ProductListWidgetItem *item = new ProductListWidgetItem(p);
            ui->productListWidget->addItem(item);
            ui->statusLabel->setText("Loaded " + QString::number(ui->productListWidget->count()) + " objects...");
        }

        totalCount += count;
        ui->itemStatusLabel->setText("Total objects found: " + QString::number(totalCount));
        pages++;

        //TODO: turn this off for release
        //break;
    }
}

void MarketListView::on_listWidget_itemClicked(QListWidgetItem *item)
{
    ui->productListWidget->clear();
    if(!item)
    {
        DropMessageBox("Please select region, bitch");
        return;
    }

    QJsonObject regionData = item->data(Qt::UserRole).toJsonObject();
    int regionId = regionData["region_id"].toInt();
    _GetProductList(regionId);
}

void MarketListView::on_productListWidget_itemClicked(QListWidgetItem *item)
{
    ui->productHistoryTextBrowser->clear();
    ui->productTextBrowser->clear();
    ProductListWidgetItem *pItem = dynamic_cast<ProductListWidgetItem*>(item);
    Product *product = pItem->GetProduct();
    ui->productHistoryTextBrowser->setText(product->GetHistoryInfo(DAYS));
    QChart *chart = new QChart();
    product->FillProductChart(chart, Product::CHART_HISTORY);
    chart->createDefaultAxes();
    chart->setTitle(item->text() + " market history");
    QChartView *chartView = new QChartView(chart);
    chartView->resize(700, 400);
    chartView->show();
}

void MarketListView::on_resetButton_clicked()
{
    int total = ui->productListWidget->count();
    ui->statusLabel->setText("Loaded");
    ui->itemStatusLabel->setText("Loaded");
    for (auto i = 0; i < total; i++)
    {
         ProductListWidgetItem *pItem = dynamic_cast<ProductListWidgetItem*>(ui->productListWidget->item(i));
         pItem->setHidden(false);
    }
}

void MarketListView::on_loadMarketInfoButton_clicked()
{
    int id = ui->listWidget->selectedItems()[0]->data(Qt::UserRole).toJsonObject()["region_id"].toInt();
    _LoadAllProducts(id);
}
