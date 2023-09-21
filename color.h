#ifndef COLOR_H
#define COLOR_H

//класс для задачи цвета объекта
class color
{
public:
    color();
    bool SetRGBA(int r, int g, int b, int a);//сеттер
    void GetRGBA(int &r, int &g, int &b, int &a);//геттер

protected:
    int red;
    int green;
    int blue;
    int alpha; //прозрачность
};

#endif // COLOR_H
