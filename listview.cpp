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
#include <QtConcurrentRun>
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
    QStringList regions = {"10000002","10000043", "10000042"};

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
    int pages = 1;
    int totalCount = 0;
    QJsonArray uniqueIds;

    while(true)
    {
        ui->statusLabel->setText("Loading page " + QString::number(pages) + "...");

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

            QtConcurrent::run([&]() {
                ProductListWidgetItem *item = new ProductListWidgetItem(p);
                ui->productListWidget->addItem(item);
                p->LoadProductInfo();
                ui->statusLabel->setText("Loaded " + QString::number(ui->productListWidget->count()) + " objects...");
            });
        }

        totalCount += count;
        ui->itemStatusLabel->setText("Total objects found: " + QString::number(totalCount));
        pages++;

        break;
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
