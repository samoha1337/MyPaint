#ifndef POLYLINE_H
#define POLYLINE_H

#include <QImage>
#include <QPainter>
#include "mpen.h"
#include "mbrush.h"
#include "tochka.h"
//класс для создания ломаной
class polyLine
{
public:
    polyLine();

    void draw(QImage & im) ;//рисуем ломаную

    QVector<tochka> *points;//вектор наших точек(с помощью класса точка)

    mpen pen;
};

#endif // POLYLINE_H
