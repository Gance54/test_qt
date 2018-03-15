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
    QMessageBox msgBox;
    msgBox.setText(QString::number(reply->bytesAvailable()));
    msgBox.exec();
}


void ListView::on_getMarketInfoButton_clicked()
{
    QNetworkAccessManager *manager = new QNetworkAccessManager();

    QSslConfiguration config = QSslConfiguration::defaultConfiguration();
    config.setProtocol(QSsl::TlsV1_0OrLater);
    request.setSslConfiguration(config);
    request.setUrl(QUrl("https://esi.tech.ccp.is/latest/universe/regions/"));

    connect(manager, SIGNAL(finished(QNetworkReply*)), this,
                     SLOT(replyFinished()));

    reply = manager->get(request);
}
