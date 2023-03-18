/********************************************************************************
** Form generated from reading UI file 'reader_information.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_READER_INFORMATION_H
#define UI_READER_INFORMATION_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_reader_information
{
public:
    QGroupBox *groupBox;
    QLabel *label_account;
    QLabel *label_14;
    QLabel *label_name;
    QLabel *label_16;
    QLabel *label_acvalue;
    QLabel *label_nvalue;
    QPushButton *btn2_rebrw;
    QPushButton *btn1_brwbk;
    QPushButton *btn3_quitlogin;
    QTableWidget *tableWidget;

    void setupUi(QWidget *reader_information)
    {
        if (reader_information->objectName().isEmpty())
            reader_information->setObjectName(QString::fromUtf8("reader_information"));
        reader_information->resize(931, 400);
        groupBox = new QGroupBox(reader_information);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(10, 10, 911, 101));
        label_account = new QLabel(groupBox);
        label_account->setObjectName(QString::fromUtf8("label_account"));
        label_account->setGeometry(QRect(10, 10, 60, 16));
        label_14 = new QLabel(groupBox);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        label_14->setGeometry(QRect(10, 70, 281, 16));
        label_name = new QLabel(groupBox);
        label_name->setObjectName(QString::fromUtf8("label_name"));
        label_name->setGeometry(QRect(10, 40, 60, 16));
        label_16 = new QLabel(groupBox);
        label_16->setObjectName(QString::fromUtf8("label_16"));
        label_16->setGeometry(QRect(830, 10, 71, 20));
        label_acvalue = new QLabel(groupBox);
        label_acvalue->setObjectName(QString::fromUtf8("label_acvalue"));
        label_acvalue->setGeometry(QRect(60, 10, 81, 18));
        label_nvalue = new QLabel(groupBox);
        label_nvalue->setObjectName(QString::fromUtf8("label_nvalue"));
        label_nvalue->setGeometry(QRect(60, 40, 81, 18));
        btn2_rebrw = new QPushButton(reader_information);
        btn2_rebrw->setObjectName(QString::fromUtf8("btn2_rebrw"));
        btn2_rebrw->setGeometry(QRect(410, 340, 113, 32));
        btn1_brwbk = new QPushButton(reader_information);
        btn1_brwbk->setObjectName(QString::fromUtf8("btn1_brwbk"));
        btn1_brwbk->setGeometry(QRect(140, 340, 113, 32));
        btn3_quitlogin = new QPushButton(reader_information);
        btn3_quitlogin->setObjectName(QString::fromUtf8("btn3_quitlogin"));
        btn3_quitlogin->setGeometry(QRect(670, 340, 113, 32));
        tableWidget = new QTableWidget(reader_information);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        tableWidget->setGeometry(QRect(10, 120, 911, 192));
        tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tableWidget->setSelectionMode(QAbstractItemView::SingleSelection);
        tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);

        retranslateUi(reader_information);
        QObject::connect(btn1_brwbk, SIGNAL(clicked()), reader_information, SLOT(BorrowbkButton()));
        QObject::connect(btn2_rebrw, SIGNAL(clicked()), reader_information, SLOT(ReborrowbkButton()));
        QObject::connect(btn3_quitlogin, SIGNAL(clicked()), reader_information, SLOT(QuitloginButton()));
        QObject::connect(reader_information, SIGNAL(SendCurrentRow(int)), reader_information, SLOT(RowSelected(int)));
        QObject::connect(tableWidget, SIGNAL(cellClicked(int,int)), reader_information, SLOT(TableClicked(int,int)));

        QMetaObject::connectSlotsByName(reader_information);
    } // setupUi

    void retranslateUi(QWidget *reader_information)
    {
        reader_information->setWindowTitle(QCoreApplication::translate("reader_information", "reader_information", nullptr));
        groupBox->setTitle(QString());
        label_account->setText(QCoreApplication::translate("reader_information", "\350\264\246\345\217\267\357\274\232", nullptr));
        label_14->setText(QCoreApplication::translate("reader_information", "\346\235\203\351\231\220\357\274\232\350\257\273\350\200\205", nullptr));
        label_name->setText(QCoreApplication::translate("reader_information", "\345\247\223\345\220\215\357\274\232", nullptr));
        label_16->setText(QCoreApplication::translate("reader_information", "\344\270\252\344\272\272\344\277\241\346\201\257", nullptr));
        label_acvalue->setText(QCoreApplication::translate("reader_information", "TextLabel", nullptr));
        label_nvalue->setText(QCoreApplication::translate("reader_information", "TextLabel", nullptr));
        btn2_rebrw->setText(QCoreApplication::translate("reader_information", "\347\273\255\345\200\237", nullptr));
        btn1_brwbk->setText(QCoreApplication::translate("reader_information", "\345\200\237\351\230\205", nullptr));
        btn3_quitlogin->setText(QCoreApplication::translate("reader_information", "\351\200\200\345\207\272\347\231\273\345\275\225", nullptr));
    } // retranslateUi

};

namespace Ui {
    class reader_information: public Ui_reader_information {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_READER_INFORMATION_H
