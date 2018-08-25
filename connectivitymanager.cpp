#include "connectivitymanager.h"

ConnectivityManager::ConnectivityManager()
{
    _manager = new QNetworkAccessManager();
    QSslConfiguration config = QSslConfiguration::defaultConfiguration();
    config.setProtocol(QSsl::TlsV1_0OrLater);
    _request.setSslConfiguration(config);
    _request.setRawHeader("Content-Type", "application/json");
}

void ConnectivityManager::SetRequestUrl(QString url)
{
    _request.setUrl(QUrl(url));
}

QNetworkReply* ConnectivityManager::Post(QJsonDocument json)
{
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
