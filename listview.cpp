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

#define REGION_IDS_URL "https://esi.tech.ccp.is/latest/universe/regions/"

ListView::ListView(QDialog *parent) :
    QDialog(parent),
    ui(new Ui::ListView)
{
    ui->setupUi(this);

}

ListView::~ListView()
{
    delete ui;
}

void ListView::replyFinished()
{
    QNetworkReply *reply = qobject_cast<QNetworkReply *>(sender());
    QString str = QString::fromStdString((reply->readAll().toStdString()));
    str.remove(0,1);
    str.remove(str.size()-1, 1);
    QStringList arr = str.split(',');
    for (auto i = arr.begin(); i < arr.end(); i++)
    {
        ui->listWidget->addItem(*i);
    }
}


void ListView::on_getMarketInfoButton_clicked()
{
    QNetworkAccessManager *manager = new QNetworkAccessManager();
    QSslConfiguration config = QSslConfiguration::defaultConfiguration();
    config.setProtocol(QSsl::TlsV1_0OrLater);
    request.setSslConfiguration(config);
    request.setUrl(QUrl(REGION_IDS_URL));
    QNetworkReply *reply = manager->get(request);
    connect(reply, SIGNAL(finished()), this, SLOT(replyFinished()));
}
