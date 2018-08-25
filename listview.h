#ifndef LISTVIEW_H
#define LISTVIEW_H
#include <QDialog>
#include "ui_listview.h"
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
    void SetRequestUrl(QString url);
    QNetworkReply *Post(QJsonDocument json);
    QNetworkReply *Get(QString url);
    void DropMessageBox(QString text);

private slots:

    void on_getMarketInfoButton_clicked();
    void on_GetRegions_clicked();

    /* callbacks */
    void OnGetRegionInfoFinished();

    //    void CharactersFinished();
    //    void CharactersDescriptionFinished();
    
private:
    Ui::ListView *ui;
    QNetworkRequest _request;
    QNetworkAccessManager *_manager;

    QJsonDocument _ReadJsonReply();
};

#endif // LISTVIEW_H
