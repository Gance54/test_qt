#ifndef CALENDAR_H
#define CALENDAR_H
#include <QDialog>

namespace Ui {
class Calendar;
}

class Calendar : public QDialog
{
    Q_OBJECT

public:
    explicit Calendar(QDialog *parent = 0);
    ~Calendar();

private slots:
    void on_calendarWidget_clicked(const QDate &date);

private:
    Ui::Calendar *ui;
};
#endif // CALENDAR_H
