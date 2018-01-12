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
    void SetPrevios();

private:
    QList <QLabel*>_labelList;
    QPalette _previosPalette;
    QString _previosText;
    bool _updated;
};

#endif // LABELMAPPER_H
