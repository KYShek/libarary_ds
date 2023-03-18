/********************************************************************************
** Form generated from reading UI file 'bkstock.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BKSTOCK_H
#define UI_BKSTOCK_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_bkstock
{
public:
    QPushButton *btn2_bkin;
    QPushButton *btn3_bkout;
    QPushButton *btn4_quit;
    QTableWidget *tableWidget;

    void setupUi(QWidget *bkstock)
    {
        if (bkstock->objectName().isEmpty())
            bkstock->setObjectName(QString::fromUtf8("bkstock"));
        bkstock->resize(1222, 400);
        btn2_bkin = new QPushButton(bkstock);
        btn2_bkin->setObjectName(QString::fromUtf8("btn2_bkin"));
        btn2_bkin->setGeometry(QRect(40, 360, 99, 28));
        btn3_bkout = new QPushButton(bkstock);
        btn3_bkout->setObjectName(QString::fromUtf8("btn3_bkout"));
        btn3_bkout->setGeometry(QRect(550, 360, 99, 28));
        btn4_quit = new QPushButton(bkstock);
        btn4_quit->setObjectName(QString::fromUtf8("btn4_quit"));
        btn4_quit->setGeometry(QRect(1080, 360, 99, 28));
        tableWidget = new QTableWidget(bkstock);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        tableWidget->setGeometry(QRect(10, 10, 1201, 341));

        retranslateUi(bkstock);
        QObject::connect(btn2_bkin, SIGNAL(clicked()), bkstock, SLOT(BkinButton()));
        QObject::connect(btn3_bkout, SIGNAL(clicked()), bkstock, SLOT(BkoutButton()));
        QObject::connect(btn4_quit, SIGNAL(clicked()), bkstock, SLOT(QuitloginButton()));

        QMetaObject::connectSlotsByName(bkstock);
    } // setupUi

    void retranslateUi(QWidget *bkstock)
    {
        bkstock->setWindowTitle(QCoreApplication::translate("bkstock", "bkstock", nullptr));
        btn2_bkin->setText(QCoreApplication::translate("bkstock", "\344\271\246\347\261\215\345\205\245\345\272\223", nullptr));
        btn3_bkout->setText(QCoreApplication::translate("bkstock", "\344\271\246\347\261\215\345\207\272\345\272\223", nullptr));
        btn4_quit->setText(QCoreApplication::translate("bkstock", "\351\200\200\345\207\272\347\231\273\345\275\225", nullptr));
    } // retranslateUi

};

namespace Ui {
    class bkstock: public Ui_bkstock {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BKSTOCK_H
