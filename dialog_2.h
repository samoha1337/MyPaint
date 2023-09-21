#ifndef DIALOG_2_H
#define DIALOG_2_H

#include <QDialog>
//класс для вызова диалогового окна_2, в котором мы задаем точки
namespace Ui {
class Dialog_2;
}

class Dialog_2 : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog_2(QWidget *parent = nullptr);
    ~Dialog_2();

    void openDialog(QString title, QVector<int>& points);//функция для того, чтобы перед запуском программы убирать лишние поля, менять название объекта на выбранный

    void GETVALUES(bool &flag_ok);//функция передает значение переменной, которая отвечает за опознование выбрал ли пользователь сохранить значения или нет

signals:

    void arrayChanged(QVector<int>& newPoints);//сигнал для передачи вектора int

private slots:

    void on_spinBox_valueChanged(int arg1);//изменеие спинбокса

    void on_tableWidget_cellChanged(int row, int column);//изменение таблицы

    void on_pushButton_clicked();//передачача параметров

    void on_pushButton_2_clicked();// отмена параметров

private:
    Ui::Dialog_2 *ui;
    bool flag_is_ok=0;//принял ли пользователь значения

};

#endif // DIALOG_2_H
