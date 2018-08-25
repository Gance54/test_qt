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
#define URL_CHARACTER_IDS "https://esi.tech.ccp.is/latest/universe/ids/"
#define URL_CHARACTER_PUBLIC_DESCRIPTION "https://esi.evetech.net/latest/characters/"
#define URL_REGIONS "https://esi.evetech.net/latest/universe/regions/"
#define URL_REGION_INFO "https://esi.evetech.net/latest/universe/regions/"
#define URL_GET_ORDERS "https://esi.evetech.net/latest/markets/10000043/orders/"

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

void ListView::on_getMarketInfoButton_clicked()
{

}

void ListView::OnGetRegionInfoFinished()
{
    QJsonObject obj = _cManager->ReadJsonReply(sender()).object();
    ui->listWidget->addItem(obj["name"].toString());
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

