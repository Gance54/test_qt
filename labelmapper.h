#ifndef LABELMAPPER_H
#define LABELMAPPER_H

#include <QObject>
#include <QLabel>
#include <QList>

class LabelMapper : public QObject
{
    Q_OBJECT
public:
    explicit LabelMapper(QObject *parent = 0);
    void RegisterLabel(QLabel *label);
    void UpdateLabels(QString text, QString color);

private:
    QList <QLabel*>_labelList;
    QPalette _previosPalette;
};

#endif // LABELMAPPER_H
