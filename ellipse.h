#ifndef ELLIPSE_H
#define ELLIPSE_H

#include <mbrush.h>
#include "mpen.h"
#include <tochka.h>
#include <QImage>
#include <QPainter>
//класс для создания эллипса
class ellipse : public tochka, public color
{
public:
    ellipse();
    //сеттеры
    bool setRadius1(int val);
    bool setRadius2(int val);
    //геттеры
    int getRadius1();
    int getRadius2();

    mpen pen;
    mbrush brush;
    tochka center;

    void draw(QImage & im);//рисование эллипса

private:
    int radius1;//радиусы
    int radius2;
};

#endif // ELLIPSE_H
