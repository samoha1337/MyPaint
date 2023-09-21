/********************************************************************************
** Form generated from reading UI file 'dialog_2.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_2_H
#define UI_DIALOG_2_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTableWidget>

QT_BEGIN_NAMESPACE

class Ui_Dialog_2
{
public:
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QTableWidget *tableWidget;
    QSpinBox *spinBox;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;

    void setupUi(QDialog *Dialog_2)
    {
        if (Dialog_2->objectName().isEmpty())
            Dialog_2->setObjectName(QString::fromUtf8("Dialog_2"));
        Dialog_2->resize(369, 442);
        pushButton = new QPushButton(Dialog_2);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(180, 390, 75, 23));
        pushButton_2 = new QPushButton(Dialog_2);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(270, 390, 75, 23));
        tableWidget = new QTableWidget(Dialog_2);
        if (tableWidget->columnCount() < 2)
            tableWidget->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        tableWidget->setGeometry(QRect(10, 70, 217, 291));
        tableWidget->setRowCount(0);
        tableWidget->setColumnCount(2);
        spinBox = new QSpinBox(Dialog_2);
        spinBox->setObjectName(QString::fromUtf8("spinBox"));
        spinBox->setGeometry(QRect(270, 140, 61, 21));
        label = new QLabel(Dialog_2);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(250, 110, 111, 20));
        QFont font;
        font.setPointSize(10);
        label->setFont(font);
        label_2 = new QLabel(Dialog_2);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(20, 39, 201, 31));
        QFont font1;
        font1.setPointSize(11);
        label_2->setFont(font1);
        label_3 = new QLabel(Dialog_2);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(10, 10, 341, 20));
        QWidget::setTabOrder(spinBox, tableWidget);
        QWidget::setTabOrder(tableWidget, pushButton);
        QWidget::setTabOrder(pushButton, pushButton_2);

        retranslateUi(Dialog_2);

        QMetaObject::connectSlotsByName(Dialog_2);
    } // setupUi

    void retranslateUi(QDialog *Dialog_2)
    {
        Dialog_2->setWindowTitle(QApplication::translate("Dialog_2", "Dialog", nullptr));
        pushButton->setText(QApplication::translate("Dialog_2", "Ok", nullptr));
        pushButton_2->setText(QApplication::translate("Dialog_2", "Cancel", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("Dialog_2", "X", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("Dialog_2", "Y", nullptr));
        label->setText(QApplication::translate("Dialog_2", "\320\232\320\276\320\273\320\270\321\207\320\265\321\201\321\202\320\262\320\276 \321\202\320\276\321\207\320\265\320\272", nullptr));
        label_2->setText(QApplication::translate("Dialog_2", "\320\230\320\275\321\201\321\202\321\200\321\203\320\274\320\265\320\275\321\202 ", nullptr));
        label_3->setText(QApplication::translate("Dialog_2", "<html><head/><body><p align=\"center\">\320\236\320\263\321\200\320\260\320\275\320\270\321\207\320\265\320\275\320\270\320\265 \320\275\320\260 \320\262\320\262\320\276\320\264 \320\272\320\276\320\276\321\200\320\264\320\270\320\275\320\260\321\202:0&lt;=X&lt;=900,0&lt;=Y&lt;=350</p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Dialog_2: public Ui_Dialog_2 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_2_H
