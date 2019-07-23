#include "connectivitymanager.h"
#include <QEventLoop>
#include <QJsonObject>
#include <QMutex>
#include <QMutexLocker>
ConnectivityManager::ConnectivityManager()
{
    _manager = new QNetworkAccessManager();
    QSslConfiguration config = QSslConfiguration::defaultConfiguration();
    config.setProtocol(QSsl::TlsV1_0OrLater);
    _request.setSslConfiguration(config);
    _request.setRawHeader("Content-Type", "application/json");
}

ConnectivityManager::~ConnectivityManager()
{
    delete _manager;
}

void ConnectivityManager::SetRequestUrl(QString url)
{
    _request.setUrl(QUrl(url));
}

QNetworkReply* ConnectivityManager::Post(QString url, QJsonDocument json)
{
    SetRequestUrl(url);
    return _manager->post(_request, json.toJson());
}

QNetworkReply* ConnectivityManager::Get(QString url)
{
    SetRequestUrl(url);
    return _manager->get(_request);
}

QJsonDocument ConnectivityManager::ReadJsonReply(QObject *sender)
{
    QNetworkReply *reply = qobject_cast<QNetworkReply *>(sender);
    return (QJsonDocument::fromJson(reply->readAll()));
}

QJsonDocument ConnectivityManager::_readResponse(QNetworkReply* reply)
{
    QEventLoop loop;
    QObject::connect(reply, SIGNAL(finished()), &loop, SLOT(quit()));
    loop.exec();
    return (QJsonDocument::fromJson(reply->readAll()));
}

QJsonDocument ConnectivityManager::dPost(QString url, QJsonDocument json)
{
    SetRequestUrl(url);
    QNetworkReply* reply = _manager->post(_request, json.toJson());
    return _readResponse(reply);
}

QJsonDocument ConnectivityManager::dGet(QString url)
{
    SetRequestUrl(url);
    QNetworkReply* reply = _manager->get(_request);
    return _readResponse(reply);
}
