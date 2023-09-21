/********************************************************************************
** Form generated from reading UI file 'okno.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_OKNO_H
#define UI_OKNO_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_okno
{
public:
    QWidget *centralwidget;
    QPushButton *pushButton_Close;
    QPushButton *pushButtonColor_Brush;
    QLabel *label_Header;
    QLabel *label_Style;
    QComboBox *comboBox_Style;
    QPushButton *pushButton_Ok;
    QPushButton *pushButtonColor_Pen;
    QLabel *label_color_1;
    QLabel *label_color_2;
    QLabel *label;
    QLabel *label_width;
    QLineEdit *lineEdit_width;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *okno)
    {
        if (okno->objectName().isEmpty())
            okno->setObjectName(QString::fromUtf8("okno"));
        okno->resize(519, 420);
        centralwidget = new QWidget(okno);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        pushButton_Close = new QPushButton(centralwidget);
        pushButton_Close->setObjectName(QString::fromUtf8("pushButton_Close"));
        pushButton_Close->setGeometry(QRect(430, 320, 81, 31));
        pushButtonColor_Brush = new QPushButton(centralwidget);
        pushButtonColor_Brush->setObjectName(QString::fromUtf8("pushButtonColor_Brush"));
        pushButtonColor_Brush->setGeometry(QRect(100, 190, 211, 31));
        QFont font;
        font.setPointSize(10);
        pushButtonColor_Brush->setFont(font);
        pushButtonColor_Brush->setAutoFillBackground(true);
        label_Header = new QLabel(centralwidget);
        label_Header->setObjectName(QString::fromUtf8("label_Header"));
        label_Header->setGeometry(QRect(20, 20, 93, 21));
        QFont font1;
        font1.setPointSize(13);
        label_Header->setFont(font1);
        label_Style = new QLabel(centralwidget);
        label_Style->setObjectName(QString::fromUtf8("label_Style"));
        label_Style->setGeometry(QRect(10, 60, 81, 21));
        comboBox_Style = new QComboBox(centralwidget);
        comboBox_Style->addItem(QString());
        comboBox_Style->addItem(QString());
        comboBox_Style->addItem(QString());
        comboBox_Style->addItem(QString());
        comboBox_Style->setObjectName(QString::fromUtf8("comboBox_Style"));
        comboBox_Style->setGeometry(QRect(100, 60, 211, 24));
        pushButton_Ok = new QPushButton(centralwidget);
        pushButton_Ok->setObjectName(QString::fromUtf8("pushButton_Ok"));
        pushButton_Ok->setGeometry(QRect(350, 320, 71, 31));
        pushButtonColor_Pen = new QPushButton(centralwidget);
        pushButtonColor_Pen->setObjectName(QString::fromUtf8("pushButtonColor_Pen"));
        pushButtonColor_Pen->setGeometry(QRect(100, 250, 211, 31));
        pushButtonColor_Pen->setFont(font);
        pushButtonColor_Pen->setAutoFillBackground(true);
        label_color_1 = new QLabel(centralwidget);
        label_color_1->setObjectName(QString::fromUtf8("label_color_1"));
        label_color_1->setGeometry(QRect(10, 190, 81, 31));
        label_color_2 = new QLabel(centralwidget);
        label_color_2->setObjectName(QString::fromUtf8("label_color_2"));
        label_color_2->setGeometry(QRect(10, 250, 81, 31));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(100, 90, 210, 90));
        label_width = new QLabel(centralwidget);
        label_width->setObjectName(QString::fromUtf8("label_width"));
        label_width->setGeometry(QRect(330, 50, 51, 41));
        lineEdit_width = new QLineEdit(centralwidget);
        lineEdit_width->setObjectName(QString::fromUtf8("lineEdit_width"));
        lineEdit_width->setGeometry(QRect(390, 59, 121, 21));
        okno->setCentralWidget(centralwidget);
        menubar = new QMenuBar(okno);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 519, 21));
        okno->setMenuBar(menubar);
        statusbar = new QStatusBar(okno);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        okno->setStatusBar(statusbar);

        retranslateUi(okno);

        comboBox_Style->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(okno);
    } // setupUi

    void retranslateUi(QMainWindow *okno)
    {
        okno->setWindowTitle(QApplication::translate("okno", "MainWindow", nullptr));
        pushButton_Close->setText(QApplication::translate("okno", "Close", nullptr));
        pushButtonColor_Brush->setText(QApplication::translate("okno", "\320\227\320\260\320\264\320\260\321\202\321\214 \321\206\320\262\320\265\321\202", nullptr));
        label_Header->setText(QApplication::translate("okno", "\320\227\320\260\320\263\320\276\320\273\320\276\320\262\320\276\320\272", nullptr));
        label_Style->setText(QApplication::translate("okno", "\320\222\321\213\320\261\321\200\320\260\321\202\321\214 \321\201\321\202\320\270\320\273\321\214:", nullptr));
        comboBox_Style->setItemText(0, QApplication::translate("okno", "\320\236\321\201\320\275\320\276\320\262\320\260\320\275\321\217", nullptr));
        comboBox_Style->setItemText(1, QApplication::translate("okno", "\320\237\321\203\320\275\320\272\321\202\320\270\321\200\320\275\320\260\321\217", nullptr));
        comboBox_Style->setItemText(2, QApplication::translate("okno", "\320\242\320\276\321\207\320\272\320\270", nullptr));
        comboBox_Style->setItemText(3, QApplication::translate("okno", "\320\237\321\203\320\275\320\272\321\202\320\270\321\200+\320\242\320\276\321\207\320\272\320\270", nullptr));

        pushButton_Ok->setText(QApplication::translate("okno", "Ok", nullptr));
        pushButtonColor_Pen->setText(QApplication::translate("okno", "\320\227\320\260\320\264\320\260\321\202\321\214 \321\206\320\262\320\265\321\202", nullptr));
        label_color_1->setText(QApplication::translate("okno", "\320\246\320\262\320\265\321\202 \320\267\320\260\320\273\320\270\320\262\320\272\320\270:", nullptr));
        label_color_2->setText(QApplication::translate("okno", "\320\246\320\262\320\265\321\202 \320\272\320\276\320\275\321\202\321\203\321\200\320\260:", nullptr));
        label->setText(QApplication::translate("okno", "TextLabel", nullptr));
        label_width->setText(QApplication::translate("okno", "\320\250\320\270\321\200\320\270\320\275\320\260:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class okno: public Ui_okno {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OKNO_H
