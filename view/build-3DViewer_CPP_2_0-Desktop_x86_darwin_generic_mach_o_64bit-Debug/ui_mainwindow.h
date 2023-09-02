/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.2.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>
#include "render.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    Render *gl_visual;
    QPushButton *render_button;
    QDoubleSpinBox *double_spin_box_scale;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1192, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gl_visual = new Render(centralwidget);
        gl_visual->setObjectName(QString::fromUtf8("gl_visual"));
        gl_visual->setGeometry(QRect(170, 100, 801, 431));
        render_button = new QPushButton(centralwidget);
        render_button->setObjectName(QString::fromUtf8("render_button"));
        render_button->setGeometry(QRect(510, 20, 111, 51));
        double_spin_box_scale = new QDoubleSpinBox(centralwidget);
        double_spin_box_scale->setObjectName(QString::fromUtf8("double_spin_box_scale"));
        double_spin_box_scale->setGeometry(QRect(20, 180, 121, 21));
        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        render_button->setText(QCoreApplication::translate("MainWindow", "Render", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
