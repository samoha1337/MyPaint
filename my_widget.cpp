#include "my_widget.h"

my_widget::my_widget(QWidget *parent) : QWidget(parent)//конструктор
{
    im_created=false;
}
void my_widget::paintEvent(QPaintEvent *)//создание изображения
{
    // Событие при обновлении виджета
    if (!im_created)
    {
        im = QImage(width(), height(), QImage::Format_ARGB32_Premultiplied);
        //im.fill(0);
        im_created = true;
    }
    QPainter painter(this);
    painter.drawImage(0, 0, im);//отрисовываем его
}
