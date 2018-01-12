#ifndef LISTVIEWITEM_H
#define LISTVIEWITEM_H
#include <qlistview.h>
#include <QListWidgetItem>
class ListViewItem : public QListWidgetItem
{
public:
    ListViewItem(QListView *listView, QString text, QVariant data):
        _text(text), _data(data), _listView(listView){}

    ListViewItem(QListView *listView, QString text, QString data):
        _text(text), _data(data), _listView(listView){}

    QString text() const;
    QString description() const;
    QVariant data() const;

private:
    QString _text;
    QVariant _data;
    QListView *_listView;
};

#endif // LISTVIEWITEM_H
