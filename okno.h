#ifndef OKNO_H
#define OKNO_H
//Данный класс не использутеся, создавался на лекции
#include <QMainWindow>
#include <QLabel>

#include "mbrush.h"
#include "mpen.h"

namespace Ui {
class okno;
}

class okno : public QMainWindow /*, public QDialog*/
{
    Q_OBJECT

public:
    explicit okno(QWidget *parent = nullptr, QLabel *ll=nullptr);

    ~okno();

private slots:

    void on_pushButton_Close_clicked();

    void on_comboBox_Style_currentIndexChanged();

    void on_pushButton_Ok_clicked();

    void on_pushButtonColor_Brush_clicked();

    void on_pushButtonColor_Pen_clicked();

private:
    Ui::okno *ui;
    QLabel * label_from_mainform;
    int integer_Style_dialog=0;//стиль линии(выбрал пользователь)
};

#endif // OKNO_H
