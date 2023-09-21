#ifndef MY_WIDGET_H
#define MY_WIDGET_H

#include <QWidget>
#include <QPainter>
//класс для виджета
class my_widget : public QWidget
{
    Q_OBJECT
public:

    explicit my_widget(QWidget *parent = nullptr);

    QImage im;

    void create_im(int size_x, int size_y);//создание изображения по ширине и высоте виджета

private:

    bool im_created;

protected:

    void paintEvent(QPaintEvent *);
};

#endif // MY_WIDGET_H
