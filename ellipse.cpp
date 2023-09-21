#include "ellipse.h"
ellipse::ellipse()
{//конструктор
    radius1 = 0;
    radius2 = 0;
}
void ellipse::draw(QImage &im)//рисование изображения
{
    // Рисование эллипса
    QPainter painter(&im);
    QColor color;

    int r, g, b, a;
    pen.GetRGBA(r, g, b, a);
    QPen qpen(QColor(r, g, b, a));//цвет линии
    qpen.setWidth(pen.GetWidth());//ширина линии
    qpen.setStyle(Qt::PenStyle(pen.GetStyle()));//стиль линии
    brush.GetRGBA(r, g, b, a);
    QBrush qbrush(QColor(r, g, b, a));//цвет закраски
    qbrush.setStyle(Qt::BrushStyle(brush.GetStyle()));//стиль закраски

    painter.setPen(qpen);
    painter.setBrush(qbrush);
    int x1,y1;
    center.GetXY(x1,y1);
    //рисуем эллипс по центру и 2 радиусам
    painter.drawEllipse(x1 - getRadius1(), y1 - getRadius2(), getRadius1() * 2, getRadius2() * 2);
}
bool ellipse::setRadius1(int val)
{
    // Установка первого радиуса (по ширине)
    if (val < 0 || val > 1000) return false;
    radius1 = val;
    return true;
}
bool ellipse::setRadius2(int val)
{
    // Установка второго радиуса (по высоте)
    if (val < 0 || val > 1000) return false;
    radius2 = val;
    return true;
}
int ellipse::getRadius1()
{
    // Возвращение первого радиуса
    return radius1;
}
int ellipse::getRadius2()
{
    // Возвращение второго радиуса
    return radius2;
}
