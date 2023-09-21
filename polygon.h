#ifndef POLYGON_H
#define POLYGON_H

#include <QImage>
#include <QPainter>
#include "mpen.h"
#include "mbrush.h"
#include "tochka.h"
//класс для создания полигона
class polygon
{
public:
    polygon();

    void draw(QImage & im);//рисуем полигон

    mpen pen;
    mbrush brush;

    QVector<tochka> *points;//вектор наших точек(с помощью класса точка)
};

#endif // POLYGON_H
