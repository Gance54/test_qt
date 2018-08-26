#ifndef CONNECTIVITYMANAGER_H
#define CONNECTIVITYMANAGER_H

#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkRequest>
#include <QtNetwork/QNetworkReply>
#include <QtNetwork/QSsl>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>

#define DATASOURCE "?datasource=tranquility"
#define LANGUAGE "language=en-us"

#define URL_UNIVERSE_NAMES "https://esi.evetech.net/latest/universe/names/"
#define URL_CHARACTER_PUBLIC_DESCRIPTION "https://esi.evetech.net/latest/characters/"
#define URL_REGIONS "https://esi.evetech.net/latest/universe/regions/"
#define URL_REGION_INFO "https://esi.evetech.net/latest/universe/regions/"
#define URL_MARKET "https://esi.evetech.net/latest/markets/"
#define MARKET_ORDERS "orders"
#define MARKET_HISTORY "history"
#define MARKET_TYPES "types"

#define PRODUCT_TYPE_ID "type_id"

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
