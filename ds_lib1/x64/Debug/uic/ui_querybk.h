/********************************************************************************
** Form generated from reading UI file 'querybk.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QUERYBK_H
#define UI_QUERYBK_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_querybk
{
public:
    QPushButton *btn4_starorder;
    QPushButton *btn3_intereorder;
    QLabel *label_4;
    QLineEdit *lineEdit;
    QPushButton *btn5_timeorder;
    QLabel *label;
    QLabel *label_3;
    QLineEdit *lineEdit_2;
    QLineEdit *lineEdit_4;
    QPushButton *btnt2_preciseq;
    QLabel *label_2;
    QLineEdit *lineEdit_3;
    QPushButton *btn1_vagueq;
    QTableWidget *tableWidget;
    QPushButton *btn6_defalt;

    void setupUi(QWidget *querybk)
    {
        if (querybk->objectName().isEmpty())
            querybk->setObjectName(QString::fromUtf8("querybk"));
        querybk->resize(1211, 700);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(querybk->sizePolicy().hasHeightForWidth());
        querybk->setSizePolicy(sizePolicy);
        btn4_starorder = new QPushButton(querybk);
        btn4_starorder->setObjectName(QString::fromUtf8("btn4_starorder"));
        btn4_starorder->setGeometry(QRect(370, 650, 201, 41));
        btn3_intereorder = new QPushButton(querybk);
        btn3_intereorder->setObjectName(QString::fromUtf8("btn3_intereorder"));
        btn3_intereorder->setGeometry(QRect(60, 650, 221, 41));
        label_4 = new QLabel(querybk);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(40, 140, 131, 41));
        lineEdit = new QLineEdit(querybk);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(90, 20, 161, 31));
        btn5_timeorder = new QPushButton(querybk);
        btn5_timeorder->setObjectName(QString::fromUtf8("btn5_timeorder"));
        btn5_timeorder->setGeometry(QRect(660, 650, 201, 41));
        label = new QLabel(querybk);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(40, 20, 71, 31));
        label_3 = new QLabel(querybk);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(40, 60, 71, 41));
        lineEdit_2 = new QLineEdit(querybk);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(360, 20, 161, 31));
        lineEdit_4 = new QLineEdit(querybk);
        lineEdit_4->setObjectName(QString::fromUtf8("lineEdit_4"));
        lineEdit_4->setGeometry(QRect(130, 150, 161, 31));
        btnt2_preciseq = new QPushButton(querybk);
        btnt2_preciseq->setObjectName(QString::fromUtf8("btnt2_preciseq"));
        btnt2_preciseq->setGeometry(QRect(320, 150, 121, 31));
        label_2 = new QLabel(querybk);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(290, 20, 91, 31));
        lineEdit_3 = new QLineEdit(querybk);
        lineEdit_3->setObjectName(QString::fromUtf8("lineEdit_3"));
        lineEdit_3->setGeometry(QRect(90, 70, 161, 31));
        btn1_vagueq = new QPushButton(querybk);
        btn1_vagueq->setObjectName(QString::fromUtf8("btn1_vagueq"));
        btn1_vagueq->setGeometry(QRect(550, 20, 121, 31));
        tableWidget = new QTableWidget(querybk);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        tableWidget->setGeometry(QRect(10, 201, 1191, 441));
        tableWidget->horizontalHeader()->setCascadingSectionResizes(true);
        tableWidget->verticalHeader()->setCascadingSectionResizes(true);
        btn6_defalt = new QPushButton(querybk);
        btn6_defalt->setObjectName(QString::fromUtf8("btn6_defalt"));
        btn6_defalt->setGeometry(QRect(950, 650, 201, 41));

        retranslateUi(querybk);
        QObject::connect(btn4_starorder, SIGNAL(clicked()), querybk, SLOT(ScoreRank()));
        QObject::connect(btn3_intereorder, SIGNAL(clicked()), querybk, SLOT(TimesRank()));
        QObject::connect(btn5_timeorder, SIGNAL(clicked()), querybk, SLOT(DateRank()));
        QObject::connect(btn6_defalt, SIGNAL(clicked()), querybk, SLOT(DefaltRank()));
        QObject::connect(btn1_vagueq, SIGNAL(clicked()), querybk, SLOT(VagueQ()));
        QObject::connect(btnt2_preciseq, SIGNAL(clicked()), querybk, SLOT(PreciseQ()));

        QMetaObject::connectSlotsByName(querybk);
    } // setupUi

    void retranslateUi(QWidget *querybk)
    {
        querybk->setWindowTitle(QCoreApplication::translate("querybk", "querybk", nullptr));
        btn4_starorder->setText(QCoreApplication::translate("querybk", "\346\214\211\344\271\246\350\257\204\345\272\246\346\216\222\345\272\217", nullptr));
        btn3_intereorder->setText(QCoreApplication::translate("querybk", "\346\214\211\350\257\273\350\200\205\345\205\264\350\266\243\345\272\246\346\216\222\345\272\217", nullptr));
        label_4->setText(QCoreApplication::translate("querybk", "\344\271\246\347\261\215ISBN:", nullptr));
        btn5_timeorder->setText(QCoreApplication::translate("querybk", "\346\214\211\345\207\272\347\211\210\346\227\266\351\227\264\346\216\222\345\272\217", nullptr));
        label->setText(QCoreApplication::translate("querybk", "\344\271\246\345\220\215\357\274\232", nullptr));
        label_3->setText(QCoreApplication::translate("querybk", "\344\275\234\350\200\205\357\274\232", nullptr));
        btnt2_preciseq->setText(QCoreApplication::translate("querybk", "\347\262\276\347\241\256\346\237\245\350\257\242", nullptr));
        label_2->setText(QCoreApplication::translate("querybk", "\345\207\272\347\211\210\347\244\276\357\274\232", nullptr));
        btn1_vagueq->setText(QCoreApplication::translate("querybk", "\346\250\241\347\263\212\346\237\245\350\257\242", nullptr));
        btn6_defalt->setText(QCoreApplication::translate("querybk", "\346\214\211\347\274\226\345\217\267\346\216\222\345\272\217", nullptr));
    } // retranslateUi

};

namespace Ui {
    class querybk: public Ui_querybk {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QUERYBK_H
