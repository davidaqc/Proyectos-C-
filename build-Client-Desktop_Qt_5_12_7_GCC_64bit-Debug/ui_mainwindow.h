/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.7
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
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionSalir;
    QAction *actionVentana_1;
    QWidget *centralwidget;
    QLabel *label;
    QLineEdit *lineEdit;
    QLabel *label_2;
    QPushButton *aceptar;
    QLabel *label_3;
    QLineEdit *lineEdit_2;
    QPushButton *aceptar_nodo;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLineEdit *lineEdit_3;
    QLineEdit *lineEdit_4;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton;
    QTableWidget *tableWidget;
    QPushButton *pushButton_4;
    QMenuBar *menubar;
    QMenu *menuArchivo;
    QMenu *menuEdiciones;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->setEnabled(true);
        MainWindow->resize(700, 500);
        actionSalir = new QAction(MainWindow);
        actionSalir->setObjectName(QString::fromUtf8("actionSalir"));
        actionVentana_1 = new QAction(MainWindow);
        actionVentana_1->setObjectName(QString::fromUtf8("actionVentana_1"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(20, 10, 321, 181));
        lineEdit = new QLineEdit(centralwidget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(190, 190, 41, 25));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(20, 190, 161, 17));
        aceptar = new QPushButton(centralwidget);
        aceptar->setObjectName(QString::fromUtf8("aceptar"));
        aceptar->setGeometry(QRect(250, 190, 89, 25));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(20, 250, 151, 17));
        lineEdit_2 = new QLineEdit(centralwidget);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(190, 250, 71, 25));
        aceptar_nodo = new QPushButton(centralwidget);
        aceptar_nodo->setObjectName(QString::fromUtf8("aceptar_nodo"));
        aceptar_nodo->setEnabled(false);
        aceptar_nodo->setGeometry(QRect(280, 250, 101, 25));
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(20, 300, 161, 17));
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(70, 330, 91, 16));
        label_6 = new QLabel(centralwidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(70, 350, 81, 17));
        lineEdit_3 = new QLineEdit(centralwidget);
        lineEdit_3->setObjectName(QString::fromUtf8("lineEdit_3"));
        lineEdit_3->setGeometry(QRect(160, 320, 71, 25));
        lineEdit_4 = new QLineEdit(centralwidget);
        lineEdit_4->setObjectName(QString::fromUtf8("lineEdit_4"));
        lineEdit_4->setGeometry(QRect(160, 350, 71, 25));
        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setEnabled(false);
        pushButton_2->setGeometry(QRect(250, 330, 111, 25));
        pushButton_3 = new QPushButton(centralwidget);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setEnabled(false);
        pushButton_3->setGeometry(QRect(280, 280, 101, 25));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setEnabled(false);
        pushButton->setGeometry(QRect(250, 370, 111, 25));
        tableWidget = new QTableWidget(centralwidget);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        tableWidget->setGeometry(QRect(430, 30, 256, 341));
        pushButton_4 = new QPushButton(centralwidget);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        pushButton_4->setGeometry(QRect(440, 390, 101, 25));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 700, 22));
        menuArchivo = new QMenu(menubar);
        menuArchivo->setObjectName(QString::fromUtf8("menuArchivo"));
        menuEdiciones = new QMenu(menubar);
        menuEdiciones->setObjectName(QString::fromUtf8("menuEdiciones"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menuArchivo->menuAction());
        menubar->addAction(menuEdiciones->menuAction());
        menuArchivo->addAction(actionSalir);
        menuEdiciones->addAction(actionVentana_1);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Grafos", nullptr));
        actionSalir->setText(QApplication::translate("MainWindow", "Salir", nullptr));
        actionVentana_1->setText(QApplication::translate("MainWindow", "Ventana 1", nullptr));
        label->setText(QApplication::translate("MainWindow", "        REPRESENTACION DE GRAFOS DIRIGIDOS\n"
"\n"
" 1. INSERTAR UN NODO                 \n"
" 2. INSERTAR UNA ARISTA              \n"
" 3. ELIMINAR UN NODO                 \n"
" 4. ELIMINAR UNA ARISTA .", nullptr));
        label_2->setText(QApplication::translate("MainWindow", "INGRESE UNA OPCION:", nullptr));
        aceptar->setText(QApplication::translate("MainWindow", "Aceptar", nullptr));
        label_3->setText(QApplication::translate("MainWindow", "Insertar/eliminar nodo", nullptr));
        aceptar_nodo->setText(QApplication::translate("MainWindow", "Aceptar nodo", nullptr));
        label_4->setText(QApplication::translate("MainWindow", "Insertar/eliminar arista", nullptr));
        label_5->setText(QApplication::translate("MainWindow", "Nodo inicial:", nullptr));
        label_6->setText(QApplication::translate("MainWindow", "Nodo final:", nullptr));
        pushButton_2->setText(QApplication::translate("MainWindow", "Aceptar arista", nullptr));
        pushButton_3->setText(QApplication::translate("MainWindow", "Eliminar nodo", nullptr));
        pushButton->setText(QApplication::translate("MainWindow", "Eliminar arista", nullptr));
        pushButton_4->setText(QApplication::translate("MainWindow", "Mostrar grafo", nullptr));
        menuArchivo->setTitle(QApplication::translate("MainWindow", "Archivo", nullptr));
        menuEdiciones->setTitle(QApplication::translate("MainWindow", "Ediciones", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
