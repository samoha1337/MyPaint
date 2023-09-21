#ifndef DIALOG_1_H
#define DIALOG_1_H

#include <QDialog>
#include <mbrush.h>
//класс для диалогового окна_1
namespace Ui {
class Dialog_1;
}
class Dialog_1 : public QDialog
{
    Q_OBJECT
public:
    explicit Dialog_1(QWidget *parent = nullptr);
    ~Dialog_1();

    void openDialog(QString title,int spin_from_main,int style_from_main_brush,int style_from_main_line,QColor color_line_from_main,QColor color_brush_from_main);//функция для того, чтобы перед запуском программы убирать лишние поля, менять название объекта на выбранный

    void GetValues(int &spin_from_main1,int &style_from_main_line1,int &style_from_main_brush1,QColor &color_line_from_main1,QColor &color_brush_from_main1,bool &flag);

signals://создаем сигналы для передачи данных в основное окно

    void ExportString(QString str);//из лекции для передачи данных из строки сразу в главное окно

    void ExportStyle(int style_value_line,int style_value_brush);//для передачи стиля линии

    void ExportSpinbox(int spin_value);//для передачи ширины линии

    void ExportColor_line(QColor color);//для передачи цвета линии

    void ExportColor_brush(QColor color);//для передачи цвета заливки объекта

private slots:

    void on_pushButtonColor_clicked();//кнопка для передачи стиля линии

    void on_pushButton_ok_clicked();//принимаем параметры стиля линии

    void on_pushButton_cancel_clicked();//отменяем стиль линии

    void on_pushButtonColor_2_clicked();//кнопка для передачи парметров заливки

    void on_comboBoxStyle_currentIndexChanged(int index);//изменение стиля

    void on_comboBoxStyle_2_currentIndexChanged(int index);//изменение заливки

private:
    Ui::Dialog_1 *ui;
    QColor color_dialog_line,color_dialog_brush;//для хранения цвета линии и заливки
    int spin_box_value,style_combobox_value_line,style_combobox_value_brush;//для хранения стиля и ширины
    QString title_dialog;//инструмент
    bool flag_is_ok=0;//принял ли пользователь значения
};

#endif // DIALOG_1_H
