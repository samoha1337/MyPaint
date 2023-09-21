/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>
#include <my_widget.h>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionSha256;
    QWidget *centralWidget;
    my_widget *widget;
    QSpinBox *spinBox;
    QTableWidget *tableWidget;
    QLabel *label;
    QPushButton *pushButton_save;
    QPushButton *pushButton_open;
    QLabel *label_text;
    QLabel *label_text_2;
    QMenuBar *menuBar;
    QMenu *menu;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(942, 738);
        QFont font;
        font.setPointSize(8);
        MainWindow->setFont(font);
        actionSha256 = new QAction(MainWindow);
        actionSha256->setObjectName(QString::fromUtf8("actionSha256"));
        QIcon icon;
        icon.addFile(QString::fromUtf8("../../Users/tonak/algorithm.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionSha256->setIcon(icon);
        QFont font1;
        font1.setPointSize(12);
        actionSha256->setFont(font1);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        widget = new my_widget(centralWidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(10, 459, 900, 200));
        spinBox = new QSpinBox(centralWidget);
        spinBox->setObjectName(QString::fromUtf8("spinBox"));
        spinBox->setGeometry(QRect(230, 20, 42, 22));
        tableWidget = new QTableWidget(centralWidget);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        tableWidget->setGeometry(QRect(10, 160, 901, 281));
        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(20, 15, 201, 31));
        pushButton_save = new QPushButton(centralWidget);
        pushButton_save->setObjectName(QString::fromUtf8("pushButton_save"));
        pushButton_save->setGeometry(QRect(310, 20, 75, 23));
        pushButton_open = new QPushButton(centralWidget);
        pushButton_open->setObjectName(QString::fromUtf8("pushButton_open"));
        pushButton_open->setGeometry(QRect(400, 20, 75, 23));
        label_text = new QLabel(centralWidget);
        label_text->setObjectName(QString::fromUtf8("label_text"));
        label_text->setGeometry(QRect(10, 70, 931, 71));
        label_text_2 = new QLabel(centralWidget);
        label_text_2->setObjectName(QString::fromUtf8("label_text_2"));
        label_text_2->setGeometry(QRect(490, 8, 361, 71));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 942, 27));
        menuBar->setFont(font1);
        menu = new QMenu(menuBar);
        menu->setObjectName(QString::fromUtf8("menu"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menu->menuAction());
        menu->addAction(actionSha256);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        actionSha256->setText(QApplication::translate("MainWindow", "Sha256-\320\220\320\273\320\263\320\276\321\200\320\270\321\202\320\274", nullptr));
        label->setText(QApplication::translate("MainWindow", "\320\232\320\276\320\273\320\270\321\207\320\265\321\201\321\202\320\262\320\276 \320\276\320\261\321\212\320\265\320\272\321\202\320\276\320\262 \320\264\320\273\321\217 \320\276\321\202\321\200\320\270\321\201\320\276\320\262\320\272\320\270:", nullptr));
        pushButton_save->setText(QApplication::translate("MainWindow", "\320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214", nullptr));
        pushButton_open->setText(QApplication::translate("MainWindow", "\320\236\321\202\320\272\321\200\321\213\321\202\321\214", nullptr));
        label_text->setText(QApplication::translate("MainWindow", "<html><head/><body><p align=\"center\">\320\222\320\270\320\264\320\266\320\265\321\202 \321\200\320\260\320\267\320\274\320\265\321\200\320\276\320\274 (900,200), \320\276\320\263\321\200\320\260\320\275\320\270\321\207\320\265\320\275\320\270\320\265 \320\275\320\260 \320\262\320\262\320\276\320\264 \320\264\320\260\320\275\320\275\321\213\321\205:\321\206\320\265\320\273\321\213\320\265 \321\207\320\270\321\201\320\273\320\260 \320\276\321\202 -1000 \320\264\320\276 1000.</p><p align=\"center\">\320\225\321\201\320\273\320\270 \321\207\320\270\321\201\320\273\320\276 \320\262\321\213\321\205\320\276\320\264\320\270\321\202 \320\267\320\260 \320\264\320\270\320\260\320\277\320\276\320\267\320\276\320\275, \321\202\320\276 \320\277\321\200\320\270\320\275\320\270\320\274\320\260\320\265\321\202\321\201\321\217 \320\261\320\273\320\270\320\266\320\260\320\271\321\210\320\265\320\265 \320\272\321\200\320\260\320\271\320\275\320\265\320\265 \320\267\320\275\320\260\321\207\320\265\320\275\320\270\320\265, \320\265"
                        "\321\201\320\273\320\270 \321\207\320\270\321\201\320\273\320\276 \320\275\320\265 \321\217\320\262\320\273\321\217\320\265\321\202\321\201\321\217 \321\206\320\265\320\273\321\213\320\274, \321\202\320\276 \320\267\320\275\320\260\321\207\320\265\320\275\320\270\320\265 \321\201\321\202\320\260\320\275\320\276\320\262\320\270\321\202\321\201\321\217 \321\200\320\260\320\262\320\275\321\213\320\274 0</p><p align=\"center\">\320\243\320\263\320\273\321\213 \320\224\321\203\320\263\320\270 \320\275\320\265 \320\274\320\276\320\263\321\203\321\202 \320\261\321\213\321\202\321\214 \320\276\321\202\321\200\320\270\321\206\320\260\321\202\320\265\320\273\321\214\320\275\321\213\320\274\320\270</p></body></html>", nullptr));
        label_text_2->setText(QApplication::translate("MainWindow", "<html><head/><body><p align=\"center\">\320\243\320\273\321\203\321\207\321\210\320\265\320\275\320\275\320\260\321\217 \320\267\320\260\321\211\320\270\321\202\320\260: \320\277\321\200\320\276\320\262\320\265\321\200\320\272\320\260 \320\272\320\276\320\275\321\202\321\200\320\276\320\273\321\214\320\275\320\276\320\271 \321\201\321\203\320\274\320\274\321\213</p><p align=\"center\">:0</p></body></html>", nullptr));
        menu->setTitle(QApplication::translate("MainWindow", "\320\230\320\275\321\204\320\276\321\200\320\274\320\260\321\206\320\270\321\217", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
