/********************************************************************************
** Form generated from reading UI file 'dialog_1.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_1_H
#define UI_DIALOG_1_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>

QT_BEGIN_NAMESPACE

class Ui_Dialog_1
{
public:
    QLabel *labelHeader;
    QPushButton *pushButtonColor;
    QComboBox *comboBoxStyle;
    QLabel *labelStyle;
    QPushButton *pushButton_ok;
    QPushButton *pushButton_cancel;
    QPushButton *pushButtonColor_2;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLineEdit *lineEdit;
    QLabel *label_6;
    QLabel *label_7;
    QSpinBox *spinBox;
    QLabel *label_8;
    QLabel *labelStyle_2;
    QComboBox *comboBoxStyle_2;

    void setupUi(QDialog *Dialog_1)
    {
        if (Dialog_1->objectName().isEmpty())
            Dialog_1->setObjectName(QString::fromUtf8("Dialog_1"));
        Dialog_1->resize(532, 385);
        labelHeader = new QLabel(Dialog_1);
        labelHeader->setObjectName(QString::fromUtf8("labelHeader"));
        labelHeader->setGeometry(QRect(2, 10, 511, 21));
        QFont font;
        font.setPointSize(13);
        labelHeader->setFont(font);
        pushButtonColor = new QPushButton(Dialog_1);
        pushButtonColor->setObjectName(QString::fromUtf8("pushButtonColor"));
        pushButtonColor->setGeometry(QRect(130, 100, 171, 31));
        QFont font1;
        font1.setPointSize(10);
        pushButtonColor->setFont(font1);
        pushButtonColor->setAutoFillBackground(true);
        comboBoxStyle = new QComboBox(Dialog_1);
        comboBoxStyle->addItem(QString());
        comboBoxStyle->addItem(QString());
        comboBoxStyle->addItem(QString());
        comboBoxStyle->addItem(QString());
        comboBoxStyle->addItem(QString());
        comboBoxStyle->setObjectName(QString::fromUtf8("comboBoxStyle"));
        comboBoxStyle->setGeometry(QRect(130, 50, 171, 31));
        QFont font2;
        font2.setPointSize(8);
        comboBoxStyle->setFont(font2);
        labelStyle = new QLabel(Dialog_1);
        labelStyle->setObjectName(QString::fromUtf8("labelStyle"));
        labelStyle->setGeometry(QRect(14, 60, 101, 21));
        pushButton_ok = new QPushButton(Dialog_1);
        pushButton_ok->setObjectName(QString::fromUtf8("pushButton_ok"));
        pushButton_ok->setGeometry(QRect(140, 330, 75, 23));
        pushButton_cancel = new QPushButton(Dialog_1);
        pushButton_cancel->setObjectName(QString::fromUtf8("pushButton_cancel"));
        pushButton_cancel->setGeometry(QRect(270, 330, 75, 23));
        pushButtonColor_2 = new QPushButton(Dialog_1);
        pushButtonColor_2->setObjectName(QString::fromUtf8("pushButtonColor_2"));
        pushButtonColor_2->setGeometry(QRect(130, 260, 171, 31));
        pushButtonColor_2->setFont(font1);
        pushButtonColor_2->setAutoFillBackground(true);
        label_2 = new QLabel(Dialog_1);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(14, 110, 51, 21));
        label_3 = new QLabel(Dialog_1);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(14, 270, 51, 21));
        label_4 = new QLabel(Dialog_1);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(310, 50, 221, 121));
        label_5 = new QLabel(Dialog_1);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(13, 160, 111, 21));
        lineEdit = new QLineEdit(Dialog_1);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(400, 30, 101, 20));
        label_6 = new QLabel(Dialog_1);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(70, 110, 51, 21));
        label_7 = new QLabel(Dialog_1);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(70, 270, 51, 21));
        spinBox = new QSpinBox(Dialog_1);
        spinBox->setObjectName(QString::fromUtf8("spinBox"));
        spinBox->setGeometry(QRect(130, 160, 51, 22));
        label_8 = new QLabel(Dialog_1);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(320, 169, 201, 121));
        labelStyle_2 = new QLabel(Dialog_1);
        labelStyle_2->setObjectName(QString::fromUtf8("labelStyle_2"));
        labelStyle_2->setGeometry(QRect(14, 210, 101, 21));
        comboBoxStyle_2 = new QComboBox(Dialog_1);
        comboBoxStyle_2->addItem(QString());
        comboBoxStyle_2->addItem(QString());
        comboBoxStyle_2->addItem(QString());
        comboBoxStyle_2->addItem(QString());
        comboBoxStyle_2->addItem(QString());
        comboBoxStyle_2->addItem(QString());
        comboBoxStyle_2->addItem(QString());
        comboBoxStyle_2->addItem(QString());
        comboBoxStyle_2->addItem(QString());
        comboBoxStyle_2->addItem(QString());
        comboBoxStyle_2->addItem(QString());
        comboBoxStyle_2->addItem(QString());
        comboBoxStyle_2->addItem(QString());
        comboBoxStyle_2->setObjectName(QString::fromUtf8("comboBoxStyle_2"));
        comboBoxStyle_2->setGeometry(QRect(130, 210, 171, 31));
        QWidget::setTabOrder(comboBoxStyle, comboBoxStyle_2);
        QWidget::setTabOrder(comboBoxStyle_2, spinBox);
        QWidget::setTabOrder(spinBox, pushButtonColor);
        QWidget::setTabOrder(pushButtonColor, pushButtonColor_2);
        QWidget::setTabOrder(pushButtonColor_2, pushButton_ok);
        QWidget::setTabOrder(pushButton_ok, pushButton_cancel);
        QWidget::setTabOrder(pushButton_cancel, lineEdit);

        retranslateUi(Dialog_1);

        comboBoxStyle->setCurrentIndex(0);
        comboBoxStyle_2->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(Dialog_1);
    } // setupUi

    void retranslateUi(QDialog *Dialog_1)
    {
        Dialog_1->setWindowTitle(QApplication::translate("Dialog_1", "Dialog", nullptr));
        labelHeader->setText(QApplication::translate("Dialog_1", "<html><head/><body><p align=\"center\">\320\227\320\260\320\263\320\276\320\273\320\276\320\262\320\276\320\272</p></body></html>", nullptr));
        pushButtonColor->setText(QApplication::translate("Dialog_1", "\320\222\321\213\320\261\321\200\320\260\321\202\321\214 \321\206\320\262\320\265\321\202", nullptr));
        comboBoxStyle->setItemText(0, QApplication::translate("Dialog_1", "\320\221\320\265\320\267 \320\273\320\270\320\275\320\270\320\270", nullptr));
        comboBoxStyle->setItemText(1, QApplication::translate("Dialog_1", "\320\236\321\201\320\275\320\276\320\262\320\275\320\260\321\217", nullptr));
        comboBoxStyle->setItemText(2, QApplication::translate("Dialog_1", "\320\237\321\203\320\275\320\272\321\202\320\270\321\200\320\275\320\260\321\217", nullptr));
        comboBoxStyle->setItemText(3, QApplication::translate("Dialog_1", "\320\242\320\276\321\207\320\272\320\270", nullptr));
        comboBoxStyle->setItemText(4, QApplication::translate("Dialog_1", "\320\237\321\203\320\275\320\272\321\202\320\270\321\200+\321\202\320\276\321\207\320\272\320\270", nullptr));

        labelStyle->setText(QApplication::translate("Dialog_1", "\320\241\321\202\320\270\320\273\321\214 \320\233\320\270\320\275\320\270\320\270", nullptr));
        pushButton_ok->setText(QApplication::translate("Dialog_1", "Ok", nullptr));
        pushButton_cancel->setText(QApplication::translate("Dialog_1", "Cancel", nullptr));
        pushButtonColor_2->setText(QApplication::translate("Dialog_1", "\320\222\321\213\320\261\321\200\320\260\321\202\321\214 \321\206\320\262\320\265\321\202", nullptr));
        label_2->setText(QApplication::translate("Dialog_1", "\320\232\320\276\320\275\321\202\321\203\321\200", nullptr));
        label_3->setText(QApplication::translate("Dialog_1", "\320\227\320\260\320\272\321\200\320\260\321\201\320\272\320\260", nullptr));
        label_4->setText(QApplication::translate("Dialog_1", "<html><head/><body><p><span style=\" font-size:7pt;\">\320\242\320\243\320\242 \320\221\320\243\320\224\320\225\320\242 \320\230\320\227\320\236\320\221\320\240\320\220\320\226\320\225\320\235\320\230\320\225 \320\241\320\242\320\230\320\233\320\257 \320\233\320\230\320\235\320\230\320\230</span></p></body></html>", nullptr));
        label_5->setText(QApplication::translate("Dialog_1", "\320\250\320\270\321\200\320\270\320\275\320\260:", nullptr));
        label_6->setText(QString());
        label_7->setText(QString());
        label_8->setText(QApplication::translate("Dialog_1", "<html><head/><body><p><span style=\" font-size:7pt;\">\320\242\320\243\320\242 \320\221\320\243\320\224\320\225\320\242 \320\230\320\227\320\236\320\221\320\240\320\220\320\226\320\225\320\235\320\230\320\225 \320\241\320\242\320\230\320\233\320\257 \320\227\320\220\320\232\320\240\320\220\320\241\320\232\320\230</span></p></body></html>", nullptr));
        labelStyle_2->setText(QApplication::translate("Dialog_1", "\320\241\321\202\320\270\320\273\321\214 \320\227\320\260\320\272\321\200\320\260\321\201\320\272\320\270", nullptr));
        comboBoxStyle_2->setItemText(0, QApplication::translate("Dialog_1", "\320\235\320\265\321\202 \320\267\320\260\320\273\320\270\320\262\320\272\320\270", nullptr));
        comboBoxStyle_2->setItemText(1, QApplication::translate("Dialog_1", "\320\236\320\264\320\275\320\276\321\202\320\276\320\275\320\275\320\260\321\217", nullptr));
        comboBoxStyle_2->setItemText(2, QApplication::translate("Dialog_1", "\320\242\320\276\321\207\320\272\320\270(||)(\321\206\320\262\320\265\321\202\320\260 \321\204\320\276\320\275\320\260)", nullptr));
        comboBoxStyle_2->setItemText(3, QApplication::translate("Dialog_1", "\320\242\320\276\321\207\320\272\320\270(\321\206\320\262\320\265\321\202\320\260 \321\204\320\276\320\275\320\260)", nullptr));
        comboBoxStyle_2->setItemText(4, QApplication::translate("Dialog_1", "\320\237\320\273\321\216\321\201\320\270\320\272\320\270(\321\206\320\262\320\265\321\202\320\260 \320\267\320\260\320\273\320\270\320\262\320\272\320\270)", nullptr));
        comboBoxStyle_2->setItemText(5, QApplication::translate("Dialog_1", "\320\237\320\270\320\272\321\201\320\265\320\273\320\270", nullptr));
        comboBoxStyle_2->setItemText(6, QApplication::translate("Dialog_1", "\320\237\320\273\321\216\321\201\320\270\320\272\320\270(\321\206\320\262\320\265\321\202\320\260 \321\204\320\276\320\275\320\260)", nullptr));
        comboBoxStyle_2->setItemText(7, QApplication::translate("Dialog_1", "\320\242\320\276\321\207\320\272\320\270(\321\206\320\262\320\265\321\202\320\260 \320\267\320\260\320\273\320\270\320\262\320\272\320\270)", nullptr));
        comboBoxStyle_2->setItemText(8, QApplication::translate("Dialog_1", "\320\242\320\276\321\207\320\272\320\270(||)(\321\206\320\262\320\265\321\202\320\260 \320\267\320\260\320\273\320\270\320\262\320\272\320\270)", nullptr));
        comboBoxStyle_2->setItemText(9, QApplication::translate("Dialog_1", "\320\223\320\276\321\200\320\270\320\267\320\276\320\275\321\202\320\260\320\273\321\214\320\275\321\213\320\265 \320\273\320\270\320\275\320\270\320\270", nullptr));
        comboBoxStyle_2->setItemText(10, QApplication::translate("Dialog_1", "\320\222\320\265\321\200\321\202\320\270\320\272\320\260\320\273\321\214\320\275\321\213\320\265 \320\273\320\270\320\275\320\270\320\270", nullptr));
        comboBoxStyle_2->setItemText(11, QApplication::translate("Dialog_1", "\320\232\321\200\320\265\321\201\321\202\320\270\320\272\320\270", nullptr));
        comboBoxStyle_2->setItemText(12, QApplication::translate("Dialog_1", "\320\224\320\270\320\260\320\263\320\276\320\275\320\260\320\273\321\214\320\275\320\260\321\217 \320\262\320\276\320\273\320\275\320\260", nullptr));

    } // retranslateUi

};

namespace Ui {
    class Dialog_1: public Ui_Dialog_1 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_1_H
