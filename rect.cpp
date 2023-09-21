#include "rect.h"

mrect::mrect()// конструктор
{

}
void mrect::draw(QImage &im)//рисование
{
    QPainter painter(&im);
    QColor color;

    int r,g,b,a;
    pen.GetRGBA(r,g,b,a);

    color.setRgb(r,g,b,a);

    QPen qpen;
    qpen.setWidth(pen.GetWidth());//ширина линии
    qpen.setColor(color);//цвет линии
    QBrush qbrush;
    brush.GetRGBA(r,g,b,a);

    color.setRgb(r,g,b,a);
    qbrush.setColor(color);//цвет заливки
    qbrush.setStyle(Qt::BrushStyle(brush.GetStyle()));//стиль заливки
    qpen.setStyle(Qt::PenStyle(pen.GetStyle()));//стиль линии


    painter.setPen(qpen);
    painter.setBrush(qbrush);
    int x1,x2,y1,y2;
    left_top.GetXY(x1,y1);//левая точка
    right_bottom.GetXY(x2,y2);//правая точка
    //рисуем прямоугольник по 2 крайним вершинам
    painter.drawRect(x1,y1,x2-x1,y2-y1);
}
