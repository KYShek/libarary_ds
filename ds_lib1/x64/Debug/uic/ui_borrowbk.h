/********************************************************************************
** Form generated from reading UI file 'borrowbk.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BORROWBK_H
#define UI_BORROWBK_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_borrowbk
{
public:
    QPushButton *checkbrw_btn;
    QGroupBox *groupBox;
    QLabel *label;
    QLineEdit *lineEdit_BrId;

    void setupUi(QWidget *borrowbk)
    {
        if (borrowbk->objectName().isEmpty())
            borrowbk->setObjectName(QString::fromUtf8("borrowbk"));
        borrowbk->resize(401, 140);
        checkbrw_btn = new QPushButton(borrowbk);
        checkbrw_btn->setObjectName(QString::fromUtf8("checkbrw_btn"));
        checkbrw_btn->setGeometry(QRect(150, 90, 113, 32));
        groupBox = new QGroupBox(borrowbk);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(10, 10, 381, 71));
        QFont font;
        font.setPointSize(10);
        groupBox->setFont(font);
        groupBox->setFlat(false);
        groupBox->setCheckable(false);
        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 30, 131, 16));
        lineEdit_BrId = new QLineEdit(groupBox);
        lineEdit_BrId->setObjectName(QString::fromUtf8("lineEdit_BrId"));
        lineEdit_BrId->setGeometry(QRect(140, 30, 221, 21));

        retranslateUi(borrowbk);
        QObject::connect(checkbrw_btn, SIGNAL(clicked()), borrowbk, SLOT(BorrowClicked()));

        QMetaObject::connectSlotsByName(borrowbk);
    } // setupUi

    void retranslateUi(QWidget *borrowbk)
    {
        borrowbk->setWindowTitle(QCoreApplication::translate("borrowbk", "borrowbk", nullptr));
        checkbrw_btn->setText(QCoreApplication::translate("borrowbk", "\347\241\256\350\256\244\345\200\237\351\230\205", nullptr));
        groupBox->setTitle(QCoreApplication::translate("borrowbk", "\345\200\237\351\230\205", nullptr));
        label->setText(QCoreApplication::translate("borrowbk", "\350\257\267\350\276\223\345\205\245\344\271\246\347\261\215 id\357\274\232", nullptr));
    } // retranslateUi

};

namespace Ui {
    class borrowbk: public Ui_borrowbk {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BORROWBK_H
