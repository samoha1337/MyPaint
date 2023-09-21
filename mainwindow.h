#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#define Colums_8 8

#include <QComboBox>
#include <QPushButton>
#include <QMessageBox>
#include <QMainWindow>
#include <QColorDialog>
#include <QDialog>
#include <QMenu>
#include <QColor>
#include <QVector>
#include <algorithm>
#include <vector>
#include <QPoint>
#include "QMessageBox"
#include <QFileDialog>
#include <fstream>
#include <QCryptographicHash>
#include <QtGui>
#include <QHash>


#include "my_widget.h"
#include "pixel.h"
#include "line.h"
#include "rect.h"
#include "okno.h"
#include "dialog.h"
#include "dialog_1.h"
#include "dialog_2.h"
#include "ellipse.h"
#include "arc.h"
#include "polygon.h"
#include "polyline.h"


namespace Ui {
class MainWindow;
}

struct T_DATA{//структура для хранения данных о примитивах
    mpen pen;
    mbrush brush;
    int kol;
    int oper=0;//в начале операция Пиксель, поэтому 0
    QVector<int>* POINTS_VECTOR=new QVector<int>({0, 0, 0, 0, 0, 0});//вектор для хранения точек
};



class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    T_DATA * OBJ_DATA;//структура для данных

protected slots:

    void typeComboBox_clicked(int arg1);

private slots:

    void on_spinBox_valueChanged(int arg1);

    void StyleButton_clicked();

    void pointsDialogButton_clicked();

    //импортируемые слоты для получения данных из диалогового окна_2

    void onArrayChanged(QVector<int>& newPoints);

    //импортируемые слоты для получения данных из диалогового окна_1

    void ImportSpin(int spin_value);//для значения ширины

    void ImportStyle(int style_value, int style_brush_value);//для значения стиля

    void ImportColor_line(QColor color);//для цвета линии

    void ImportColor_brush(QColor color);//для цвета заливки

    void drawPixel(int index);//рисование пикселся

    void drawLine(int index);//рисование линии

    void drawRectangle(int index);//рисование прямоугольника

    void drawCircle(int index);//рисование круга

    void drawEllipse(int index);//рисование элипса

    void drawKrivaya(int index);//рисование кривой

    void drawLines(int index);//рисование ломаной

    void drawPolygon(int index);//рисование полигона

    //void drawAll();

    //рисование ячеек в зависимости от выбора пользователя

    void getPixel(int row);//функция для генерации ячеек под пиксель

    void getLine(int row);//функция для генерации ячеек под линию

    void getRect(int row);//функция для генерации ячеек под прямоугольник

    void getCircle(int row);//функция для генерации ячеек под круг

    void getEllipse(int row);//функция для генерации ячеек под эллипс

    void getArc(int row);//функция для генерации ячеек под дуги

    void getPolyline(int row);//функция для генерации ячеек под ломаной

    void getPolygon(int row);//функция для генерации ячеек под полигона

    void clearItems(int row);//очистка ячеек

    void on_tableWidget_cellChanged(int row, int column);//изменение таблицы

    void on_pushButton_save_clicked();//кнопка сохранить

    void on_pushButton_open_clicked();//кнопка отркыть

    void on_actionSha256_triggered();//ссылка на алгоритм

    void on_pushButton_draw_clicked();//кнопка нарисовать

    void on_pushButton_clear_table_clicked();//очистка таблицы

    void on_pushButton_clear_wiget_clicked();//очистка виджета

private:
    Ui::MainWindow *ui;
    int num_primitives=0;//количество примитивов для отрисовки
    int primitive=0;//примитив, который пользователь хочет нарисовать
    int integer_Style=0;//стиль линии, который выбрал пользователь
    int width_main,length_main;//ширина и длина основного виджета
    QColor color_dialog_line_main,color_dialog_brush_main;//значения цвета из диалогового окна_1
    int style_value_line_main=1,style_value_brush_main=1,spin_box_value_main=1;//значения стиля и ширины, стиль=0(так как индекс основного в начальный момент = 0)
    QVector<int>* newPointsPtr;//вектор для передачи наших точек в диалоговое окно_2 и рисования по нему многоугольника и ломаной
    bool auto_change=0;//изменяет ли пользователь ячейки(0) или же мы(1)
    bool open_change=0;//открываем ли мы файл, (0)-нет, (1)-да
    QString Checksum;
    int k;
};

#endif // MAINWINDOW_H
