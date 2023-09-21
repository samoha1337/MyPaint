#include "mbrush.h"

mbrush::mbrush() //конструктор
{
    style=1;
}
bool mbrush::SetStyle(int n_style)//сеттер
{

    if (n_style < 0 || n_style > 13) return false;
    style=n_style;
    return(true);
}
int mbrush::GetStyle(void)//геттер
{
    return(style);
}
