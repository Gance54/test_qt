#ifndef PRODUCTLISTWIDGETITEM_H
#define PRODUCTLISTWIDGETITEM_H
#include <QListWidgetItem>
#include "product.h"

class ProductListWidgetItem : public QListWidgetItem
{
public:
    ProductListWidgetItem(Product *p) : _product(p) {}
    Product *GetProduct() { return _product; }

private:

    Product *_product;

    ~ProductListWidgetItem()
    {
        delete _product;
    }
};

#endif // PRODUCTLISTWIDGETITEM_H
