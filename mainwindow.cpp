#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : //конструктор
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    //констурктор
    ui->setupUi(this);
    MainWindow::showMaximized();//размер окна
    ui->tableWidget->horizontalHeader()->setSectionResizeMode (QHeaderView::Fixed);//фиксатор на столбцы
    ui->tableWidget->setRowCount(0);//установка количества строк
    ui->tableWidget->setColumnCount(Colums_8);//начальное количество столбцов 8
    setWindowTitle("Моя божественная рисовалка с помощью таблицы");//название
    OBJ_DATA=nullptr;
    newPointsPtr = new QVector<int>();//начальные значения для пользователя
    for (int i = 0; i < ui->tableWidget->horizontalHeader()->count(); i++) {
        ui->tableWidget->setColumnWidth(i, 145);//устанавливаем начальное значение для ширины всех столбцов таблицы
    }

}
MainWindow::~MainWindow()//деструктор
{
    delete ui;
    delete newPointsPtr;//очищаем наш вектор при выходе
}
QString getFileChecksum(QString fileName)//получаем контрольную сумму файла
{
    QFile file(fileName);
    if (!file.open(QIODevice::ReadOnly)) {
        return "";//если нет пути файла, то ничего не возвращаем
    }
    QCryptographicHash hash(QCryptographicHash::Sha256);//получаем hash по заданному алгоритму(sha256)
    if (hash.addData(&file) == false) {
        return "";
    }
    QByteArray result = hash.result();
    return result.toHex();//возвращаем полученную контрольную сумму

}

void MainWindow::ImportColor_line(QColor color)//функция импорта цвета линии
{
    color_dialog_line_main=color;
}
void MainWindow::ImportColor_brush(QColor color)//функция импорта цвета заливки
{
    color_dialog_brush_main=color;
}

void MainWindow::drawPixel(int index)
{
    int x1=0,y1=0;//координаты точки
    bool flag_X_1,flag_Y_1;
    pixel m_p; //мой пиксель
    int width;//толщина
    //получаем значения ячеек
    QTableWidgetItem* item_x = ui->tableWidget->item(2*index+1, 1);
    QTableWidgetItem* item_y = ui->tableWidget->item(2*index+1, 2);

    //проверка на то что они существуют
    if(item_x!=nullptr && item_y!=nullptr){

        //проверка на int
        x1=item_x->text().toInt(&flag_X_1);
        y1=item_y->text().toInt(&flag_Y_1);
        width = spin_box_value_main;
        //задаем цвет
        int a,r,g,b;
        a=255;
        QColor c;

        OBJ_DATA[index].pen.GetRGBA(r,g,b,a);
        c=QColor(r,g,b,a);
        m_p.SetRGBA(r,g,b,a);
        //m_p.SetWidth(OBJ_DATA[index].pen.GetWidth());//ширина линии
        m_p.SetX(x1);//устанавливаем координаты по X и Y
        m_p.SetY(y1);
        m_p.pen.SetWidth(width);
        m_p.draw(ui->widget->im);//рисуем
        update();
    }
}

void MainWindow::drawLine(int index)
{
    int x1,y1,x2,y2;//координаты точек линии
    bool flag_X_1,flag_Y_1,flag_X_2,flag_Y_2;
    line m_l; //моя линия

    //получаем значения ячеек
    QTableWidgetItem* item_x1 = ui->tableWidget->item(2*index+1, 1);
    QTableWidgetItem* item_y1 = ui->tableWidget->item(2*index+1, 2);
    QTableWidgetItem* item_x2 = ui->tableWidget->item(2*index+1, 3);
    QTableWidgetItem* item_y2 = ui->tableWidget->item(2*index+1, 4);

    //проверка на то что они существуют
    if(item_x1!=nullptr && item_y1!=nullptr && item_x2!=nullptr && item_y2!=nullptr){

        //проверка на int
        x1=item_x1->text().toInt(&flag_X_1);
        y1=item_y1->text().toInt(&flag_Y_1);
        x2=item_x2->text().toInt(&flag_X_2);
        y2=item_y2->text().toInt(&flag_Y_2);

        m_l.pen.SetWidth(OBJ_DATA[index].pen.GetWidth());//ширина линии
        m_l.pen.SetStyle(OBJ_DATA[index].pen.GetStyle());//стиль линии

        //задаем цвет
        int a,r,g,b;
        a=255;
        QColor c;

        OBJ_DATA[index].pen.GetRGBA(r,g,b,a);
        c=QColor(r,g,b,a);
        m_l.pen.SetRGBA(r,g,b,a);//устанавливаем цвет

        m_l.st.SetX(x1);//устанавливаем координаты X и Y для начальной и конечной точек
        m_l.st.SetY(y1);
        m_l.end.SetX(x2);
        m_l.end.SetY(y2);
        m_l.draw(ui->widget->im);//рисуем
        update();
    }
}

void MainWindow::drawRectangle(int index)
{
    int x1,y1,x2,y2;//координаты двух противоположных вершинх прямоугольника
    bool flag_X_1,flag_Y_1,flag_X_2,flag_Y_2;
    mrect m_r; //мой прямоугольник

    //получаем значения ячеек
    QTableWidgetItem* item_x1 = ui->tableWidget->item(2*index+1, 1);
    QTableWidgetItem* item_y1 = ui->tableWidget->item(2*index+1, 2);
    QTableWidgetItem* item_x2 = ui->tableWidget->item(2*index+1, 3);
    QTableWidgetItem* item_y2 = ui->tableWidget->item(2*index+1, 4);

    //проверка на то что они существуют
    if(item_x1!=nullptr && item_y1!=nullptr && item_x2!=nullptr && item_y2!=nullptr){

        //проверка на int
        x1=item_x1->text().toInt(&flag_X_1);
        y1=item_y1->text().toInt(&flag_Y_1);
        x2=item_x2->text().toInt(&flag_X_2);
        y2=item_y2->text().toInt(&flag_Y_2);

        m_r.pen.SetWidth(OBJ_DATA[index].pen.GetWidth());//ширина линии
        m_r.pen.SetStyle(OBJ_DATA[index].pen.GetStyle());//стиль линии
        m_r.brush.SetStyle(OBJ_DATA[index].brush.GetStyle());//стиль линии

        //задаем цвет
        int a,r,g,b;
        a=255;
        QColor lin,bru;

        OBJ_DATA[index].pen.GetRGBA(r,g,b,a);
        lin=QColor(r,g,b,a);
        m_r.pen.SetRGBA(r,g,b,a);//устанавливаем цвет контура
        OBJ_DATA[index].brush.GetRGBA(r,g,b,a);
        bru=QColor(r,g,b,a);
        m_r.brush.SetRGBA(r,g,b,a);//устанавливаем цвет заливки

        m_r.left_top.SetX(x1);//устанавливаем координаты X и Y двух противоположных вершинх прямоугольника
        m_r.left_top.SetY(y1);
        m_r.right_bottom.SetX(x2);
        m_r.right_bottom.SetY(y2);
        m_r.draw(ui->widget->im);//рисуем
        update();
    }
}
void MainWindow::drawCircle(int index)
{
    int x1,y1,r1;//координаты центра и радиусы
    bool flag_X_1,flag_Y_1,flag_r_1;
    ellipse m_el; //мой эллипс

    //получаем значения ячеек
    QTableWidgetItem* item_x1 = ui->tableWidget->item(2*index+1, 1);
    QTableWidgetItem* item_y1 = ui->tableWidget->item(2*index+1, 2);
    QTableWidgetItem* item_r1 = ui->tableWidget->item(2*index+1, 3);

    //проверка на то что они существуют
    if(item_x1!=nullptr && item_y1!=nullptr && item_r1!=nullptr){

        //проверка на int
        x1=item_x1->text().toInt(&flag_X_1);
        y1=item_y1->text().toInt(&flag_Y_1);
        r1=item_r1->text().toInt(&flag_r_1);
        if (r1<0)
        {
            QMessageBox::information(this,"information","Ввод отрицательных значений радиуса запрещен");
            return;
        }
        m_el.pen.SetWidth(OBJ_DATA[index].pen.GetWidth());//ширина линии
        m_el.pen.SetStyle(OBJ_DATA[index].pen.GetStyle());//стиль линии
        m_el.brush.SetStyle(OBJ_DATA[index].brush.GetStyle());//стиль линии

        //задаем цвет
        int a,r,g,b;
        a=255;
        QColor lin,bru;

        OBJ_DATA[index].pen.GetRGBA(r,g,b,a);
        lin=QColor(r,g,b,a);
        m_el.pen.SetRGBA(r,g,b,a);//устанавливаем цвет контура
        OBJ_DATA[index].brush.GetRGBA(r,g,b,a);
        bru=QColor(r,g,b,a);
        m_el.brush.SetRGBA(r,g,b,a);//устанавливаем цвет заливки

        m_el.center.SetXY(x1,y1);//устанавливаем центр и радиусы
        m_el.setRadius1(r1);
        m_el.setRadius2(r1);

        m_el.draw(ui->widget->im);//рисуем
        update();
    }
}
void MainWindow::ImportSpin(int spin_value)//функция импорта ширины линии
{
    spin_box_value_main=spin_value;
}
void MainWindow::ImportStyle(int style_line_value,int style_brush_value)//функция импорта стиля линии
{
    style_value_line_main=style_line_value;
    style_value_brush_main=style_brush_value;
}
//void MainWindow::drawAll(){//создаем новое изображение сбросив все что было нарисовано до этого
//    QImage * im = &ui->widget->im;
//    (*im).fill(0);//заполняем пустотой
//    int cur_rows=ui->tableWidget->rowCount();//получаем количество строк
//    if(cur_rows<0){//проверка
//        cur_rows=0;
//    }
//    if (OBJ_DATA != nullptr) {//проверяем на существование наших данных
//        for(int i=0;i<cur_rows/2;i++){
//            int op=OBJ_DATA[i].oper;//получаем операцию
//            if(op<0 || op>6){//проверка
//                OBJ_DATA[i].oper=0;
//            }
//            switch (OBJ_DATA[i].oper) {//рисуем в зависимости от операции
//            case 0://пиксель
//            {
//                drawPixel(i);
//                break;
//            }
//            case 1://линия
//            {
//                drawLine(i);
//                break;
//            }
//            case 2://прямоугольник
//            {
//                drawRectangle(i);
//                break;
//            }
//            case 3://эллипс
//            {
//                drawEllipse(i);
//                break;
//            }
//            case 4://круг
//            {
//                drawCircle(i);
//                break;
//            }
//            case 5://кривая
//            {
//                drawKrivaya(i);
//                break;
//            }
//            case 6://ломаная
//            {
//                drawLines(i);
//                break;
//            }
//            case 7://полигон
//            {
//                drawPolygon(i);
//                break;
//            }

