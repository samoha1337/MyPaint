#ifndef RECT_H
#define RECT_H

#include "mpen.h"
#include "mbrush.h"
#include "tochka.h"
#include <QImage>
#include <QPainter>

//Класс создания прямоугольника по 2 вершинам
class mrect
{
public:
    mrect();

    void draw(QImage &im);//рисуем прямоугольник

    tochka left_top;//верхний угол
    tochka right_bottom;//нижний угол

    mpen pen;
    mbrush brush;
};

#endif // RECT_H
