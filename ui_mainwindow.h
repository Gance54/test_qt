/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QPushButton *Calendar;
    QPushButton *ProductsButton;
    QPushButton *InitDatabase;
    QPushButton *lockButton;
    QPushButton *unlockButton;
    QLabel *DbStatusText;
    QLabel *DbStatusLabel;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(400, 297);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        Calendar = new QPushButton(centralWidget);
        Calendar->setObjectName(QStringLiteral("Calendar"));
        Calendar->setGeometry(QRect(10, 10, 80, 22));
        ProductsButton = new QPushButton(centralWidget);
        ProductsButton->setObjectName(QStringLiteral("ProductsButton"));
        ProductsButton->setGeometry(QRect(300, 10, 80, 22));
        InitDatabase = new QPushButton(centralWidget);
        InitDatabase->setObjectName(QStringLiteral("InitDatabase"));
        InitDatabase->setGeometry(QRect(279, 210, 101, 22));
        lockButton = new QPushButton(centralWidget);
        lockButton->setObjectName(QStringLiteral("lockButton"));
        lockButton->setGeometry(QRect(10, 140, 80, 22));
        unlockButton = new QPushButton(centralWidget);
        unlockButton->setObjectName(QStringLiteral("unlockButton"));
        unlockButton->setGeometry(QRect(10, 170, 80, 22));
        DbStatusText = new QLabel(centralWidget);
        DbStatusText->setObjectName(QStringLiteral("DbStatusText"));
        DbStatusText->setGeometry(QRect(10, 220, 71, 16));
        DbStatusLabel = new QLabel(centralWidget);
        DbStatusLabel->setObjectName(QStringLiteral("DbStatusLabel"));
        DbStatusLabel->setGeometry(QRect(80, 220, 71, 16));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 400, 19));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        Calendar->setText(QApplication::translate("MainWindow", "Calendar", 0));
        ProductsButton->setText(QApplication::translate("MainWindow", "Products", 0));
        InitDatabase->setText(QApplication::translate("MainWindow", "Init database", 0));
        lockButton->setText(QApplication::translate("MainWindow", "Lock DB", 0));
        unlockButton->setText(QApplication::translate("MainWindow", "Unlock DB", 0));
        DbStatusText->setText(QApplication::translate("MainWindow", "DB Status:", 0));
        DbStatusLabel->setText(QApplication::translate("MainWindow", "Undefined", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
