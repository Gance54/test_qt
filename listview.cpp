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
#define DATASOURCE "?datasource=tranquility"
#define LANGUAGE "language=en-us"
#define REGION_IDS_URL "https://esi.tech.ccp.is/latest/universe/regions/"
#define CHARACTER_IDS_URL "https://esi.tech.ccp.is/latest/universe/ids/"

ListView::ListView(QDialog *parent) :
    QDialog(parent),
    ui(new Ui::ListView)
{
    ui->setupUi(this);

    _manager = new QNetworkAccessManager();
    QSslConfiguration config = QSslConfiguration::defaultConfiguration();
    config.setProtocol(QSsl::TlsV1_0OrLater);
    _request.setSslConfiguration(config);
    _request.setRawHeader("Content-Type", "application/json");
}

void ListView::SetRequestUrl(const char *url)
{
    _request.setUrl(QUrl(url));
}

ListView::~ListView()
{
    delete ui;
}

QNetworkReply* ListView::Post(QJsonDocument json)
{
    return _manager->post(_request, json.toJson());
}

QNetworkReply* ListView::Get(const char *url)
{
    SetRequestUrl(url);
    return _manager->get(_request);
}

void ListView::DropMessageBox(QString text)
{
    QMessageBox mb;
    mb.setText(text);
    mb.exec();
}

void ListView::CharactersFinished()
{
    QNetworkReply *reply = qobject_cast<QNetworkReply *>(sender());
    QJsonDocument doc = (QJsonDocument::fromJson(reply->readAll()));
    QJsonObject json_obj = doc.object();
    QJsonArray arr = json_obj["characters"].toArray();
    std::list<int> characterIds;
    if(arr.isEmpty())
    {
        DropMessageBox("Empty response. Check spelling");
        return;
    }

    for(auto i=0; i < arr.count(); i++)
    {
        QJsonObject obj =  arr.at(i).toObject();
        characterIds.push_back(obj["id"].toInt());
        DropMessageBox(QString::number(obj["id"].toInt()));
    }

    for(auto i=0; i < arr.count(); i++)
    {
        QJsonObject obj =  arr.at(i).toObject();
        QJsonArray arr;
        arr.append(obj["id"].toString());
        QNetworkReply *reply = Get()
        connect(reply, SIGNAL(finished()), this, SLOT(CharactersFinished()));
    }
}

void ListView::on_getMarketInfoButton_clicked()
{
    SetRequestUrl(CHARACTER_IDS_URL DATASOURCE "&" LANGUAGE);
    QStringList charList = ui->CharactersPlainTextEdit->toPlainText().split(',');
    QJsonArray arr;

    for (auto i = charList.begin(); i < charList.end(); i++)
        arr.append(*i);

    QNetworkReply *reply = Post((QJsonDocument)arr);
    connect(reply, SIGNAL(finished()), this, SLOT(CharactersFinished()));
}
