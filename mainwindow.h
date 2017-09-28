#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <calendar.h>
#include <listview.h>
#include <database.h>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_Calendar_clicked();
    void on_ProductsButton_clicked();

private:
    Ui::MainWindow *ui;
    Calendar *calendar;
    ListView *products;
    std::unique_ptr <DatabaseBuilder> d;
};

#endif // MAINWINDOW_H
