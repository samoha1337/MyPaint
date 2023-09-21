#ifndef TOCHKA_H
#define TOCHKA_H

//Класс для создания точки
class tochka
{
public:
    tochka();

    //сеттеры
    void SetX(int new_x);

    void SetY(int new_y);

    void SetXY(int new_x, int new_y);

    //геттеры
    int GetX(void);

    int GetY(void);

    void GetXY(int &zn_x,int &zn_y);

protected:
    int x;
    int y;

};

#endif // TOCHKA_H
