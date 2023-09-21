#ifndef ARC_H
#define ARC_H

#include <QImage>
#include <QPainter>
#include <ellipse.h>
//класс для создания кривой
class arc  : public ellipse
{
public:
    arc();
    //сеттеры
    bool setStartAngle(int angle);
    bool setSpanAngle(int angle);
    //геттеры
    int getStartAngle();
    int getSpanAngle();

    void draw(QImage & im);//рисование кривой

private:
    int startAngle;//стартовый угол
    int spanAngle;//угол пролета
};

#endif // ARC_H
