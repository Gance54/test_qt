#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <marketlistview.h>

#include <labelmapper.h>

namespace Ui {
class MainWindow;
}

extern LabelMapper gdbLabels;
extern LabelMapper gdbTransactionLabels;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
void on_ProductsButton_clicked();

private:
    Ui::MainWindow *ui;
    MarketListView *products;
    void *_object;
};

#endif // MAINWINDOW_H
