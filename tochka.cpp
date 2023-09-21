#include "tochka.h"

tochka::tochka() //конструктор
{
    x=0;
    y=0;
}
//сеттеры
void tochka::SetX(int new_x)
{
    x=new_x;
}
void tochka::SetY(int new_y)
{
    y=new_y;
}
void tochka::SetXY(int new_x, int new_y)
{
    x=new_x;
    y=new_y;
}
//геттеры
int tochka::GetX(void)
{
    return (x);
}
int tochka::GetY(void)
{
    return (y);
}
void tochka::GetXY(int &zn_x,int &zn_y)
{
    zn_x=x;
    zn_y=y;
}
