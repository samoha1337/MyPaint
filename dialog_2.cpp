#include "dialog_2.h"
#include "ui_dialog_2.h"

#include <QColorDialog>
#include "mainwindow.h"


Dialog_2::Dialog_2(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog_2)
{//констурктор
    ui->setupUi(this);
    setWindowTitle("Окно для выбора точек");
    ui->spinBox->setMinimum(3);//устанавливаем крайние значения для ширины
    ui->spinBox->setMaximum(30);
}

Dialog_2::~Dialog_2()//деструктор
{
    delete ui;
}
void Dialog_2::GETVALUES(bool &flag_ok){//передавать ли значения в главное окно
    flag_ok=flag_is_ok;
}
void Dialog_2::openDialog(QString title, QVector<int>& points)//функция выпоняется перед открытием окна
{
    if(title=="Полигон"){//если многоугольник, то нужно как минимум 3 точки
        ui->spinBox->setMinimum(3);
    }
    else{
        ui->spinBox->setMinimum(3);//для ломаной достаточно 3
    }
    ui->label_2->setText("Инструмент: " +title);//задаем заголовок
    ui->tableWidget->setRowCount(3);//устанавливаем нужное количество строк
    ui->tableWidget->setColumnCount(2);//количество столбцов 2 - X и Y
    ui->spinBox->setValue(points.size() / 2);
    for (int i = 0; i < points.size(); i += 2) {//берем два значения и устанавливаем их в соответсвующие столбцы
        int x = points.at(i);
        int y = points.at(i + 1);
        QTableWidgetItem *itemX = new QTableWidgetItem(QString::number(x));
        QTableWidgetItem *itemY = new QTableWidgetItem(QString::number(y));
        ui->tableWidget->setItem(i / 2, 0, itemX);
        ui->tableWidget->setItem(i / 2, 1, itemY);
    }
    exec();
}
void Dialog_2::on_spinBox_valueChanged(int arg1)//функция изменяет количество строк в зависимости от выбранного значения spinbox
{
    ui->tableWidget->setRowCount(arg1);    
}
void Dialog_2::on_tableWidget_cellChanged(int row, int column)//функция обработки изменения ячейки
{
    bool flag;//проверка на удовлетворение элемента условиям(число)
    int value=ui->tableWidget->item(row,column)->text().toInt(&flag);
    if(!flag || (value>1900 && column==0) || (value>800 && column==1) || value<0){//ограничения из виджета(1900,800)
        ui->tableWidget->item(row,column)->setBackgroundColor(Qt::red);//ошибка, красим в красный(предупреждение)
    }
    else{
        ui->tableWidget->item(row,column)->setBackgroundColor(Qt::white);//все харашо
    }
}
void Dialog_2::on_pushButton_clicked()//пользователь нажал ок
{
    bool flag=true;
    QVector<int> newPoints;
    int rowCount = ui->tableWidget->rowCount();
    int colCount = ui->tableWidget->columnCount();
    //проверяем все ячейки на возможное незаполнение
    for(int row = 0; row < rowCount; row++){
        for(int col = 0; col < colCount; col++){
            QTableWidgetItem* item = ui->tableWidget->item(row, col);
            if(item == nullptr || item->text().isEmpty()) {//нашли пустую ячейку
                flag=false;
                QTableWidgetItem * ti; //создали указатель
                ti =  new QTableWidgetItem(); //выделяем память
                ui->tableWidget->setItem(row,col,ti); //помещаем ячейку в таблицу
                ui->tableWidget->item(row,col)->setBackgroundColor(Qt::red);//перекрашиваем
            }
            else{
                QColor color = item->background().color();//получаем цвет ячейки на тот случай если в таблице есть неверный значения
                if(color==Qt::red){
                    flag=0;
                }
                else{//если все ок, то добавляем наше значение
                    newPoints.append(item->text().toInt());
                }
            }

        }
    }
    if(flag){
        emit arrayChanged(newPoints);
        flag_is_ok=1;//принимаем значения
        close();
    }
    else{
        QMessageBox::warning(this,"ERROR","Проверьте введенные значения");
    }
}
void Dialog_2::on_pushButton_2_clicked()//пользователь нажал Cancel
{
    flag_is_ok=0;//не применяем значения
    close();
}



