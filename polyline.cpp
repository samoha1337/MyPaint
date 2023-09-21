#include "polyline.h"

polyLine::polyLine()//конструктор
{
    points = new QVector<tochka>(3);
}
void polyLine::draw(QImage &im)//рисование ломаной
{
    // Рисование ломанной
    QPainter painter(&im);
    QPainterPath path;
    QColor color;
    int cx, cy;
    int r,g,b,a;
    pen.GetRGBA(r,g,b,a);
    color.setRgb(r,g,b,a);
    QPen qpen;
    qpen.setWidth(pen.GetWidth());//ширина линии
    qpen.setColor(color);//цвет линии
    color.setRgb(r,g,b,a);
    qpen.setStyle(Qt::PenStyle(pen.GetStyle()));//стиль линии
    (*points)[0].GetXY(cx, cy);
    path.moveTo(cx, cy);//перемещаемся в начальную точку
    int count = points->count();
    for (int i = 1; i < count; i++)
    {
        (*points)[i].GetXY(cx, cy);
        path.lineTo(cx, cy);
    }
    (*points)[0].GetXY(cx, cy);
    //path.lineTo(cx, cy);
    //painter.drawPolyline(mpoints.points());
    painter.setPen(qpen);
    painter.drawPath(path);//отрисовываем по контуру используя заданные параметры
}
