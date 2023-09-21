#ifndef MPEN_H
#define MPEN_H

#include "color.h"

//класс для создания стиля, ширины линии
class mpen : public color
{
public:
    mpen();
    //сеттеры
    bool SetWidth(int n_width);
    bool SetStyle(int n_style);
    //геттеры
    int GetWidth(void);
    int GetStyle(void);

protected:
    int width;//ширина
    int style;//стиль
};

#endif // MPEN_H
