#include "dialog_1.h"
#include "ui_dialog_1.h"

#include <QColorDialog>
#include "mainwindow.h"


Dialog_1::Dialog_1(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog_1)
{//констурктор
    ui->setupUi(this);
    setWindowTitle("Окно для выбора стиля и цветов");
    ui->lineEdit->hide();//скрываем так как не нужна(из лекции)
    ui->spinBox->setMinimum(1);//устанавливаем крайние значения для ширины
    ui->spinBox->setMaximum(20);

    connect(ui->lineEdit,SIGNAL(textChanged(QString)),this,SIGNAL(ExportString(QString)));//коннектимся (из лекции)
}
Dialog_1::~Dialog_1()//деструктор
{
    delete ui;
}
void Dialog_1::GetValues(int &spin_from_main1, int &style_from_main_line1, int &style_from_main_brush1, QColor &color_line_from_main1, QColor &color_brush_from_main1, bool &flag)//передаем значения в главное окно
{
    spin_from_main1=spin_box_value;//ширина
    style_from_main_line1=style_combobox_value_line;//стиль линии
    style_from_main_brush1=style_combobox_value_brush;//стиль закраски
    color_line_from_main1=color_dialog_line;//цвет линии
    color_brush_from_main1=color_dialog_brush;//цвет закраски
    flag=flag_is_ok;//принимать ли
}
void Dialog_1::openDialog(QString title,int spin_from_main,int style_from_main_line,int style_from_main_brush,QColor color_line_from_main,QColor color_brush_from_main)//функция выпоняется перед открытием окна
{
    // Обработчик открытия диалога
    title_dialog=title;
    // Применяем полученные данные
    color_dialog_line=color_line_from_main;
    color_dialog_brush=color_brush_from_main;
    ui->labelHeader->setText("Инструмент: " +title);//задаем заголовок
    ui->comboBoxStyle->setCurrentIndex(style_from_main_line);
    ui->comboBoxStyle_2->setCurrentIndex(style_from_main_brush);
    ui->labelHeader->setAlignment(Qt::AlignCenter);//выравниваем

    if(title=="Пиксель"){//наша операция-пиксель
        //скрываем все кроме цвета пикселя
        ui->labelStyle->hide();
        ui->comboBoxStyle->hide();
        ui->label_3->hide();
        ui->pushButtonColor_2->hide();
        ui->label_5->hide();
        ui->spinBox->hide();
        ui->labelStyle_2->hide();
        ui->comboBoxStyle_2->hide();
        ui->spinBox->show();
        ui->label_5->show();
    }
    else if (title=="Линия") {//наша операция-линия
        //скрываем заливку
        ui->labelStyle->show();
        ui->comboBoxStyle->show();
        ui->label_3->hide();
        ui->pushButtonColor_2->hide();
        ui->label_5->show();
        ui->spinBox->show();
        ui->labelStyle_2->hide();
        ui->comboBoxStyle_2->hide();
    }
    else if (title=="Прямоугольник") {//наша операция-прямоугольник
        ui->labelStyle->show();
        ui->comboBoxStyle->show();
        ui->label_3->show();
        ui->pushButtonColor_2->show();
        ui->label_5->show();
        ui->spinBox->show();
        ui->labelStyle_2->show();
        ui->comboBoxStyle_2->show();
    }
    else if(title=="Эллипс"){//наша операция Эллипс
        ui->labelStyle->show();
        ui->comboBoxStyle->show();
        ui->label_3->show();
        ui->pushButtonColor_2->show();
        ui->label_5->show();
        ui->spinBox->show();        
        ui->labelStyle_2->show();
        ui->comboBoxStyle_2->show();
    }
    else if(title=="Дуга"){//наша операция Дуга
        ui->labelStyle->show();
        ui->comboBoxStyle->show();
        ui->label_3->hide();
        ui->pushButtonColor_2->hide();
        ui->label_5->show();
        ui->spinBox->show();
        //ui->labelStyle_2->hide();
        //ui->comboBoxStyle_2->hide();
    }
    else if(title=="Ломаная"){//наша операция Ломаная
        //скрываем заливку
        ui->labelStyle->show();
        ui->comboBoxStyle->show();
        ui->label_3->hide();
        ui->pushButtonColor_2->hide();
        ui->label_5->show();
        ui->spinBox->show();
        ui->labelStyle_2->hide();
        ui->comboBoxStyle_2->hide();
    }
    else if(title=="Полигон"){//наша операция Многоугольник
        ui->labelStyle->show();
        ui->comboBoxStyle->show();
        ui->label_3->show();
        ui->pushButtonColor_2->show();        
        ui->label_5->show();
        ui->spinBox->show();
        ui->labelStyle_2->show();
        ui->comboBoxStyle_2->show();   
    }
    if(style_from_main_brush==0){
        ui->pushButtonColor_2->hide();
        ui->label_3->hide();
    }


    //устанавливаем выбранный цвет в специальные для этого labels
    ui->spinBox->setValue(spin_from_main);

    //QString itemText = ui->comboBoxStyle->itemText(style_from_main_line);//устанавливаем значения стиля, которое было ранее выбрано
    QString itemText_brush = ui->comboBoxStyle->itemText(style_from_main_brush);
    //emit ui->comboBoxStyle->currentIndexChanged(itemText);
    emit ui->comboBoxStyle->currentIndexChanged(style_from_main_line);
    emit ui->comboBoxStyle_2->currentIndexChanged(itemText_brush);
    // Открываем диалог
    exec();


}
void Dialog_1::on_pushButtonColor_clicked()//функция выбора цвета линии
{
    // Обработчик получение нового цвета
    color_dialog_line = QColorDialog::getColor(Qt::white,this, tr("Цвет линии"),QColorDialog::ShowAlphaChannel);//получаем цвет линии при нажатии на соотв кнопку
}
void Dialog_1::on_pushButton_ok_clicked()//пользователь нажал ок-выходим приминив данные
{
    spin_box_value=ui->spinBox->value();//получаем значение из spinbox для ширины линии
    //отправка значения QColor по сигналу
    emit ExportColor_line(color_dialog_line);//испускаем сигналы
    emit ExportColor_brush(color_dialog_brush);
    emit ExportSpinbox(spin_box_value);
    style_combobox_value_line=ui->comboBoxStyle->currentIndex();
    style_combobox_value_brush=ui->comboBoxStyle_2->currentIndex();
    emit ExportStyle(style_combobox_value_line,style_combobox_value_brush);
    flag_is_ok=1;//принимаем значения
    close();//закрываем
}
void Dialog_1::on_pushButton_cancel_clicked()//пользователь нажал отменить-закрываем без сохранения, применяем стандартные параметры
{
    // Отмена
    flag_is_ok=0;//не принимаем изменения
    close();
}
void Dialog_1::on_pushButtonColor_2_clicked()//функция выбора цвета для заливки
{
    color_dialog_brush = QColorDialog::getColor(Qt::white,this, tr("Цвет заливки"),QColorDialog::ShowAlphaChannel);//получаем цвет заливки
}

void Dialog_1::on_comboBoxStyle_currentIndexChanged(int index)
{
    if (index==0)
    {
        ui->spinBox->hide();
        ui->label_5->hide();
        ui->label_2->hide();
        ui->pushButtonColor->hide();
    }
    else
    {
        ui->spinBox->show();
        ui->label_5->show();
        ui->label_2->show();
        ui->pushButtonColor->show();
    }
}
void Dialog_1::on_comboBoxStyle_2_currentIndexChanged(int index)
{
    if (index==0)
    {
        ui->label_3->hide();
        ui->pushButtonColor_2->hide();
    }
    else
    {
        ui->label_3->show();
        ui->pushButtonColor_2->show();
    }
}

