#ifndef CONNECTIVITYMANAGER_H
#define CONNECTIVITYMANAGER_H

#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkRequest>
#include <QtNetwork/QNetworkReply>

class ConnectivityManager
{
public:
    ConnectivityManager();

    QNetworkRequest _request;
    QNetworkAccessManager *_manager;
};

#endif // CONNECTIVITYMANAGER_H
