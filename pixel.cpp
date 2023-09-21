#include "pixel.h"

pixel::pixel()//конструктор
{

}
void pixel::draw(QImage &im)//рисование пикселя
{
    QPainter painter(&im);
    QColor color;//цвет

    color.setRgb(red,green,blue,alpha);//устанавливаем цвет в палитре rgba

    QPen mpen;
    mpen.setWidth(pen.GetWidth());//размер пикселя по умолчанию 10
    mpen.setColor(color);

    painter.setPen(mpen);//задаем цвет карандаша
    painter.drawPoint(x,y);//рисуем пиксель
}
