#include "labelmapper.h"
#include <QPalette>

LabelMapper::LabelMapper(QObject *parent) : QObject(parent)
{
    _updated = false;
}

void LabelMapper::RegisterLabel(QLabel *label)
{
    if(label)
        _labelList.push_back(label);
}

void LabelMapper::UpdateLabels(QString text, QString color)
{
    if(!text.isEmpty() && !_labelList.isEmpty())
        _previosText = (_labelList.first())->text();

    if(!color.isEmpty() && !_labelList.isEmpty())
        _previosPalette = (_labelList.first())->palette();

    std::for_each(_labelList.begin(), _labelList.end(), [&](QLabel *label){
        if(!text.isEmpty())
        {
            _previosText = label->text();
            label->setText(text);
            label->setFixedWidth(label->fontMetrics().width(text));
        }

        if(!color.isEmpty())
        {
            _previosPalette = label->palette();
            QColor col(color);
            QPalette pal(label->palette());
            pal.setColor(QPalette::WindowText, col);
            label->setPalette(pal);
        }
    });

    _updated = true;
}

void LabelMapper::SetPrevios()
{
    if(!_updated)
        return;

    std::for_each(_labelList.begin(), _labelList.end(), [&](QLabel *label){
        label->setFixedWidth(label->fontMetrics().width(_previosText));
        label->setPalette(_previosPalette);
        label->setText(_previosText);
    });
}
