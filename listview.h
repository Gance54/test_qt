#ifndef LISTVIEW_H
#define LISTVIEW_H
#include <QDialog>
#include "ui_listview.h"
#include "product.h"
#include "connectivitymanager.h"
#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkRequest>
#include <QtNetwork/QNetworkReply>
namespace Ui {
class ListView;
}

class ListView : public QDialog
{
    Q_OBJECT

public:
    explicit ListView(QDialog *parent = 0);
    ~ListView();
    void DropMessageBox(QString text);

private slots:

    void on_getMarketInfoButton_clicked();
    void on_GetRegions_clicked();

    /* callbacks */
    void OnGetRegionInfoFinished();
    void OnGetProductListFinished();
    void OnGetProductNamesFinished();
    void OnGetProductHistoryFinished();
    void OnGetProductOrdersFinished();

    void on_listWidget_itemClicked(QListWidgetItem *item);
    void on_productListWidget_itemClicked(QListWidgetItem *item);

private:
    Ui::ListView *ui;
    ConnectivityManager *_cManager;
    QJsonDocument _ReadJsonReply();
    QList <Product> _products;
};

#endif // LISTVIEW_H
