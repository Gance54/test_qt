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
    void SetRequestUrl(const char *url);
    QNetworkReply *Post(QJsonDocument json);
    QNetworkReply *Get(const char *url);
    void DropMessageBox(QString text);

private slots:

    void on_getMarketInfoButton_clicked();
    void CharactersFinished();
private:
    Ui::ListView *ui;
    QNetworkRequest _request;
    QNetworkAccessManager *_manager;
};

#endif // LISTVIEW_H
