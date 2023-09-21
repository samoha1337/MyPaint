#ifndef LINE_H
#define LINE_H

#include "mpen.h"
#include "tochka.h"
#include <QImage>
#include <QPainter>
//класс для создания линии
class line
{
public:
    line();

    void draw(QImage &im);//рисование линии

    tochka st;//начальная точка
    tochka end;//конечная точка
    mpen pen;
};

#endif // LINE_H