//            }
//        }
//    }
//    update();
//}
void MainWindow::drawEllipse(int index){//функция рисования эллипса
    int x1,y1,r1,r2;//координаты центра и радиусы
    bool flag_X_1,flag_Y_1,flag_r_1,flag_r_2;
    ellipse m_el; //мой эллипс

    //получаем значения ячеек
    QTableWidgetItem* item_x1 = ui->tableWidget->item(2*index+1, 1);
    QTableWidgetItem* item_y1 = ui->tableWidget->item(2*index+1, 2);
    QTableWidgetItem* item_r1 = ui->tableWidget->item(2*index+1, 3);
    QTableWidgetItem* item_r2 = ui->tableWidget->item(2*index+1, 4);

    //проверка на то что они существуют
    if(item_x1!=nullptr && item_y1!=nullptr && item_r1!=nullptr && item_r2!=nullptr){

        //проверка на int
        x1=item_x1->text().toInt(&flag_X_1);
        y1=item_y1->text().toInt(&flag_Y_1);
        r1=item_r1->text().toInt(&flag_r_1);
        r2=item_r2->text().toInt(&flag_r_2);
        if (r1<0 or r2<0)
        {
            QMessageBox::information(this,"information","Ввод отрицательных радиусов запрещен");
            return;
        }
        m_el.pen.SetWidth(OBJ_DATA[index].pen.GetWidth());//ширина линии
        m_el.pen.SetStyle(OBJ_DATA[index].pen.GetStyle());//стиль линии
        m_el.brush.SetStyle(OBJ_DATA[index].brush.GetStyle());//стиль линии

        //задаем цвет
        int a,r,g,b;
        a=255;
        QColor lin,bru;

        OBJ_DATA[index].pen.GetRGBA(r,g,b,a);
        lin=QColor(r,g,b,a);
        m_el.pen.SetRGBA(r,g,b,a);//устанавливаем цвет контура
        OBJ_DATA[index].brush.GetRGBA(r,g,b,a);
        bru=QColor(r,g,b,a);
        m_el.brush.SetRGBA(r,g,b,a);//устанавливаем цвет заливки

        m_el.center.SetXY(x1,y1);//устанавливаем центр и радиусы
        m_el.setRadius1(r1);
        m_el.setRadius2(r2);

        m_el.draw(ui->widget->im);//рисуем
        update();
    }
}
void MainWindow::drawKrivaya(int index){//функция рисования кривой
    int x1,y1,r1,r2,c1,c2;//координаты центра, радиусы, угол стартовый и угол пролета
    bool flag_X_1,flag_Y_1,flag_r_1,flag_r_2,flag_c_1,flag_c_2;
    arc m_arc;//моя дуга

    //получаем значения ячеек
    QTableWidgetItem* item_x1 = ui->tableWidget->item(2*index+1, 1);
    QTableWidgetItem* item_y1 = ui->tableWidget->item(2*index+1, 2);
    QTableWidgetItem* item_r1 = ui->tableWidget->item(2*index+1, 3);
    QTableWidgetItem* item_r2 = ui->tableWidget->item(2*index+1, 4);
    QTableWidgetItem* item_c1 = ui->tableWidget->item(2*index+1, 5);
    QTableWidgetItem* item_c2 = ui->tableWidget->item(2*index+1, 6);

    //проверка на то что они существуют
    if(item_x1!=nullptr && item_y1!=nullptr && item_r1!=nullptr && item_r2!=nullptr && item_c1!=nullptr && item_c2!=nullptr ){

        //проверка на int
        x1=item_x1->text().toInt(&flag_X_1);
        y1=item_y1->text().toInt(&flag_Y_1);
        r1=item_r1->text().toInt(&flag_r_1);
        r2=item_r2->text().toInt(&flag_r_2);
        c1=item_c1->text().toInt(&flag_c_1);
        c2=item_c2->text().toInt(&flag_c_2);

        if(c1>360 || c1<-360){
            c1=c1%360;
            item_c1->setText(QString::number(c1));
        }
        if(c2>360 || c2<-360){
            c2=c2%360;
            item_c2->setText(QString::number(c2));
        }
        if(c1<0){
            c1=360+c1;
        }
        if(c2<0){
            c1=c1+c2;
            if(c1<0){
                c1=360+c1;
            }
            c2=abs(c2);
        }
        m_arc.pen.SetWidth(OBJ_DATA[index].pen.GetWidth());//ширина линии
        m_arc.pen.SetStyle(OBJ_DATA[index].pen.GetStyle());//стиль линии

        //задаем цвет
        int a,r,g,b;
        a=255;
        QColor c;

        OBJ_DATA[index].pen.GetRGBA(r,g,b,a);
        c=QColor(r,g,b,a);
        m_arc.pen.SetRGBA(r,g,b,a);//устанавливаем цвет

        m_arc.SetX(x1);//устанавливаем центр, радиусы, стартовый угол и угол пролета
        m_arc.SetY(y1);
        m_arc.setRadius1(r1);
        m_arc.setRadius2(r2);
        m_arc.setStartAngle(c1);
        m_arc.setSpanAngle(c2);

        m_arc.draw(ui->widget->im);//рисуем
        update();
    }
}
void MainWindow::drawLines(int index){//функция рисования ломаной
    polyLine m_polyline; //моя ломаная

    m_polyline.pen.SetWidth(OBJ_DATA[index].pen.GetWidth());//ширина линии
    m_polyline.pen.SetStyle(OBJ_DATA[index].pen.GetStyle());//стиль линии

    int a,r,g,b;
    a=255;
    QColor c;

    OBJ_DATA[index].pen.GetRGBA(r,g,b,a);
    c=QColor(r,g,b,a);
    m_polyline.pen.SetRGBA(r,g,b,a);//устанавливаем цвет

    QVector<int> points_int=*OBJ_DATA[index].POINTS_VECTOR;//вектор для отрисовки точек
    QVector<tochka> points_tochka;//вектор "tochka" для отрисовки по нашим точкам
    if(points_int.isEmpty())
    {

        QMessageBox::information(this,"information","Массив пустой. Заполните точки");
    }
    for (int i = 0; i < points_int.size(); i += 2) {
        tochka k;
        k.SetX(points_int[i]);//устанавливаем X и Y координаты
        k.SetY(points_int[i+1]);
        points_tochka.append(k);//получаем точку
    }
    m_polyline.points = new QVector<tochka>(points_tochka);//рисуем по точкам
    m_polyline.draw(ui->widget->im);//рисуем
    update();
}
void MainWindow::drawPolygon(int index){//функция рисования полигона
    polygon m_poly; //мой полигон

    m_poly.pen.SetWidth(OBJ_DATA[index].pen.GetWidth());//ширина линии
    m_poly.pen.SetStyle(OBJ_DATA[index].pen.GetStyle());//стиль линии
    m_poly.brush.SetStyle(OBJ_DATA[index].brush.GetStyle());//стиль линии

    //задаем цвет
    int a,r,g,b;
    a=255;
    QColor lin,bru;

    OBJ_DATA[index].pen.GetRGBA(r,g,b,a);
    lin=QColor(r,g,b,a);
    m_poly.pen.SetRGBA(r,g,b,a);//устанавливаем цвет контура
    OBJ_DATA[index].brush.GetRGBA(r,g,b,a);
    bru=QColor(r,g,b,a);
    m_poly.brush.SetRGBA(r,g,b,a);//устанавливаем цвет заливки

    QVector<int> points_int =*OBJ_DATA[index].POINTS_VECTOR;//вектор для отрисовки точек
    QVector<tochka> points_tochka;//вектор "tochka" для отрисовки по нашим точкам
    if(points_int.isEmpty())
    {
        QMessageBox::information(this,"information","Массив пустой. Заполните точки");
    }
    for (int i = 0; i < points_int.size(); i += 2) {
        tochka k;
        k.SetX(points_int[i]);//устанавливаем X и Y координаты
        k.SetY(points_int[i+1]);
        points_tochka.append(k);//получаем точку
    }
    m_poly.points = new QVector<tochka>(points_tochka);//рисуем по точкам
    m_poly.draw(ui->widget->im);//рисуем
    update();
}
void MainWindow::onArrayChanged(QVector<int>& newPoints)///функция принимает вектор из диалогового окна_2
{
    *newPointsPtr=newPoints;//обработка измененного массива
}
void MainWindow::on_spinBox_valueChanged(int arg1)//функция изменяет количетсво строк в зависиомсти от выбора пользователем количества объектов для отрисовки
{
    if(open_change!=1){
        auto_change=1;//включено автоизменение
        int need_rows=arg1*2;//сколько нам надо отрисовать строк
        int cur_rows=ui->tableWidget->rowCount();//текущее количество строк
        int old_val=cur_rows/2;//старое количество фигур
        if(cur_rows<0){//проверка
            cur_rows=0;
        }
        if(need_rows>cur_rows){//нужно добавить строки
            ui->tableWidget->setRowCount(need_rows);//устанавливаем новое количество строк
            int i=cur_rows;//идем от текущего элемента
            QTableWidgetItem * twi;//создаем ячейку
            QComboBox * cb;//создаем combobox
            while(i<need_rows){
                //задаем надписи для пользователя в нужных ячейках
                twi=new QTableWidgetItem;
                twi->setText("Объект");
                twi->setFlags(twi->flags() & 0xfffffffd);//запрещаем изменение ячейки с помощью побитового И(&) на код Qt::ItemIsEditable, который имеет значение 2(по умолчанию в Qt),для этого из макс значения вычитаем 10(2 в 2сс) 0xfffffffff=1111 1111.... 1111,0xfffffffd=1111...1101, тип данных int в языке C++ имеет размер 4 байта (32 бита). В 16-ричной системе счисления каждый знак представляет 4 бита, поэтому 8 знаков соответствуют 32 битам. Можно было и так конечно, но нужно было показать суть того, как это получается (item->flags() & Qt::ItemIsEditable).
                ui->tableWidget->setItem(i,0,twi);
                twi=new QTableWidgetItem;
                twi->setText("X");
                twi->setFlags(twi->flags() & 0xfffffffd);
                ui->tableWidget->setItem(i,1,twi);
                twi=new QTableWidgetItem;
                twi->setText("Y");
                twi->setFlags(twi->flags() & 0xfffffffd);
                ui->tableWidget->setItem(i,2,twi);
                twi = new QTableWidgetItem;
                twi->setFlags(twi->flags() & 0xfffffffd);//запрещает изменять ячейку
                twi->setText("Стиль пикселя");
                ui->tableWidget->setItem(i, 3, twi);
                for (int j = 4; j < Colums_8; j++)//ненужные ячейки
                {
                    twi = new QTableWidgetItem;
                    twi->setFlags(twi->flags() & 0xffffffdd);//запрещает изменять ячейку
                    twi->setText("---");
                    ui->tableWidget->setItem(i, j, twi);
                }
                i++;
                cb=new QComboBox;
                cb->addItem("Пиксель");
                cb->addItem("Линия");
                cb->addItem("Прямоугольник");
                cb->addItem("Эллипс");
                cb->addItem("Круг");
                cb->addItem("Дуга");
                cb->addItem("Ломаная");
                cb->addItem("Полигон");
                cb->setProperty("row",i);
                connect(cb,SIGNAL(activated(int)),this,SLOT(typeComboBox_clicked(int)));
                connect(cb,SIGNAL(currentIndexChanged(int)),this,SLOT(typeComboBox_clicked(int)));
                ui->tableWidget->setCellWidget(i,0,cb);

                //эти ячейки уже можно редактировать
                twi = new QTableWidgetItem;
                twi->setText("0");
                ui->tableWidget->setItem(i, 1, twi);

                twi = new QTableWidgetItem;
                twi->setText("0");
                ui->tableWidget->setItem(i, 2, twi);

                QPushButton * pb = new QPushButton;
                pb->setText("Задать");
                pb->setProperty("row", i);
                connect(pb, SIGNAL(clicked()), this, SLOT(StyleButton_clicked()));//связываем
                ui->tableWidget->setCellWidget(i, 3, pb);

                for (int j = 4; j < Colums_8; j++)//ненужные ячейки
                {
                    twi = new QTableWidgetItem;
                    twi->setFlags(twi->flags() & 0xffffffdd);//запрещает изменять ячейку
                    twi->setText("---");
                    ui->tableWidget->setItem(i, j, twi);
                }
                i++;
            }
        }
        else{//нужно удалить строки
            ui->tableWidget->setRowCount(need_rows);
        }
        if(arg1<=0){//если нет требуются данные для хранения, то все удаляем и на всякий случай приравниваем к нулевому указателю
            delete [] OBJ_DATA;
            OBJ_DATA=nullptr;
        }
        else{
            if((old_val==0) || (OBJ_DATA==nullptr)){
                OBJ_DATA=new T_DATA[arg1];//выделили память под новые данные
            }
            else{
                if(old_val<arg1){
                    //добавляем
                    T_DATA * new_OBJ_DATA=OBJ_DATA;//сохранили старое значение
                    OBJ_DATA=new T_DATA[arg1];//выделили память под новые данные
                    memcpy(OBJ_DATA,new_OBJ_DATA,old_val*sizeof(T_DATA));

                    delete [] new_OBJ_DATA;
                    //скопировали старые данные

                    // инициализация значений
                    for(int i=old_val;i<arg1;i++){
                        OBJ_DATA[i].kol=0;
                        OBJ_DATA[i].oper=0;
                        OBJ_DATA[i].POINTS_VECTOR=new QVector<int>({0,0, 0, 0, 0, 0});
                        OBJ_DATA[i].pen.SetRGBA(0,0,0,255);
                        OBJ_DATA[i].pen.SetStyle(1);
                        OBJ_DATA[i].pen.SetWidth(1);
                        OBJ_DATA[i].brush.SetStyle(1);
                        OBJ_DATA[i].brush.SetRGBA(0,0,0,255);
                    }
                }
                else{
                    //удаляем
                    T_DATA * new_OBJ_DATA=OBJ_DATA;//сохранили старое значение
                    OBJ_DATA=new T_DATA[arg1];//выделили память под новые данные
                    memcpy(OBJ_DATA,new_OBJ_DATA,arg1*sizeof(T_DATA));//копируем данные в OBJ_DATA из new_OBJ_DATA заданное количество бит (void * memcpy ( void * destination, const void * source, size_t num );)

                    //                    //скопировали старые данные
                    //                    for(int i=arg1;i<old_val;i++){
                    //                        //освобождение памяти внутри ненужных структур
                    //                        if(new_OBJ_DATA[i].kol>0){
                    //                            //delete [] new_OBJ_DATA[i].POINTS_VECTOR;
                    //                        }
                    //                    }
                    delete [] new_OBJ_DATA;
                }
            }
        }
        auto_change=0;
        //drawAll();
    }
}
void MainWindow::getPixel(int row){//функция для генерации ячеек под пиксель
    QTableWidgetItem * twi = new QTableWidgetItem;
    twi->setFlags(twi->flags() & 0xfffffffd);//запрещает изменять ячейку
    twi->setText("X");
    ui->tableWidget->setItem(row, 1, twi);

    twi = new QTableWidgetItem;
    twi->setFlags(twi->flags() & 0xfffffffd);//запрещает изменять ячейку
    twi->setText("Y");
    ui->tableWidget->setItem(row, 2, twi);

    twi = new QTableWidgetItem;
    twi->setFlags(twi->flags() & 0xfffffffd);//запрещает изменять ячейку
    twi->setText("Стиль пикселя");
    ui->tableWidget->setItem(row, 3, twi);

    for (int j = 4; j < Colums_8; j++)//ненужные ячейки
    {
        twi = new QTableWidgetItem;
        twi->setFlags(twi->flags() & 0xffffffdd);//запрещает изменять ячейку
        twi->setText("---");
        ui->tableWidget->setItem(row, j, twi);
    }
    row++;

    //эти ячейки уже можно редактировать
    twi = new QTableWidgetItem;
    twi->setText("0");
    ui->tableWidget->setItem(row, 1, twi);

    twi = new QTableWidgetItem;
    twi->setText("0");
    ui->tableWidget->setItem(row, 2, twi);

    QPushButton * pb = new QPushButton;
    pb->setText("Задать");
    pb->setProperty("row", row);
    connect(pb, SIGNAL(clicked()), this, SLOT(StyleButton_clicked()));//связываем
    ui->tableWidget->setCellWidget(row, 3, pb);


    for (int j = 4; j < Colums_8; j++)//ненужные ячейки
    {
        twi = new QTableWidgetItem;
        twi->setFlags(twi->flags() & 0xffffffdd);//запрещает изменять ячейку
        twi->setText("---");
        ui->tableWidget->setItem(row, j, twi);
    }

}
void MainWindow::getLine(int row){//функция для генерации ячеек под линиию

    QTableWidgetItem * twi = new QTableWidgetItem;
    twi->setText("X1");
    twi->setFlags(twi->flags() & ~Qt::ItemIsEditable);//запрещает изменять ячейку
    ui->tableWidget->setItem(row, 1, twi);

    twi = new QTableWidgetItem;
    twi->setText("Y1");
    twi->setFlags(twi->flags() & ~Qt::ItemIsEditable);//запрещает изменять ячейку
    ui->tableWidget->setItem(row, 2, twi);

    twi = new QTableWidgetItem;
    twi->setText("X2");
    twi->setFlags(twi->flags() & ~Qt::ItemIsEditable);//запрещает изменять ячейку
    ui->tableWidget->setItem(row, 3, twi);

    twi = new QTableWidgetItem;
    twi->setText("Y2");
    twi->setFlags(twi->flags() & ~Qt::ItemIsEditable);//запрещает изменять ячейку
    ui->tableWidget->setItem(row, 4, twi);

    twi = new QTableWidgetItem;
    twi->setText("Стиль линии");
    twi->setFlags(twi->flags() & ~Qt::ItemIsEditable);//запрещает изменять ячейку
    ui->tableWidget->setItem(row, 5, twi);

    for (int j = 6; j < Colums_8; j++)//пустые ячейки
    {
        twi = new QTableWidgetItem;
        twi->setText("---");
        twi->setFlags(twi->flags() & ~Qt::ItemIsEditable);//запрещает изменять ячейку
        ui->tableWidget->setItem(row, j, twi);
    }
    row++;
    //эти ячейки уже можно редактировать
    twi = new QTableWidgetItem;
    twi->setText("0");
    ui->tableWidget->removeCellWidget(row, 1);
    ui->tableWidget->setItem(row, 1, twi);

    twi = new QTableWidgetItem;
    twi->setText("0");
    ui->tableWidget->removeCellWidget(row, 2);
    ui->tableWidget->setItem(row, 2, twi);

    twi = new QTableWidgetItem;
    twi->setText("0");
    ui->tableWidget->removeCellWidget(row, 3);
    ui->tableWidget->setItem(row, 3, twi);

    twi = new QTableWidgetItem;
    twi->setText("0");
    ui->tableWidget->removeCellWidget(row, 4);
    ui->tableWidget->setItem(row, 4, twi);


    QPushButton * pb = new QPushButton;
    pb->setText("Задать");
    //(row - 1) / 2
    pb->setProperty("row", row);
    connect(pb, SIGNAL(clicked()), this, SLOT(StyleButton_clicked()));
    ui->tableWidget->setCellWidget(row, 5, pb);

    for (int j = 6; j < Colums_8; j++)
    {
        twi = new QTableWidgetItem;
        twi->setText("---");
        twi->setFlags(twi->flags() & ~Qt::ItemIsEditable);//запрещает изменять ячейку
        ui->tableWidget->setItem(row, j, twi);
    }
}
void MainWindow::getRect(int row){//функция для генерации ячеек под прямоугольник
    QTableWidgetItem * twi = new QTableWidgetItem;
    twi->setText("X1");
    twi->setFlags(twi->flags() & ~Qt::ItemIsEditable);//запрещает изменять ячейку
    ui->tableWidget->setItem(row, 1, twi);

    twi = new QTableWidgetItem;
    twi->setText("Y1");
    twi->setFlags(twi->flags() & ~Qt::ItemIsEditable);//запрещает изменять ячейку
    ui->tableWidget->setItem(row, 2, twi);

    twi = new QTableWidgetItem;
    twi->setText("X2");
    twi->setFlags(twi->flags() & ~Qt::ItemIsEditable);//запрещает изменять ячейку
    ui->tableWidget->setItem(row, 3, twi);

    twi = new QTableWidgetItem;
    twi->setText("Y2");
    twi->setFlags(twi->flags() & ~Qt::ItemIsEditable);//запрещает изменять ячейку
    ui->tableWidget->setItem(row, 4, twi);

    twi = new QTableWidgetItem;
    twi->setText("Стиль Прямоугольника");
    twi->setFlags(twi->flags() & ~Qt::ItemIsEditable);//запрещает изменять ячейку
    ui->tableWidget->setItem(row, 5, twi);


    for (int j = 6; j < Colums_8; j++)//пустые ячейки
    {
        twi = new QTableWidgetItem;
        twi->setText("---");
        twi->setFlags(twi->flags() & ~Qt::ItemIsEditable);//запрещает изменять ячейку
        ui->tableWidget->setItem(row, j, twi);
    }
    row++;
    //эти ячейки уже можно редактировать
    twi = new QTableWidgetItem;
    twi->setText("0");
    ui->tableWidget->setItem(row, 1, twi);

    twi = new QTableWidgetItem;
    twi->setText("0");
    ui->tableWidget->setItem(row, 2, twi);

    twi = new QTableWidgetItem;
    twi->setText("0");
    ui->tableWidget->setItem(row, 3, twi);

    twi = new QTableWidgetItem;
    twi->setText("0");
    ui->tableWidget->setItem(row, 4, twi);

    QPushButton * pb = new QPushButton;
    pb->setText("Задать");
    pb->setProperty("row", row);
    connect(pb, SIGNAL(clicked()), this, SLOT(StyleButton_clicked()));
    ui->tableWidget->setCellWidget(row, 5, pb);


    for (int j = 6; j < Colums_8; j++)//пустые ячейки
    {
        twi = new QTableWidgetItem;
        twi->setText("---");
        twi->setFlags(twi->flags() & ~Qt::ItemIsEditable);//запрещает изменять ячейку
        ui->tableWidget->setItem(row, j, twi);
    }
}

