#include "okno.h"
#include "ui_okno.h"
#include <QDialog>
#include <QColorDialog>
//Данный класс не использутеся, создавался на лекции
okno::okno(QWidget *parent, QLabel *ll) :
    QMainWindow(parent),
    ui(new Ui::okno)
{//конструктор
    ui->setupUi(this);
    label_from_mainform=ll;
}
okno::~okno()//Деструктор
{
    delete ui;
}
void okno::on_pushButton_Close_clicked()//пользователь закрывает диалоговое окно без сохранения параметров
{     
    close();
}
void okno::on_comboBox_Style_currentIndexChanged()//пользователь изменяет значение Выбранного стиля
{
    integer_Style_dialog=ui->comboBox_Style->currentIndex();//получаем значение выбранного стиля
    //выводить изображение выбранного стиля
}
void okno::on_pushButton_Ok_clicked()//Пользователь сохраняет выбранные параметры
{
    label_from_mainform->setText(ui->lineEdit_width->text());//выводим ширину(изменить)
    close();
}
void okno::on_pushButtonColor_Brush_clicked()//функция позволяет пользователю выбрать цвет заливки
//передать значения для кисти и карандаша в основную программу
{
    QColor color_brush;
    int a,r,g,b;
    color_brush=QColorDialog::getColor(Qt::black, this, "Выбор заливки",QColorDialog::ShowAlphaChannel);
    if (color_brush.isValid()) {
        a=255;
        color_brush.getRgb(&r,&g,&b,&a);

    }

}
void okno::on_pushButtonColor_Pen_clicked()//функция позволяет пользователю выбрать цвет контура
{
    QColor color_pen;
    int a,r,g,b;
    color_pen=QColorDialog::getColor(Qt::black, this, "Выбор контура",QColorDialog::ShowAlphaChannel);
    if (color_pen.isValid()) {
        color_pen.getRgb(&r,&g,&b,&a);
        a=255;
    }
}

