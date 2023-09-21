#ifndef PIXEL_H
#define PIXEL_H

#include "color.h"
#include "tochka.h"
#include "mpen.h"
#include <QImage>
#include <QPainter>
//Класс создания пикселя
class pixel : public tochka, public color
{
public:
    pixel();

    void draw(QImage &im);//рисуем пиксель
    mpen pen;

};

#endif // PIXEL_H
