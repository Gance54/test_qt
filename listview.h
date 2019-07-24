#ifndef LISTVIEW_H
#define LISTVIEW_H
#include <QDialog>
#include "ui_listview.h"
#include "product.h"
#include "connectivitymanager.h"
#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkRequest>
#include <QtNetwork/QNetworkReply>
#include <QThread>
#include <QMutex>

namespace Ui {
class ListView;
}

class ListView : public QDialog
{
    Q_OBJECT

public:
    explicit ListView(QDialog *parent = 0);
    ~ListView();
    static void DropMessageBox(QString text);

private slots:

    void on_getMarketInfoButton_clicked();
    void on_GetRegions_clicked();
    void GetProductList(int regionId);

    /* callbacks */
    void OnGetRegionInfoFinished();

    void on_listWidget_itemClicked(QListWidgetItem *item);
    void on_productListWidget_itemClicked(QListWidgetItem *item);

    void on_resetButton_clicked();

private:
    Ui::ListView *ui;
    QMutex _mutex;
    ConnectivityManager *_cManager;
    QList <Product*> _products;
    static void LoadConcurrent(QMutex *mutex, Ui::ListView *u, Product *p);
};

#endif // LISTVIEW_H
