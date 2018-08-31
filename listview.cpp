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
#include "productlistwidgetitem.h"

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
    int total = ui->productListWidget->count();
    int found = 0;
    ui->statusLabel->setText("Left 0 out of " + QString::number(total));
    for (auto i = 0; i < total; i++)
    {
        ProductListWidgetItem *pItem = dynamic_cast<ProductListWidgetItem*>(ui->productListWidget->item(i));
        Product *product = pItem->GetProduct();

        if(!product->isApplicable())
        {
            pItem->setHidden(true);
        }
        else
            ui->statusLabel->setText("Applicable " + QString::number(found) + " out of " + QString::number(total));
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
        ui->statusLabel->setText("Loading page " + QString::number(page) + "...");

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
        int totalCount = productsArray.count();
        for(auto i=0; i < totalCount; i++)
        {
            ui->itemStatusLabel->setText(QString::number(i+1) + " from " + QString::number(totalCount) + " unique items on page " + QString::number(page));
            QJsonObject productJson = productsArray.at(i).toObject();
            Product *p = new Product(productJson["id"].toInt(), regionId, _cManager, productJson["name"].toString(), DAYS);
            ProductListWidgetItem *item = new ProductListWidgetItem(p);
            ui->productListWidget->addItem(item);
        }

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

void ListView::on_resetButton_clicked()
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
