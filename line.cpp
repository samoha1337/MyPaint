#include "line.h"

line::line()// конструктор
{

}
void line::draw(QImage &im)//функция рисования линии на image
{
    QPainter painter(&im);
    QColor color;

    int r,g,b,a;
    pen.GetRGBA(r,g,b,a);
    color.setRgb(r,g,b,a);
    QPen qpen;
    qpen.setWidth(pen.GetWidth());//ширина линии
    qpen.setColor(color);//цвет линии
    qpen.setStyle(Qt::PenStyle(pen.GetStyle()));//стиль линии
    painter.setPen(qpen);
    int x1,x2,y1,y2;
    st.GetXY(x1,y1);//начальная точка
    end.GetXY(x2,y2);//конечная точка
    //рисуем линию по 2 координатам
    painter.drawLine(x1,y1,x2,y2);
}
