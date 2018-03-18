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
    QNetworkRequest request;

    ~ListView();

private slots:

    void on_getMarketInfoButton_clicked();
    void replyFinished();
private:
    Ui::ListView *ui;
};

#endif // LISTVIEW_H
