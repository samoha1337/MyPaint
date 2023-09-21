#include "arc.h"

arc::arc()// Конструктор
{
    startAngle = 0;
    spanAngle = 0;
}
bool arc::setStartAngle(int angle)//стартовый угол
{
    // Установка начального угла
    if (angle < 0 || angle > INT32_MAX) return false;
    startAngle = angle;
    return true;
}
bool arc::setSpanAngle(int angle)//угол пролета
{
    // Установка угла дуги
    if (angle < 0 || angle > INT32_MAX) return false;
    spanAngle = angle;
    return true;
}
int arc::getStartAngle()// Возвращение начального угла
{    
    return startAngle;
}
int arc::getSpanAngle()// Возвращение угла дуги
{    
    return spanAngle;
}
void arc::draw(QImage &im)//рисование кривой
{
    QPainter painter(&im);
    int r, g, b, a;
    pen.GetRGBA(r, g, b, a);
    QPen qpen(QColor(r, g, b, a));
    qpen.setWidth(pen.GetWidth());//размер линии
    qpen.setStyle(Qt::PenStyle(pen.GetStyle()));//стиль линии
    painter.setPen(qpen);
    //рисуем кривую
    painter.drawArc(GetX() - getRadius1(), GetY() - getRadius2(), getRadius1() * 2, getRadius2() * 2, getStartAngle() * 16, getSpanAngle() * 16);
}