void MainWindow::getCircle(int row)//функция для генерации ячеек под круг
{
    QTableWidgetItem * twi = new QTableWidgetItem;
    twi->setText("X");
    twi->setFlags(twi->flags() & ~Qt::ItemIsEditable);//запрещает изменять ячейку
    ui->tableWidget->setItem(row, 1, twi);

    twi = new QTableWidgetItem;
    twi->setText("Y");
    twi->setFlags(twi->flags() & ~Qt::ItemIsEditable);//запрещает изменять ячейку
    ui->tableWidget->setItem(row, 2, twi);

    twi = new QTableWidgetItem;
    twi->setText("Radiusss");
    twi->setFlags(twi->flags() & ~Qt::ItemIsEditable);//запрещает изменять ячейку
    ui->tableWidget->setItem(row, 3, twi);

    twi = new QTableWidgetItem;
    twi->setText("Стиль Круга");
    twi->setFlags(twi->flags() & ~Qt::ItemIsEditable);//запрещает изменять ячейку
    ui->tableWidget->setItem(row, 4, twi);

    for (int j = 5; j < Colums_8; j++)//пустые ячейки
    {
        twi = new QTableWidgetItem;
        twi->setText("---");
        twi->setFlags(twi->flags() & 0xfdd);
        ui->tableWidget->setItem(row, j, twi);
    }

    row++;
    //эти ячейки уже можно редактировать
    twi = new QTableWidgetItem;
    twi->setText("0");
    ui->tableWidget->setItem(row, 1, twi);

    twi = new QTableWidgetItem;
    twi->setText("0");
    ui->tableWidget->setItem(row, 2, twi);

    twi = new QTableWidgetItem;
    twi->setText("0");
    ui->tableWidget->setItem(row, 3, twi);

//    twi = new QTableWidgetItem;
//    twi->setText("0");
//    ui->tableWidget->setItem(row, 4, twi);

    QPushButton * pb = new QPushButton;
    pb->setText("Задать");
    pb->setProperty("row", row);
    connect(pb, SIGNAL(clicked()), this, SLOT(StyleButton_clicked()));
    ui->tableWidget->setCellWidget(row, 4, pb);

    for (int j = 5; j < Colums_8; j++)//пустые ячейки
    {
        twi = new QTableWidgetItem;
        twi->setText("---");
        twi->setFlags(twi->flags() & ~Qt::ItemIsEditable);//запрещает изменять ячейку
        ui->tableWidget->setItem(row, j, twi);
    }
}
void MainWindow::getEllipse(int row){//функция для генерации ячеек под эллипс

    QTableWidgetItem * twi = new QTableWidgetItem;
    twi->setText("X");
    twi->setFlags(twi->flags() & ~Qt::ItemIsEditable);//запрещает изменять ячейку
    ui->tableWidget->setItem(row, 1, twi);

    twi = new QTableWidgetItem;
    twi->setText("Y");
    twi->setFlags(twi->flags() & ~Qt::ItemIsEditable);//запрещает изменять ячейку
    ui->tableWidget->setItem(row, 2, twi);

    twi = new QTableWidgetItem;
    twi->setText("R⇔");
    twi->setFlags(twi->flags() & ~Qt::ItemIsEditable);//запрещает изменять ячейку
    ui->tableWidget->setItem(row, 3, twi);

    twi = new QTableWidgetItem;
    twi->setText("R⇕");
    twi->setFlags(twi->flags() & ~Qt::ItemIsEditable);//запрещает изменять ячейку
    ui->tableWidget->setItem(row, 4, twi);

    twi = new QTableWidgetItem;
    twi->setText("Стиль Эллипса");
    twi->setFlags(twi->flags() & ~Qt::ItemIsEditable);//запрещает изменять ячейку
    ui->tableWidget->setItem(row, 5, twi);



    for (int j = 6; j < Colums_8; j++)//пустые ячейки
    {
        twi = new QTableWidgetItem;
        twi->setText("---");
        twi->setFlags(twi->flags() & 0xfdd);
        ui->tableWidget->setItem(row, j, twi);
    }

    row++;
    //эти ячейки уже можно редактировать
    twi = new QTableWidgetItem;
    twi->setText("0");
    ui->tableWidget->setItem(row, 1, twi);

    twi = new QTableWidgetItem;
    twi->setText("0");
    ui->tableWidget->setItem(row, 2, twi);

    twi = new QTableWidgetItem;
    twi->setText("0");
    ui->tableWidget->setItem(row, 3, twi);

    twi = new QTableWidgetItem;
    twi->setText("0");
    ui->tableWidget->setItem(row, 4, twi);

    QPushButton * pb = new QPushButton;
    pb->setText("Задать");
    pb->setProperty("row", row);
    connect(pb, SIGNAL(clicked()), this, SLOT(StyleButton_clicked()));
    ui->tableWidget->setCellWidget(row, 5, pb);

    for (int j = 6; j < Colums_8; j++)//пустые ячейки
    {
        twi = new QTableWidgetItem;
        twi->setText("---");
        twi->setFlags(twi->flags() & ~Qt::ItemIsEditable);//запрещает изменять ячейку
        ui->tableWidget->setItem(row, j, twi);
    }
}
void MainWindow::getArc(int row)//функция для генерации ячеек под дугу
{
    QTableWidgetItem * twi = new QTableWidgetItem;
    twi->setText("X");
    twi->setFlags(twi->flags() & ~Qt::ItemIsEditable);//запрещает изменять ячейку
    ui->tableWidget->setItem(row, 1, twi);

    twi = new QTableWidgetItem;
    twi->setText("Y");
    twi->setFlags(twi->flags() & ~Qt::ItemIsEditable);//запрещает изменять ячейку
    ui->tableWidget->setItem(row, 2, twi);

    twi = new QTableWidgetItem;
    twi->setText("R1");
    twi->setFlags(twi->flags() & ~Qt::ItemIsEditable);//запрещает изменять ячейку
    ui->tableWidget->setItem(row, 3, twi);

    twi = new QTableWidgetItem;
    twi->setText("R2");
    twi->setFlags(twi->flags() & ~Qt::ItemIsEditable);//запрещает изменять ячейку
    ui->tableWidget->setItem(row, 4, twi);

    twi = new QTableWidgetItem;
    twi->setText("Начальный угол в °");
    twi->setFlags(twi->flags() & ~Qt::ItemIsEditable);//запрещает изменять ячейку
    ui->tableWidget->setItem(row, 5, twi);

    twi = new QTableWidgetItem;
    twi->setText("Угловая длина в °");
    twi->setFlags(twi->flags() & ~Qt::ItemIsEditable);//запрещает изменять ячейку
    ui->tableWidget->setItem(row, 6, twi);

    twi = new QTableWidgetItem;
    twi->setText("Стиль Дуги");
    twi->setFlags(twi->flags() & ~Qt::ItemIsEditable);//запрещает изменять ячейку
    ui->tableWidget->setItem(row, 7, twi);

    for (int j = 8; j < Colums_8; j++)//пустые ячейки
    {
        twi = new QTableWidgetItem;
        twi->setText("---");
        twi->setFlags(twi->flags() & ~Qt::ItemIsEditable);//запрещает изменять ячейку
        ui->tableWidget->setItem(row, j, twi);
    }

    row++;
    //эти ячейки уже можно редактировать
    twi = new QTableWidgetItem;
    twi->setText("0");
    ui->tableWidget->setItem(row, 1, twi);

    twi = new QTableWidgetItem;
    twi->setText("0");
    ui->tableWidget->setItem(row, 2, twi);

    twi = new QTableWidgetItem;
    twi->setText("0");
    ui->tableWidget->setItem(row, 3, twi);

    twi = new QTableWidgetItem;
    twi->setText("0");
    ui->tableWidget->setItem(row, 4, twi);

    twi = new QTableWidgetItem;
    twi->setText("0");
    ui->tableWidget->setItem(row, 5, twi);

    twi = new QTableWidgetItem;
    twi->setText("0");
    ui->tableWidget->setItem(row, 6, twi);


    QPushButton * pb = new QPushButton;
    pb->setText("Задать");
    pb->setProperty("row", row);
    connect(pb, SIGNAL(clicked()), this, SLOT(StyleButton_clicked()));
    ui->tableWidget->setCellWidget(row, 7, pb);

    for (int j = 8; j < Colums_8; j++)
    {
        twi = new QTableWidgetItem;
        twi->setText("---");
        twi->setFlags(twi->flags() & ~Qt::ItemIsEditable);//запрещает изменять ячейку
        ui->tableWidget->setItem(row, j, twi);
    }
}
void MainWindow::getPolyline(int row){//функция для генерации ячеек под ломаную
    QTableWidgetItem * twi = new QTableWidgetItem;
    twi->setText("Точки Ломаной");
    twi->setFlags(twi->flags() & ~Qt::ItemIsEditable);//запрещает изменять ячейку
    ui->tableWidget->setItem(row, 1, twi);
    twi->setBackgroundColor(Qt::red);


    twi = new QTableWidgetItem;
    twi->setText("Стиль Линии");
    twi->setFlags(twi->flags() & ~Qt::ItemIsEditable);//запрещает изменять ячейку
    ui->tableWidget->setItem(row, 2, twi);

    for (int j = 3; j < Colums_8; j++)//пустые ячейки
    {
        twi = new QTableWidgetItem;
        twi->setText("---");
        twi->setFlags(twi->flags() & ~Qt::ItemIsEditable);//запрещает изменять ячейку
        ui->tableWidget->setItem(row, j, twi);
    }

    row++;

    QPushButton * pb = new QPushButton;
    pb->setText("Задать");
    pb->setProperty("row", row);    
    connect(pb, SIGNAL(clicked()), this, SLOT(pointsDialogButton_clicked()));//кнопка для задачи точек лоианой
    ui->tableWidget->setCellWidget(row, 1, pb);

    pb = new QPushButton;
    pb->setText("Задать");
    pb->setProperty("row", row);
    connect(pb, SIGNAL(clicked()), this, SLOT(StyleButton_clicked()));
    ui->tableWidget->setCellWidget(row, 2, pb);

    for (int j = 3; j < Colums_8; j++)//пустые ячейки
    {
        twi = new QTableWidgetItem;
        twi->setText("---");
        twi->setFlags(twi->flags() & ~Qt::ItemIsEditable);//запрещает изменять ячейку
        ui->tableWidget->setItem(row, j, twi);
    }
}
void MainWindow::getPolygon(int row){//функция для генерации ячеек под полигон
    QTableWidgetItem * twi = new QTableWidgetItem;
    twi->setText("Точки Полигона");
    twi->setFlags(twi->flags() & ~Qt::ItemIsEditable);//запрещает изменять ячейку
    ui->tableWidget->setItem(row, 1, twi);
    twi->setBackgroundColor(Qt::red);

    twi = new QTableWidgetItem;
    twi->setText("Стиль Полигона");
    twi->setFlags(twi->flags() & ~Qt::ItemIsEditable);//запрещает изменять ячейку
    ui->tableWidget->setItem(row, 2, twi);


    for (int j = 3; j < Colums_8; j++)
    {
        twi = new QTableWidgetItem;
        twi->setText("---");
        twi->setFlags(twi->flags() & ~Qt::ItemIsEditable);//запрещает изменять ячейку
        ui->tableWidget->setItem(row, j, twi);
    }

    row++;

    QPushButton * pb = new QPushButton;
    pb->setText("Задать");
    pb->setProperty("row", row);
    connect(pb, SIGNAL(clicked()), this, SLOT(pointsDialogButton_clicked()));//кнопка для задачи точек полигона
    ui->tableWidget->setCellWidget(row, 1, pb);

    pb = new QPushButton;
    pb->setText("Задать");
    pb->setProperty("row", row);
    connect(pb, SIGNAL(clicked()), this, SLOT(StyleButton_clicked()));
    ui->tableWidget->setCellWidget(row, 2, pb);


    for (int j = 3; j < Colums_8; j++)//пустые ячейки
    {
        twi = new QTableWidgetItem;
        twi->setText("---");
        twi->setFlags(twi->flags() & ~Qt::ItemIsEditable);//запрещает изменять ячейку
        ui->tableWidget->setItem(row, j, twi);
    }
}
void MainWindow::typeComboBox_clicked(int arg1)//функия изменения ячеек в зависимости от выбранной фигуры
{
    auto_change=1;
    int row;
    QComboBox *cbox=qobject_cast<QComboBox*>(sender());
    if(cbox!=nullptr){//проверка на существование
        row=cbox->property("row").toInt();
        //QTableWidgetItem *twi;
        int index=(row-1)/2;
        OBJ_DATA[index].oper=arg1;//записываем опрацию в наши данные
        OBJ_DATA[index].POINTS_VECTOR=new QVector<int>();
        ///если надо сбрасывать старые данные при смене операции
        //        if(OBJ_DATA[index].kol>0)
        //            //delete [] OBJ_DATA[index].POINTS_VECTOR;
        //        OBJ_DATA[index].kol=0;
        //        //OBJ_DATA[index].POINTS_VECTOR=nullptr;
        //        //OBJ_DATA[index].POINTS_VECTOR=nullptr;
        //        //OBJ_DATA[index].POINTS_VECTOR=new QVector<int>({0, 0, 0, 0, 0, 0});
        //        OBJ_DATA[index].pen.SetRGBA(0,0,0,0);
        //        OBJ_DATA[index].pen.SetStyle(1);
        //        OBJ_DATA[index].pen.SetWidth(1);
        //        OBJ_DATA[index].brush.SetStyle(1);
        //        OBJ_DATA[index].brush.SetRGBA(0,0,0,0);

        int row_m=row-1;
        clearItems(row_m);//очищаем ячейки для будущего заполения
        switch (arg1) {
        case 0://пиксель
        {
            getPixel(row_m);
            break;
        }
        case 1:
        {
            getLine(row_m);
            break;
        }
        case 2:
        {
            getRect(row_m);
            break;
        }
        case 3:
        {
            getEllipse(row_m);
            break;
        }
        case 4:
        {
            getCircle(row_m);
            break;
        }
        case 5:
        {
            getArc(row_m);
            break;
        }
        case 6:
        {
            getPolyline(row_m);
            break;
        }
        case 7:
        {
            getPolygon(row_m);
            break;
        }

        }

    }
    auto_change=0;
    //drawAll();

}
void MainWindow::clearItems(int row){//функция для очистки ячеек таблицы
    auto_change=1;
    for (int i = 1; i < Colums_8; i++)
    {
        QTableWidgetItem * twi = ui->tableWidget->item(row, i);
        if (twi != nullptr)
        {
            twi->setText("");
            //twi->setBackground(Qt::white);
        }
        twi = ui->tableWidget->item(row+1, i);
        if (twi != nullptr)
        {
            twi->setText("");
            //twi->setBackground(Qt::white);
        }
        ui->tableWidget->removeCellWidget(row, i);
        ui->tableWidget->removeCellWidget(row+1, i);
    }
    auto_change=0;
}
void MainWindow::StyleButton_clicked()//функция вызова диалогового окна для задачи стиля, цвета, ширины
{
    QPushButton * pb =qobject_cast<QPushButton *>(sender());
    if(pb!=nullptr){
        int row=pb->property("row").toInt();
        int index=(row-1)/2;
        Dialog_1 * dialog_1= new Dialog_1(this);
        connect(dialog_1, &Dialog_1::ExportColor_line, this, &MainWindow::ImportColor_line);
        connect(dialog_1, &Dialog_1::ExportColor_brush, this, &MainWindow::ImportColor_brush);
        connect(dialog_1, &Dialog_1::ExportSpinbox, this, &MainWindow::ImportSpin);
        connect(dialog_1, &Dialog_1::ExportStyle, this, &MainWindow::ImportStyle);

        //Connects, но в другой форме
        //        connect(dialog_1,SIGNAL(ExportStyle(int,int)),this,SLOT(ImportStyle(int,int)));
        //        connect(dialog_1,SIGNAL(ExportSpinbox(int)),this,SLOT(ImportSpin(int)));
        //        connect(dialog_1,SIGNAL(ExportColor_brush(QColor)),this,SLOT(ImportColor_brush(QColor)));
        //        connect(dialog_1,SIGNAL(ExportColor_line(QColor)),this,SLOT(ImportColor_line(int,int)));
        //        connect(dialog_1,SIGNAL(ExportString(QString)),this,SLOT(ImportString(QString)));


        QComboBox * cb =qobject_cast<QComboBox *>(ui->tableWidget->cellWidget(row,0));
        k=cb->currentIndex();//смотрим какая фигура выбрана
        QString title_fig;
        switch (k) {//определяем операцию
        case 0://пиксель
        {
            title_fig="Пиксель";
            break;
        }
        case 1:
        {
            title_fig="Линия";
            break;
        }
        case 2:
        {
            title_fig="Прямоугольник";
            break;
        }
        case 3:
        {
            title_fig="Эллипс";
            break;
        }
        case 4:
        {
            title_fig="Круг";
            break;
        }
        case 5:
        {
            title_fig="Дуга";
            break;
        }
        case 6:
        {
            title_fig="Ломаная";
            break;
        }
        case 7:
        {
            title_fig="Полигон";
            break;
        }

        }
        int wi,s_l,s_b;
        QColor c_l,c_b;
        bool flag_1;
        mpen pen;
        int r,g,b,a;

        //применяем параметры
        s_l=OBJ_DATA[index].pen.GetStyle();
        s_b=OBJ_DATA[index].brush.GetStyle();
        wi=OBJ_DATA[index].pen.GetWidth();
        OBJ_DATA[index].pen.GetRGBA(r,g,b,a);
        c_l=QColor(r,g,b,a);
        OBJ_DATA[index].brush.GetRGBA(r,g,b,a);
        c_b=QColor(r,g,b,a);

        dialog_1->openDialog(title_fig,wi,s_l,s_b,c_l,c_b);//передаем значения
        dialog_1->GetValues(wi,s_l,s_b,c_l,c_b,flag_1);//получаем значения
        if(flag_1==1){//если пользователь нажал ок перед выходом, то обновляем значения
            OBJ_DATA[index].pen.SetStyle(s_l);
            OBJ_DATA[index].brush.SetStyle(s_b);
            OBJ_DATA[index].pen.SetWidth(wi);

            c_l.getRgb(&r,&g,&b,&a);
            OBJ_DATA[index].pen.SetRGBA(r,g,b,a);

            c_b.getRgb(&r,&g,&b,&a);
            OBJ_DATA[index].brush.SetRGBA(r,g,b,a);
        }
        //drawAll();
    }
}
void MainWindow::pointsDialogButton_clicked(){//функция для вызова диалогового окна для задачи точек
    QPushButton * pb =qobject_cast<QPushButton *>(sender());//кто отправляет сигнал
    if(pb!=nullptr){
        int row=pb->property("row").toInt();//свойство
        int index=(row-1)/2;
        QComboBox * cb =qobject_cast<QComboBox *>(ui->tableWidget->cellWidget(row,0));//кто отправляет сигнал
        int k=cb->currentIndex();
        QString title_fig;
        switch (k) {//определяем операцию
        case 6:
        {
            title_fig="Ломаная";
            break;
        }
        case 7:
        {
            title_fig="Полигон";
            break;
        }

        }
        Dialog_2 * dialog_2= new Dialog_2(this);
        connect(dialog_2, &Dialog_2::arrayChanged, this, &MainWindow::onArrayChanged);
        bool flag_1=0;
        QVector<int> hepl=*OBJ_DATA[index].POINTS_VECTOR;//вектор для передачи в основную программу
        dialog_2->openDialog(title_fig,hepl);//открываем окно
        dialog_2->GETVALUES(flag_1);//определяем что нажал пользователь при закрытии окна
        if(flag_1){//если пользователь нажал ок, то меняем значения
            *OBJ_DATA[index].POINTS_VECTOR=*newPointsPtr;
             ui->tableWidget->item(row-1,1)->setBackgroundColor(Qt::white);
             update();
        }
    }
}
void MainWindow::on_tableWidget_cellChanged(int row, int column)//функция обработки изменения значения ячейки
{
    if(open_change!=1){
        if(auto_change==0){//если пользователь меняет значения
            QTableWidget* tableWidget = ui->tableWidget;
            QTableWidgetItem* item = tableWidget->item(row, column);
            if (item == nullptr) return;
            if (!(item->flags() & Qt::ItemIsEditable)) return;
            bool ok;
            int value = item->text().toInt(&ok);
            if (!ok) {
                // значение не является числом
                item->setText("0"); // устанавливаем значение по умолчанию
                return;
            }
            //ограничение от -1950 до 1950
            if (value < -1950) {
                value = -1950;
            } else if (value > 1950) {
                value = 1950;
            }
            item->setText(QString::number(value));//выводим значение
            //drawAll();
        }
    }
}
void MainWindow::on_pushButton_save_clicked()//сохранение файла
{
    //int cur_rows=ui->tableWidget->rowCount();//текущее количество строк
    //добавить проверку на формат файла
    QString filename = QFileDialog::getSaveFileName(this, "Сохранить файл", "", tr("Binary files (*.bin)"));    
    QString extension = QFileInfo(filename).suffix();

    std::string fileName_std;
    fileName_std=filename.toStdString();//получаем string из QString
    if (filename.isEmpty())
    {
        // Если не выбран файл
        QMessageBox::critical(this, "Ошибка", "Файл не выбран");
    }
    else
    {
        if(extension!="bin"){
            QMessageBox::critical(this, "Ошибка", "Расширение не бинарного файла");
        }
        else{
            QFile file(filename);
            if (file.open(QIODevice::WriteOnly))
            {
                //количество элементов, операция, цвет контура, стиль контура, толщина контура, (если есть: цвет заливки, стиль заливки) координаты ( или вектор точек).
                int cur_rows=(ui->tableWidget->rowCount())/2;//текущее количество элементов
                std::ofstream fout(fileName_std,std::ios_base::binary);//открываем для записи в файл в бинарной режиме
                fout.write((char*)&cur_rows,sizeof(int));//считываем количество элементов
                for(int i=0;i<cur_rows;i++){
                    fout.write((char*)&OBJ_DATA[i].oper,sizeof(int));//записываем операцию
                    //write() - функция ожидает, что будет записан указатель на данные.
                    //Приведение типа (char *) используется для преобразования указателя объекта в указатель на char, чтобы функция write() могла интерпретировать данные как последовательность байтов и записать их в файл.

                    // или другими словами:

                    //функция write() принимает адрес памяти объекта, обрабатывает его как последовательность байтов и записывает эту последовательность байтов в файл.
                    //преобразует адрес объекта в указатель на char, чтобы записать его содержимое как последовательность байтов
                    switch (OBJ_DATA[i].oper) {//рисуем в зависимости от операции
                    case 0://пиксель
                    {
                        QTableWidgetItem* item_x = ui->tableWidget->item(2*i+1, 1);
                        QTableWidgetItem* item_y = ui->tableWidget->item(2*i+1, 2);
                        int x1=0,y1=0;//координаты точки
                        bool flag_X_1,flag_Y_1;

                        //проверка на то что они существуют
                        if(item_x!=nullptr && item_y!=nullptr){

                            //проверка на int
                            x1=item_x->text().toInt(&flag_X_1);
                            y1=item_y->text().toInt(&flag_Y_1);

                            //записываем цвет пикселя
                            int r,g,b,a;
                            OBJ_DATA[i].pen.GetRGBA(r,g,b,a);
                            fout.write((char*)&r,sizeof(int));
                            fout.write((char*)&g,sizeof(int));
                            fout.write((char*)&b,sizeof(int));
                            fout.write((char*)&a,sizeof(int));

                            fout.write((char*)&x1,sizeof(int));
                            fout.write((char*)&y1,sizeof(int));
                        }
                        break;
                    }
                    case 1://линия
                    {
                        int x1,y1,x2,y2;//координаты точек линии
                        bool flag_X_1,flag_Y_1,flag_X_2,flag_Y_2;

                        //получаем значения ячеек
                        QTableWidgetItem* item_x1 = ui->tableWidget->item(2*i+1, 1);
                        QTableWidgetItem* item_y1 = ui->tableWidget->item(2*i+1, 2);
                        QTableWidgetItem* item_x2 = ui->tableWidget->item(2*i+1, 3);
                        QTableWidgetItem* item_y2 = ui->tableWidget->item(2*i+1, 4);

                        //проверка на то что они существуют
                        if(item_x1!=nullptr && item_y1!=nullptr && item_x2!=nullptr && item_y2!=nullptr){

                            //проверка на int
                            x1=item_x1->text().toInt(&flag_X_1);
                            y1=item_y1->text().toInt(&flag_Y_1);
                            x2=item_x2->text().toInt(&flag_X_2);
                            y2=item_y2->text().toInt(&flag_Y_2);
                            int r,g,b,a;
                            OBJ_DATA[i].pen.GetRGBA(r,g,b,a);
                            int penStyle=OBJ_DATA[i].pen.GetStyle();
                            int penWidth=OBJ_DATA[i].pen.GetWidth();
                            // fout.write((char*)&OBJ_DATA[i].oper,sizeof(int));
                            fout.write((char*)&r,sizeof(int));
                            fout.write((char*)&g,sizeof(int));
                            fout.write((char*)&b,sizeof(int));
                            fout.write((char*)&a,sizeof(int));

                            fout.write((char*)&penStyle,sizeof(int));
                            fout.write((char*)&penWidth,sizeof(int));

                            fout.write((char*)&x1,sizeof(int));
                            fout.write((char*)&y1,sizeof(int));
                            fout.write((char*)&x2,sizeof(int));
                            fout.write((char*)&y2,sizeof(int));
                        }
                        break;
                    }
                    case 2://прямоугольник
                    {
                        int x1,y1,x2,y2;//координаты двух противоположных вершинх прямоугольника
                        bool flag_X_1,flag_Y_1,flag_X_2,flag_Y_2;

                        //получаем значения ячеек
                        QTableWidgetItem* item_x1 = ui->tableWidget->item(2*i+1, 1);
                        QTableWidgetItem* item_y1 = ui->tableWidget->item(2*i+1, 2);
                        QTableWidgetItem* item_x2 = ui->tableWidget->item(2*i+1, 3);
                        QTableWidgetItem* item_y2 = ui->tableWidget->item(2*i+1, 4);

                        //проверка на то что они существуют
                        if(item_x1!=nullptr && item_y1!=nullptr && item_x2!=nullptr && item_y2!=nullptr){

                            //проверка на int
                            x1=item_x1->text().toInt(&flag_X_1);
                            y1=item_y1->text().toInt(&flag_Y_1);
                            x2=item_x2->text().toInt(&flag_X_2);
                            y2=item_y2->text().toInt(&flag_Y_2);
                            int r,g,b,a;
                            OBJ_DATA[i].pen.GetRGBA(r,g,b,a);
                            int penStyle=OBJ_DATA[i].pen.GetStyle();
                            int penWidth=OBJ_DATA[i].pen.GetWidth();
                            //fout.write((char*)&OBJ_DATA[i].oper,sizeof(int));
                            fout.write((char*)&r,sizeof(int));
                            fout.write((char*)&g,sizeof(int));
                            fout.write((char*)&b,sizeof(int));
                            fout.write((char*)&a,sizeof(int));

                            fout.write((char*)&penStyle,sizeof(int));
                            fout.write((char*)&penWidth,sizeof(int));

                            OBJ_DATA[i].brush.GetRGBA(r,g,b,a);
                            int brushStyle=OBJ_DATA[i].brush.GetStyle();
                            fout.write((char*)&r,sizeof(int));
                            fout.write((char*)&g,sizeof(int));
                            fout.write((char*)&b,sizeof(int));
                            fout.write((char*)&a,sizeof(int));
                            fout.write((char*)&brushStyle,sizeof(int));

                            fout.write((char*)&x1,sizeof(int));
                            fout.write((char*)&y1,sizeof(int));
                            fout.write((char*)&x2,sizeof(int));
                            fout.write((char*)&y2,sizeof(int));
                        }
                        break;
                    }
                    case 3://эллипс
                    {
                        int x1,y1,r1,r2;//координаты центра и радиусы
                        bool flag_X_1,flag_Y_1,flag_r_1,flag_r_2;

                        //получаем значения ячеек
                        QTableWidgetItem* item_x1 = ui->tableWidget->item(2*i+1, 1);
                        QTableWidgetItem* item_y1 = ui->tableWidget->item(2*i+1, 2);
                        QTableWidgetItem* item_r1 = ui->tableWidget->item(2*i+1, 3);
                        QTableWidgetItem* item_r2 = ui->tableWidget->item(2*i+1, 4);

                        //проверка на то что они существуют
                        if(item_x1!=nullptr && item_y1!=nullptr && item_r1!=nullptr && item_r2!=nullptr){

                            //проверка на int
                            x1=item_x1->text().toInt(&flag_X_1);
                            y1=item_y1->text().toInt(&flag_Y_1);
                            r1=item_r1->text().toInt(&flag_r_1);
                            r2=item_r2->text().toInt(&flag_r_2);
                            int r,g,b,a;
                            OBJ_DATA[i].pen.GetRGBA(r,g,b,a);
                            int penStyle=OBJ_DATA[i].pen.GetStyle();
                            int penWidth=OBJ_DATA[i].pen.GetWidth();
                            //fout.write((char*)&OBJ_DATA[i].oper,sizeof(int));
                            fout.write((char*)&r,sizeof(int));
                            fout.write((char*)&g,sizeof(int));
                            fout.write((char*)&b,sizeof(int));
                            fout.write((char*)&a,sizeof(int));

                            fout.write((char*)&penStyle,sizeof(int));
                            fout.write((char*)&penWidth,sizeof(int));

                            OBJ_DATA[i].brush.GetRGBA(r,g,b,a);
                            int brushStyle=OBJ_DATA[i].brush.GetStyle();
                            fout.write((char*)&r,sizeof(int));
                            fout.write((char*)&g,sizeof(int));
                            fout.write((char*)&b,sizeof(int));
                            fout.write((char*)&a,sizeof(int));
                            fout.write((char*)&brushStyle,sizeof(int));

                            fout.write((char*)&x1,sizeof(int));
                            fout.write((char*)&y1,sizeof(int));
                            fout.write((char*)&r1,sizeof(int));
                            fout.write((char*)&r2,sizeof(int));
                        }
                        break;
                    }
                    case 4://круг
                    {
                        int x1,y1,r1;//координаты центра и радиусы
                        bool flag_X_1,flag_Y_1,flag_r_1;

                        //получаем значения ячеек
                        QTableWidgetItem* item_x1 = ui->tableWidget->item(2*i+1, 1);
                        QTableWidgetItem* item_y1 = ui->tableWidget->item(2*i+1, 2);
                        QTableWidgetItem* item_r1 = ui->tableWidget->item(2*i+1, 3);

                        //проверка на то что они существуют
                        if(item_x1!=nullptr && item_y1!=nullptr && item_r1!=nullptr){

                            //проверка на int
                            x1=item_x1->text().toInt(&flag_X_1);
                            y1=item_y1->text().toInt(&flag_Y_1);
                            r1=item_r1->text().toInt(&flag_r_1);
                            int r,g,b,a;
                            OBJ_DATA[i].pen.GetRGBA(r,g,b,a);
                            int penStyle=OBJ_DATA[i].pen.GetStyle();
                            int penWidth=OBJ_DATA[i].pen.GetWidth();
                            //fout.write((char*)&OBJ_DATA[i].oper,sizeof(int));
                            fout.write((char*)&r,sizeof(int));
                            fout.write((char*)&g,sizeof(int));
                            fout.write((char*)&b,sizeof(int));
                            fout.write((char*)&a,sizeof(int));

                            fout.write((char*)&penStyle,sizeof(int));
                            fout.write((char*)&penWidth,sizeof(int));

                            OBJ_DATA[i].brush.GetRGBA(r,g,b,a);
                            int brushStyle=OBJ_DATA[i].brush.GetStyle();
                            fout.write((char*)&r,sizeof(int));
                            fout.write((char*)&g,sizeof(int));
                            fout.write((char*)&b,sizeof(int));
                            fout.write((char*)&a,sizeof(int));
                            fout.write((char*)&brushStyle,sizeof(int));

                            fout.write((char*)&x1,sizeof(int));
                            fout.write((char*)&y1,sizeof(int));
                            fout.write((char*)&r1,sizeof(int));
                        }
                        break;
                    }
                    case 5://дуга
                    {
                        int x1,y1,r1,r2,c1,c2;//координаты центра, радиусы, угол стартовый и угол пролета
                        bool flag_X_1,flag_Y_1,flag_r_1,flag_r_2,flag_c_1,flag_c_2;
                        arc m_arc;//моя дуга

                        //получаем значения ячеек
                        QTableWidgetItem* item_x1 = ui->tableWidget->item(2*i+1, 1);
                        QTableWidgetItem* item_y1 = ui->tableWidget->item(2*i+1, 2);
                        QTableWidgetItem* item_r1 = ui->tableWidget->item(2*i+1, 3);
                        QTableWidgetItem* item_r2 = ui->tableWidget->item(2*i+1, 4);
                        QTableWidgetItem* item_c1 = ui->tableWidget->item(2*i+1, 5);
                        QTableWidgetItem* item_c2 = ui->tableWidget->item(2*i+1, 6);

                        //проверка на то что они существуют
                        if(item_x1!=nullptr && item_y1!=nullptr && item_r1!=nullptr && item_r2!=nullptr && item_c1!=nullptr && item_c2!=nullptr ){

                            //проверка на int
                            x1=item_x1->text().toInt(&flag_X_1);
                            y1=item_y1->text().toInt(&flag_Y_1);
                            r1=item_r1->text().toInt(&flag_r_1);
                            r2=item_r2->text().toInt(&flag_r_2);
                            c1=item_c1->text().toInt(&flag_c_1);
                            c2=item_c2->text().toInt(&flag_c_2);
                            int r,g,b,a;
                            OBJ_DATA[i].pen.GetRGBA(r,g,b,a);
                            int penStyle=OBJ_DATA[i].pen.GetStyle();
                            int penWidth=OBJ_DATA[i].pen.GetWidth();
                            //fout.write((char*)&OBJ_DATA[i].oper,sizeof(int));
                            fout.write((char*)&r,sizeof(int));
                            fout.write((char*)&g,sizeof(int));
                            fout.write((char*)&b,sizeof(int));
                            fout.write((char*)&a,sizeof(int));

                            fout.write((char*)&penStyle,sizeof(int));
                            fout.write((char*)&penWidth,sizeof(int));

                            fout.write((char*)&x1,sizeof(int));
                            fout.write((char*)&y1,sizeof(int));
                            fout.write((char*)&r1,sizeof(int));
                            fout.write((char*)&r2,sizeof(int));
                            fout.write((char*)&c1,sizeof(int));
                            fout.write((char*)&c2,sizeof(int));

                        }
                        break;
                    }
                    case 6://ломаная
                    {
                        int r,g,b,a;
                        OBJ_DATA[i].pen.GetRGBA(r,g,b,a);
                        int penStyle=OBJ_DATA[i].pen.GetStyle();
                        int penWidth=OBJ_DATA[i].pen.GetWidth();
                        //fout.write((char*)&OBJ_DATA[i].oper,sizeof(int));
                        fout.write((char*)&r,sizeof(int));
                        fout.write((char*)&g,sizeof(int));
                        fout.write((char*)&b,sizeof(int));
                        fout.write((char*)&a,sizeof(int));

                        fout.write((char*)&penStyle,sizeof(int));
                        fout.write((char*)&penWidth,sizeof(int));
                        int vectorSize = OBJ_DATA[i].POINTS_VECTOR->size();
                        fout.write((char*)&vectorSize,sizeof(int));
                        for(int j = 0; j < vectorSize; j++)
                        {
                            int point = OBJ_DATA[i].POINTS_VECTOR->at(j);
                            fout.write(reinterpret_cast<const char*>(&point), sizeof(int));
                        }
                        break;
                    }
                    case 7://полигон
                    {
                        int r,g,b,a;
                        OBJ_DATA[i].pen.GetRGBA(r,g,b,a);
                        int penStyle=OBJ_DATA[i].pen.GetStyle();
                        int penWidth=OBJ_DATA[i].pen.GetWidth();
                        //fout.write((char*)&OBJ_DATA[i].oper,sizeof(int));
                        fout.write((char*)&r,sizeof(int));
                        fout.write((char*)&g,sizeof(int));
                        fout.write((char*)&b,sizeof(int));
                        fout.write((char*)&a,sizeof(int));

                        fout.write((char*)&penStyle,sizeof(int));
                        fout.write((char*)&penWidth,sizeof(int));

                        OBJ_DATA[i].brush.GetRGBA(r,g,b,a);
                        int brushStyle=OBJ_DATA[i].brush.GetStyle();
                        fout.write((char*)&r,sizeof(int));
                        fout.write((char*)&g,sizeof(int));
                        fout.write((char*)&b,sizeof(int));
                        fout.write((char*)&a,sizeof(int));
                        fout.write((char*)&brushStyle,sizeof(int));
                        int vectorSize = OBJ_DATA[i].POINTS_VECTOR->size();
                        fout.write((char*)&vectorSize,sizeof(int));
                        //fout.write(reinterpret_cast<const char*>(&vectorSize),sizeof(int));
                        for(int j = 0; j < vectorSize; j++)
                        {
                            int point = OBJ_DATA[i].POINTS_VECTOR->at(j);
                            fout.write(reinterpret_cast<const char*>(&point), sizeof(int));

                            // тоже самое как и до этого делали, просто другой способ(const=данные не будут изменены, а так отличий нет)
                            //reinterpret_cast
                            //Оператор приведения reinterpret_cast используется для приведения несовместимых типов. Может приводить целое число к указателю, указатель к целому числу, указатель к указателю
                        }

                        break;
                    }
                  }
                }
                fout.close();//закрываем
                QString checksum_1=getFileChecksum(filename);//получаем контрольную сумму
                //открываем снова, чтобы записать контрольную сумму
//                QHash<QString,QString> Hash;
//                Hash.insert(filename,checksum_1);
                std::ofstream fout1(filename.toStdString(), std::ios_base::binary | std::ios_base::app);
                fout1.write(checksum_1.toStdString().c_str(), checksum_1.length());//записываем в конце файла контрольную сумму
                fout1.close();

                QMessageBox::information(this, "infotmation", "Файл успешно сохранен");
            }
            else
            {
                // Если не открыто
                QMessageBox::critical(this, "Error", "Не удаётся открыть файл");
            }
        }
    }
}
void MainWindow::on_pushButton_open_clicked()//открытие файла
{
    open_change=1;
    int cur_rows=ui->tableWidget->rowCount();
    QString fileName = QFileDialog::getOpenFileName(this, "Открыть файл", "", tr("Text files (*.bin)"));//диалоговое окно для работы с файлом
    std::string filename;//объявляем имя файла
    filename=fileName.toStdString();//в string из QString

    QString extension = QFileInfo(fileName).suffix();//получаем расширение файла

    if (fileName.isEmpty())
    {
        //если не выбрали файл, то выводим ошибку
        QMessageBox::information(this, "Error", "Файл не выбран");
    }
    else
    {
        if(extension!="bin"){
            QMessageBox::critical(this, "Ошибка", "Расширение не бинарного файла");
        }
        else{
            QString last64Bytes;
            std::ifstream fout1(filename,std::ios_base::binary);
            fout1.seekg(-64, std::ios_base::end);
            char buffer[65] = {0};
            fout1.read(buffer, 64); //читаем последние 64 бита
            last64Bytes = QString::fromLatin1(buffer, 64);//запоминаем последние 64 симола-кэш сумму //было toLatin1
            fout1.seekg(0);            
            fout1.close();
            QFile file_h(fileName);

            if (file_h.open(QIODevice::ReadWrite)) {//удаляем последние 64 символа файла(там хранится контрольная сумма)
                qint64 fileSize = file_h.size();

                //удаляем последние 64 бита
                qint64 newPosition = fileSize - 64;
                file_h.seek(newPosition);
                file_h.resize(newPosition);

                file_h.close();

                QString chsum=getFileChecksum(fileName);
                std::ofstream foutAppend(fileName.toStdString(), std::ios_base::binary | std::ios_base::app);
                foutAppend.write(last64Bytes.toStdString().c_str(), last64Bytes.length());//добавляем обратно контрольную сумму
                foutAppend.close();
                if(last64Bytes!=chsum){
                    QMessageBox::warning(this, "Error", "Контрольные суммы отличаются, файл не будет открыт");
                }
                else{
                    int rows;
                    std::ifstream fout(filename,std::ios_base::binary);//открываем
                    fout.seekg(0, std::ios_base::end);//идем в конец
                    long long uSize = fout.tellg();//получаем размер файла
                    fout.seekg(0);//обратно возвращаемся в начало файла
                    if(uSize%4==0){//проверка на кратность 4
                        fout.read((char*)&rows,sizeof(int));
                        int index=rows;//количество элементов
                        rows=rows*2;//количество строк, которые мы отрисуем(в 2 рааз больше элементов)
                        if(rows<0){
                            QMessageBox::information(this, "Error", "Количество элементов больше 0");
                            return;
                        }
                        if(rows!=0){
                            //количество элементов, операция, цвет контура, стиль контура, толщина контура, (если есть: цвет заливки, стиль заливки) координаты ( или вектор точек).

                            //устанавливаем количество строк
                            ui->tableWidget->setRowCount(rows);
                            ui->spinBox->setValue(index);
                            for(int j=0;j<cur_rows;j++){//очистка таблицы
                                clearItems(j);//очищаем ячейки
                                //очищаем остальные ячейки
                                QTableWidgetItem * twi = ui->tableWidget->item(j, 0);
                                if (twi != nullptr)
                                {
                                    twi->setText("");
                                    //twi->setBackground(Qt::white);
                                }
                                twi = ui->tableWidget->item(j+1, 0);
                                if (twi != nullptr)
                                {
                                    twi->setText("");
                                    //twi->setBackground(Qt::white);
                                }
                                ui->tableWidget->removeCellWidget(j, 0);
                                ui->tableWidget->removeCellWidget(j+1, 0);

                            }
                            int j=0;//идем от текущего элемента
                            QTableWidgetItem * twi;//создаем ячейку
                            QComboBox * cb;//создаем combobox


                            QString error="";
                            OBJ_DATA=new T_DATA[index];//выделили память под новые данные
                            while(j<rows){
                                //задаем надписи для пользователя в нужных ячейках
                                twi=new QTableWidgetItem;
                                twi->setText("Объект");
                                twi->setFlags(twi->flags() & 0xfffffffd);//запрещаем изменение ячейки с помощью побитового И(&) на код Qt::ItemIsEditable, который имеет значение 2(по умолчанию в Qt),для этого из макс значения вычитаем 10(2 в 2сс) 0xfffffffff=1111 1111.... 1111,0xfffffffd=1111...1101, тип данных int в языке C++ имеет размер 4 байта (32 бита). В 16-ричной системе счисления каждый знак представляет 4 бита, поэтому 8 знаков соответствуют 32 битам. Можно было и так конечно, но нужно было показать суть того, как это получается (item->flags() & Qt::ItemIsEditable).
                                ui->tableWidget->setItem(j,0,twi);


                                cb=new QComboBox;
                                cb->addItem("Пиксель");
                                cb->addItem("Линия");
                                cb->addItem("Прямоугольник");
                                cb->addItem("Эллипс");
                                cb->addItem("Круг");
                                cb->addItem("Дуга");
                                cb->addItem("Ломаная");
                                cb->addItem("Полигон");
                                cb->setProperty("row",j+1);
                                int r,g,b,a;
                                int st,wd;
                                int i=j/2;
                                int oper;
                                fout.read((char*)&oper,sizeof(int));//считываем операцию
                                switch (oper) {
                                case 0:{//пиксель
                                    getPixel(j);
                                    cb->setCurrentIndex(0);
                                    OBJ_DATA[i].oper=0;

                                    fout.read((char*)&r,sizeof(int));
                                    fout.read((char*)&g,sizeof(int));
                                    fout.read((char*)&b,sizeof(int));
                                    fout.read((char*)&a,sizeof(int));
                                    OBJ_DATA[i].pen.SetRGBA(r,g,b,a);
                                    int x1,y1;
                                    fout.read((char*)&x1,sizeof(int));
                                    fout.read((char*)&y1,sizeof(int));

                                    twi = new QTableWidgetItem;
                                    twi->setText(QString::number(x1));
                                    ui->tableWidget->setItem(j+1, 1, twi);
                                    twi = new QTableWidgetItem;
                                    twi->setText(QString::number(y1));
                                    ui->tableWidget->setItem(j+1, 2, twi);

                                    OBJ_DATA[i].pen.SetStyle(1);
                                    OBJ_DATA[i].pen.SetWidth(1);

                                    OBJ_DATA[i].brush.SetStyle(1);
                                    OBJ_DATA[i].brush.SetRGBA(0,0,0,255);
                                    OBJ_DATA[i].kol=0;
                                    OBJ_DATA[i].POINTS_VECTOR=new QVector<int>();
                                    QColor c;
                                    c=QColor(r,g,b,a);

                                    break;
                                }
                                case 1:{//линия
                                    getLine(j);                                    
                                    OBJ_DATA[i].oper=1;

                                    fout.read((char*)&r,sizeof(int));
                                    fout.read((char*)&g,sizeof(int));
                                    fout.read((char*)&b,sizeof(int));
                                    fout.read((char*)&a,sizeof(int));
                                    OBJ_DATA[i].pen.SetRGBA(r,g,b,a);

                                    fout.read((char*)&st,sizeof(int));
                                    fout.read((char*)&wd,sizeof(int));
                                    OBJ_DATA[i].pen.SetStyle(st);
                                    OBJ_DATA[i].pen.SetWidth(wd);

                                    int x1,y1,x2,y2;
                                    fout.read((char*)&x1,sizeof(int));
                                    fout.read((char*)&y1,sizeof(int));
                                    fout.read((char*)&x2,sizeof(int));
                                    fout.read((char*)&y2,sizeof(int));

                                    twi = new QTableWidgetItem;
                                    twi->setText(QString::number(x1));
                                    ui->tableWidget->setItem(j+1, 1, twi);
                                    twi = new QTableWidgetItem;
                                    twi->setText(QString::number(y1));
                                    ui->tableWidget->setItem(j+1, 2, twi);
                                    twi = new QTableWidgetItem;
                                    twi->setText(QString::number(x2));
                                    ui->tableWidget->setItem(j+1, 3, twi);
                                    twi = new QTableWidgetItem;
                                    twi->setText(QString::number(y2));
                                    ui->tableWidget->setItem(j+1, 4, twi);


                                    OBJ_DATA[i].brush.SetStyle(1);
                                    OBJ_DATA[i].brush.SetRGBA(0,0,0,255);
                                    OBJ_DATA[i].kol=0;
                                    OBJ_DATA[i].POINTS_VECTOR=new QVector<int>();
                                    break;
                                }
                                case 2:{//прямоугольник
                                    getLine(j);
                                    OBJ_DATA[i].oper=2;
                                    cb->setCurrentIndex(2);
                                    fout.read((char*)&r,sizeof(int));
                                    fout.read((char*)&g,sizeof(int));
                                    fout.read((char*)&b,sizeof(int));
                                    fout.read((char*)&a,sizeof(int));
                                    OBJ_DATA[i].pen.SetRGBA(r,g,b,a);

                                    fout.read((char*)&st,sizeof(int));
                                    fout.read((char*)&wd,sizeof(int));
                                    OBJ_DATA[i].pen.SetStyle(st);
                                    OBJ_DATA[i].pen.SetWidth(wd);

                                    fout.read((char*)&r,sizeof(int));
                                    fout.read((char*)&g,sizeof(int));
                                    fout.read((char*)&b,sizeof(int));
                                    fout.read((char*)&a,sizeof(int));
                                    OBJ_DATA[i].brush.SetRGBA(r,g,b,a);

                                    fout.read((char*)&st,sizeof(int));
                                    OBJ_DATA[i].brush.SetStyle(st);


                                    int x1,y1,x2,y2;
                                    fout.read((char*)&x1,sizeof(int));
                                    fout.read((char*)&y1,sizeof(int));
                                    fout.read((char*)&x2,sizeof(int));
                                    fout.read((char*)&y2,sizeof(int));

                                    twi = new QTableWidgetItem;
                                    twi->setText(QString::number(x1));
                                    ui->tableWidget->setItem(j+1, 1, twi);
                                    twi = new QTableWidgetItem;
                                    twi->setText(QString::number(y1));
                                    ui->tableWidget->setItem(j+1, 2, twi);
                                    twi = new QTableWidgetItem;
                                    twi->setText(QString::number(x2));
                                    ui->tableWidget->setItem(j+1, 3, twi);
                                    twi = new QTableWidgetItem;
                                    twi->setText(QString::number(y2));
                                    ui->tableWidget->setItem(j+1, 4, twi);

                                    OBJ_DATA[i].kol=0;
                                    OBJ_DATA[i].POINTS_VECTOR=new QVector<int>();
                                    break;
                                }
                                case 3:{//эллипс
                                    getEllipse(j);
                                    cb->setCurrentIndex(3);
                                    OBJ_DATA[i].oper=3;
                                    fout.read((char*)&r,sizeof(int));
                                    fout.read((char*)&g,sizeof(int));
                                    fout.read((char*)&b,sizeof(int));
                                    fout.read((char*)&a,sizeof(int));
                                    OBJ_DATA[i].pen.SetRGBA(r,g,b,a);

                                    fout.read((char*)&st,sizeof(int));
                                    fout.read((char*)&wd,sizeof(int));
                                    OBJ_DATA[i].pen.SetStyle(st);
                                    OBJ_DATA[i].pen.SetWidth(wd);

                                    fout.read((char*)&r,sizeof(int));
                                    fout.read((char*)&g,sizeof(int));
                                    fout.read((char*)&b,sizeof(int));
                                    fout.read((char*)&a,sizeof(int));
                                    OBJ_DATA[i].brush.SetRGBA(r,g,b,a);

                                    fout.read((char*)&st,sizeof(int));
                                    OBJ_DATA[i].brush.SetStyle(st);


                                    int x1,y1,r1,r2;
                                    fout.read((char*)&x1,sizeof(int));
                                    fout.read((char*)&y1,sizeof(int));
                                    fout.read((char*)&r1,sizeof(int));
                                    fout.read((char*)&r2,sizeof(int));

                                    twi = new QTableWidgetItem;
                                    twi->setText(QString::number(x1));
                                    ui->tableWidget->setItem(j+1, 1, twi);
                                    twi = new QTableWidgetItem;
                                    twi->setText(QString::number(y1));
                                    ui->tableWidget->setItem(j+1, 2, twi);
                                    twi = new QTableWidgetItem;
                                    twi->setText(QString::number(r1));
                                    ui->tableWidget->setItem(j+1, 3, twi);
                                    twi = new QTableWidgetItem;
                                    twi->setText(QString::number(r2));
                                    ui->tableWidget->setItem(j+1, 4, twi);

                                    OBJ_DATA[i].kol=0;
                                    OBJ_DATA[i].POINTS_VECTOR=new QVector<int>();
                                    break;
                                }
                                case 4:{//круг
                                    getCircle(j);
                                    cb->setCurrentIndex(4);
                                    OBJ_DATA[i].oper=4;
                                    fout.read((char*)&r,sizeof(int));
                                    fout.read((char*)&g,sizeof(int));
                                    fout.read((char*)&b,sizeof(int));
                                    fout.read((char*)&a,sizeof(int));
                                    OBJ_DATA[i].pen.SetRGBA(r,g,b,a);

                                    fout.read((char*)&st,sizeof(int));
                                    fout.read((char*)&wd,sizeof(int));
                                    OBJ_DATA[i].pen.SetStyle(st);
                                    OBJ_DATA[i].pen.SetWidth(wd);

                                    fout.read((char*)&r,sizeof(int));
                                    fout.read((char*)&g,sizeof(int));
                                    fout.read((char*)&b,sizeof(int));
                                    fout.read((char*)&a,sizeof(int));
                                    OBJ_DATA[i].brush.SetRGBA(r,g,b,a);

                                    fout.read((char*)&st,sizeof(int));
                                    OBJ_DATA[i].brush.SetStyle(st);

                                    int x1,y1,r1;
                                    fout.read((char*)&x1,sizeof(int));
                                    fout.read((char*)&y1,sizeof(int));
                                    fout.read((char*)&r1,sizeof(int));

                                    twi = new QTableWidgetItem;
                                    twi->setText(QString::number(x1));
                                    ui->tableWidget->setItem(j+1, 1, twi);
                                    twi = new QTableWidgetItem;
                                    twi->setText(QString::number(y1));
                                    ui->tableWidget->setItem(j+1, 2, twi);
                                    twi = new QTableWidgetItem;
                                    twi->setText(QString::number(r1));
//                                    ui->tableWidget->setItem(j+1, 3, twi);
//                                    twi = new QTableWidgetItem;

                                    OBJ_DATA[i].kol=0;
                                    OBJ_DATA[i].POINTS_VECTOR=new QVector<int>();
                                    break;
                                }
                                case 5:{//дуга
                                    getArc(j);
                                    cb->setCurrentIndex(5);
                                    OBJ_DATA[i].oper=5;

                                    fout.read((char*)&r,sizeof(int));
                                    fout.read((char*)&g,sizeof(int));
                                    fout.read((char*)&b,sizeof(int));
                                    fout.read((char*)&a,sizeof(int));
                                    OBJ_DATA[i].pen.SetRGBA(r,g,b,a);

                                    fout.read((char*)&st,sizeof(int));
                                    fout.read((char*)&wd,sizeof(int));
                                    OBJ_DATA[i].pen.SetStyle(st);
                                    OBJ_DATA[i].pen.SetWidth(wd);

                                    int x1,y1,r1,r2,c1,c2;
                                    fout.read((char*)&x1,sizeof(int));
                                    fout.read((char*)&y1,sizeof(int));
                                    fout.read((char*)&r1,sizeof(int));
                                    fout.read((char*)&r2,sizeof(int));
                                    fout.read((char*)&c1,sizeof(int));
                                    fout.read((char*)&c2,sizeof(int));

                                    twi = new QTableWidgetItem;
                                    twi->setText(QString::number(x1));
                                    ui->tableWidget->setItem(j+1, 1, twi);
                                    twi = new QTableWidgetItem;
                                    twi->setText(QString::number(y1));
                                    ui->tableWidget->setItem(j+1, 2, twi);
                                    twi = new QTableWidgetItem;
                                    twi->setText(QString::number(r1));
                                    ui->tableWidget->setItem(j+1, 3, twi);
                                    twi = new QTableWidgetItem;
                                    twi->setText(QString::number(r2));
                                    ui->tableWidget->setItem(j+1, 4, twi);
                                    twi = new QTableWidgetItem;
                                    twi->setText(QString::number(c1));
                                    ui->tableWidget->setItem(j+1, 5, twi);
                                    twi = new QTableWidgetItem;
                                    twi->setText(QString::number(c2));
                                    ui->tableWidget->setItem(j+1, 6, twi);

                                    OBJ_DATA[i].brush.SetStyle(1);
                                    OBJ_DATA[i].brush.SetRGBA(0,0,0,255);
                                    OBJ_DATA[i].kol=0;
                                    OBJ_DATA[i].POINTS_VECTOR=new QVector<int>();
                                    break;
                                }
                                case 6:{//ломаная
                                    getPolyline(j);
                                    cb->setCurrentIndex(6);

                                    OBJ_DATA[i].oper=6;

                                    fout.read((char*)&r,sizeof(int));
                                    fout.read((char*)&g,sizeof(int));
                                    fout.read((char*)&b,sizeof(int));
                                    fout.read((char*)&a,sizeof(int));
                                    OBJ_DATA[i].pen.SetRGBA(r,g,b,a);

                                    fout.read((char*)&st,sizeof(int));
                                    fout.read((char*)&wd,sizeof(int));
                                    OBJ_DATA[i].pen.SetStyle(st);
                                    OBJ_DATA[i].pen.SetWidth(wd);
                                    int sz_v;
                                    fout.read((char*)&sz_v,sizeof(int));

                                    QVector<int> h_v{};
                                    for(int k=0;k<sz_v;k++){
                                        int elem;
                                        fout.read((char*)&elem,sizeof(int));
                                        h_v.append(elem);
                                    }
                                    if(sz_v<4){
                                        for(int k=sz_v;k<4;k++){
                                            h_v.append(0);
                                        }
                                        error+="Недостаточно точек для построения фигуры "+QString::number(i+1)+". Были добавлены новые точки c координатами (0,0)\n";
                                    }
                                    *OBJ_DATA[i].POINTS_VECTOR=h_v;
                                    OBJ_DATA[i].brush.SetStyle(1);
                                    OBJ_DATA[i].brush.SetRGBA(0,0,0,255);
                                    OBJ_DATA[i].kol=0;

                                    break;
                                }
                                case 7:{//полигон
                                    getPolygon(j);
                                    cb->setCurrentIndex(7);
                                    OBJ_DATA[i].oper=7;

                                    fout.read((char*)&r,sizeof(int));
                                    fout.read((char*)&g,sizeof(int));
                                    fout.read((char*)&b,sizeof(int));
                                    fout.read((char*)&a,sizeof(int));
                                    OBJ_DATA[i].pen.SetRGBA(r,g,b,a);

                                    fout.read((char*)&st,sizeof(int));
                                    fout.read((char*)&wd,sizeof(int));
                                    OBJ_DATA[i].pen.SetStyle(st);
                                    OBJ_DATA[i].pen.SetWidth(wd);

                                    fout.read((char*)&r,sizeof(int));
                                    fout.read((char*)&g,sizeof(int));
                                    fout.read((char*)&b,sizeof(int));
                                    fout.read((char*)&a,sizeof(int));
                                    OBJ_DATA[i].brush.SetRGBA(r,g,b,a);

                                    fout.read((char*)&st,sizeof(int));
                                    OBJ_DATA[i].brush.SetStyle(st);

                                    int sz_v;
                                    fout.read((char*)&sz_v,sizeof(int));
                                    QVector<int> h_v{};
                                    for(int k=0;k<sz_v;k++){
                                        int elem;
                                        fout.read((char*)&elem,sizeof(int));
                                        h_v.append(elem);
                                    }
                                    if(sz_v<6){
                                        for(int k=sz_v;k<6;k++){
                                            h_v.append(0);
                                        }
                                        error+="Недостаточно точек для построения фигуры "+QString::number(i+1)+". Были добавлены новые точки c координатами (0,0)\n";
                                    }


                                    *OBJ_DATA[i].POINTS_VECTOR=h_v;
                                    OBJ_DATA[i].kol=0;
                                    break;
                                    }
                                }

                                connect(cb,SIGNAL(activated(int)),this,SLOT(typeComboBox_clicked(int)));
                                connect(cb,SIGNAL(currentIndexChanged(int)),this,SLOT(typeComboBox_clicked(int)));
                                ui->tableWidget->setCellWidget(j+1,0,cb);

                                j+=2;
                            }
                            if(error!=""){
                                QMessageBox::warning(this, "Error", error);
                            }
                            //drawAll();
                        }
                        else {
                            //очищаем таблицу
                            for(int j=0;j<cur_rows;j++){
                                clearItems(j);
                            }
                            ui->spinBox->setValue(0);
                            ui->tableWidget->setRowCount(0);
                            //drawAll();
                        }
                    }
                    else{
                        QMessageBox::warning(this, "Error", "Размер файла не кратен 4");
                    }
                    fout.close();
                }
            }
        }
    }
    open_change=0;

}
void MainWindow::on_actionSha256_triggered()//перекидывает пользователя на сайт с подробным разбором построения заданной контрольной суммы
{
    QString link = "https://sha256algorithm.com/";
    QDesktopServices::openUrl(QUrl(link));//открываем ссылку в браузере, который является основным у пользователя
}
void MainWindow::on_pushButton_draw_clicked()
{
    QImage * im = &ui->widget->im;
    (*im).fill(0);//заполняем пустотой
    int cur_rows=ui->tableWidget->rowCount();//получаем количество строк
    if(cur_rows<0){//проверка
        cur_rows=0;
    }
    if (OBJ_DATA != nullptr) {//проверяем на существование наших данных
        for(int i=0;i<cur_rows/2;i++){
            int op=OBJ_DATA[i].oper;//получаем операцию
            if(op<0 || op>6){//проверка
                OBJ_DATA[i].oper=0;
            }
            switch (OBJ_DATA[i].oper) {//рисуем в зависимости от операции
            case 0://пиксель
            {
                drawPixel(i);
                break;
            }
            case 1://линия
            {
                drawLine(i);
                break;
            }
            case 2://прямоугольник
            {
                drawRectangle(i);
                break;
            }
            case 3://эллипс
            {
                drawEllipse(i);
                break;
            }
            case 4://круг
            {
                drawCircle(i);
                break;
            }
            case 5://дуга
            {
                drawKrivaya(i);
                break;
            }
            case 6://ломаная
            {
                drawLines(i);
                break;
            }
            case 7://полигон
            {
                drawPolygon(i);
                break;
            }

            }
        }
    }
    update();
   //drawAll();
}
void MainWindow::on_pushButton_clear_table_clicked()
{
    ui->spinBox->setValue(0);
}
void MainWindow::on_pushButton_clear_wiget_clicked()
{
    ui->widget->im.fill(0);
    update();
}





