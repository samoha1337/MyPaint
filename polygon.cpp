#include "polygon.h"

polygon::polygon()//констурктор
{
    points = new QVector<tochka>(3);
}
void polygon::draw(QImage & im)//рисование полигона
{
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
    QBrush qbrush;
    brush.GetRGBA(r,g,b,a);
    color.setRgb(r,g,b,a);
    qbrush.setColor(color);//цвет заливки
    qbrush.setStyle(Qt::BrushStyle(brush.GetStyle()));//стиль заливки
    qpen.setStyle(Qt::PenStyle(pen.GetStyle()));//стиль линии

    (*points)[0].GetXY(cx, cy);//получаем точку
    path.moveTo(cx, cy);//сдивагемся
    int count = points->count();
    for (int i = 1; i < count; i++)
    {
        (*points)[i].GetXY(cx, cy);
        path.lineTo(cx, cy);
    }
    (*points)[0].GetXY(cx, cy);
    path.lineTo(cx, cy);//рисуем линюю

    painter.setPen(qpen);
    painter.fillPath(path, qbrush);//закрашиваем
    painter.drawPath(path);//отрисовываем по контуру используя заданные параметры

}
