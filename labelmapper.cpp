#include "labelmapper.h"
#include <QPalette>

LabelMapper::LabelMapper(QObject *parent) : QObject(parent)
{

}

void LabelMapper::RegisterLabel(QLabel *label)
{
    if(label)
        _labelList.push_back(label);
}

void LabelMapper::UpdateLabels(QString text, QString color = "")
{
    std::for_each(_labelList.begin(), _labelList.end(), [&](QLabel *label){
        if(!text.isEmpty())
            label->setText(text);

        if(!color.isEmpty())
        {
            QColor col(color);
            QPalette pal(label->palette());
            pal.setColor(QPalette::WindowText, col);
            label->setPalette(pal);
        }
    });
}
