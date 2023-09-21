#include "color.h"

color::color() //конструктор
{
    red=0;
    green=0;
    blue=0;
    alpha=255;
}
//сеттер
bool color::SetRGBA(int r, int g, int b, int a)// Установка цвета
{    
    if (r < 0 or r > 255 or g < 0 or g > 255 or
            b < 0 or b > 255 or a < 0 or a > 255) {
        return false;
    }
    red = r;
    green = g;
    blue = b;
    alpha = a;
    return true;
}
//геттер
void color::GetRGBA(int &r, int &g, int &b, int &a)//получаем цвет
{
    r=red;
    g=green;
    b=blue;
    a=alpha;
}
