#ifndef CONNECTIVITYMANAGER_H
#define CONNECTIVITYMANAGER_H

#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkRequest>
#include <QtNetwork/QNetworkReply>
#include <QtNetwork/QSsl>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>

class ConnectivityManager
{
public:
    ConnectivityManager();

    void SetRequestUrl(QString url);
    QNetworkReply *Post(QString url, QJsonDocument json);
    QNetworkReply *Get(QString url);
    QJsonDocument ReadJsonReply(QObject *sender);

private:
    QNetworkRequest _request;
    QNetworkAccessManager *_manager;
};

#endif // CONNECTIVITYMANAGER_H
