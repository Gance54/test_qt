/********************************************************************************
** Form generated from reading UI file 'listview.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LISTVIEW_H
#define UI_LISTVIEW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QTextEdit>

QT_BEGIN_NAMESPACE

class Ui_ListView
{
public:
    QDialogButtonBox *buttonBox;
    QTextEdit *descriptionText;
    QListWidget *catListWidget;
    QListWidget *prodListWidget;

    void setupUi(QDialog *ListView)
    {
        if (ListView->objectName().isEmpty())
            ListView->setObjectName(QStringLiteral("ListView"));
        ListView->resize(866, 454);
        buttonBox = new QDialogButtonBox(ListView);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(750, 20, 81, 241));
        buttonBox->setOrientation(Qt::Vertical);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        descriptionText = new QTextEdit(ListView);
        descriptionText->setObjectName(QStringLiteral("descriptionText"));
        descriptionText->setGeometry(QRect(280, 50, 371, 381));
        catListWidget = new QListWidget(ListView);
        catListWidget->setObjectName(QStringLiteral("catListWidget"));
        catListWidget->setGeometry(QRect(10, 50, 256, 51));
        prodListWidget = new QListWidget(ListView);
        prodListWidget->setObjectName(QStringLiteral("prodListWidget"));
        prodListWidget->setGeometry(QRect(10, 110, 256, 321));

        retranslateUi(ListView);
        QObject::connect(buttonBox, SIGNAL(accepted()), ListView, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), ListView, SLOT(reject()));

        QMetaObject::connectSlotsByName(ListView);
    } // setupUi

    void retranslateUi(QDialog *ListView)
    {
        ListView->setWindowTitle(QApplication::translate("ListView", "Dialog", 0));
    } // retranslateUi

};

namespace Ui {
    class ListView: public Ui_ListView {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LISTVIEW_H
