#ifndef MBRUSH_H
#define MBRUSH_H
#include "color.h"
//класс для стиля заливки(в разработке)
class mbrush : public color
{
public:
    mbrush();
    //сеттер
    bool SetStyle(int n_style);
    //геттер
    int GetStyle(void);

protected:
    int style;//стиль закраски
};

#endif // MBRUSH_H
