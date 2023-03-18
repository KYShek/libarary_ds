/********************************************************************************
** Form generated from reading UI file 'returnbk.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RETURNBK_H
#define UI_RETURNBK_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_returnbkClass
{
public:
    QLabel *title;
    QLabel *label_2;
    QLineEdit *lineEdit;
    QPushButton *btn_returnbk;

    void setupUi(QWidget *returnbkClass)
    {
        if (returnbkClass->objectName().isEmpty())
            returnbkClass->setObjectName(QString::fromUtf8("returnbkClass"));
        returnbkClass->resize(305, 231);
        title = new QLabel(returnbkClass);
        title->setObjectName(QString::fromUtf8("title"));
        title->setGeometry(QRect(100, 30, 100, 40));
        title->setMinimumSize(QSize(100, 40));
        title->setMaximumSize(QSize(100, 40));
        QFont font;
        font.setFamily(QString::fromUtf8("\346\245\267\344\275\223"));
        font.setPointSize(16);
        title->setFont(font);
        label_2 = new QLabel(returnbkClass);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(20, 90, 70, 40));
        label_2->setMinimumSize(QSize(70, 40));
        label_2->setMaximumSize(QSize(70, 40));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\346\245\267\344\275\223"));
        font1.setPointSize(14);
        label_2->setFont(font1);
        lineEdit = new QLineEdit(returnbkClass);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(70, 90, 200, 35));
        lineEdit->setMinimumSize(QSize(200, 35));
        lineEdit->setMaximumSize(QSize(200, 35));
        btn_returnbk = new QPushButton(returnbkClass);
        btn_returnbk->setObjectName(QString::fromUtf8("btn_returnbk"));
        btn_returnbk->setGeometry(QRect(100, 170, 100, 35));
        btn_returnbk->setMinimumSize(QSize(100, 35));
        btn_returnbk->setMaximumSize(QSize(100, 35));
        btn_returnbk->setFont(font1);

        retranslateUi(returnbkClass);
        QObject::connect(btn_returnbk, SIGNAL(clicked()), returnbkClass, SLOT(ReturnBook()));

        QMetaObject::connectSlotsByName(returnbkClass);
    } // setupUi

    void retranslateUi(QWidget *returnbkClass)
    {
        returnbkClass->setWindowTitle(QCoreApplication::translate("returnbkClass", "returnbk", nullptr));
        title->setText(QCoreApplication::translate("returnbkClass", "<html><head/><body><p align=\"center\">\345\275\222\350\277\230</p></body></html>", nullptr));
        label_2->setText(QCoreApplication::translate("returnbkClass", "<html><head/><body><p align=\"center\">id\357\274\232</p></body></html>", nullptr));
        btn_returnbk->setText(QCoreApplication::translate("returnbkClass", "\345\275\222\350\277\230", nullptr));
    } // retranslateUi

};

namespace Ui {
    class returnbkClass: public Ui_returnbkClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RETURNBK_H
