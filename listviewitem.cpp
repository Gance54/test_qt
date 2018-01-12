#include "listviewitem.h"

QString ListViewItem::text() const
{
    return _text;
}

QString ListViewItem::description() const
{
    return _data.toString();
}

QVariant ListViewItem::data() const
{
    return _data;
}
