#include "mpen.h"

mpen::mpen() //конструктор
{
    width=1;
    style=1;
}
bool mpen::SetWidth(int n_width)//сеттер
{
    // Установка ширины линии
    if (n_width < 0 || n_width > 20)
        return false;
    width = n_width;
    return true;
}
int mpen::GetWidth(void)//геттер
{
    return(width);
}
bool mpen::SetStyle(int n_style)//сеттер
{
    // Установка стиля заливки
    if (n_style < 0 || n_style > 5) return false;
    style = n_style;
    return true;
}
int mpen::GetStyle(void)//геттер
{
    return(style);
}
