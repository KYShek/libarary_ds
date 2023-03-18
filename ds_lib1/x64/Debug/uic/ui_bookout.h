/********************************************************************************
** Form generated from reading UI file 'bookout.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BOOKOUT_H
#define UI_BOOKOUT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_bookout
{
public:
    QPushButton *But_BookOut;
    QLineEdit *lineEdit_ID;
    QLabel *label_ID;

    void setupUi(QWidget *bookout)
    {
        if (bookout->objectName().isEmpty())
            bookout->setObjectName(QString::fromUtf8("bookout"));
        bookout->resize(231, 132);
        But_BookOut = new QPushButton(bookout);
        But_BookOut->setObjectName(QString::fromUtf8("But_BookOut"));
        But_BookOut->setGeometry(QRect(80, 80, 71, 31));
        lineEdit_ID = new QLineEdit(bookout);
        lineEdit_ID->setObjectName(QString::fromUtf8("lineEdit_ID"));
        lineEdit_ID->setGeometry(QRect(50, 40, 151, 22));
        label_ID = new QLabel(bookout);
        label_ID->setObjectName(QString::fromUtf8("label_ID"));
        label_ID->setGeometry(QRect(26, 40, 18, 16));

        retranslateUi(bookout);
        QObject::connect(But_BookOut, SIGNAL(clicked()), bookout, SLOT(BookOut()));

        QMetaObject::connectSlotsByName(bookout);
    } // setupUi

    void retranslateUi(QWidget *bookout)
    {
        bookout->setWindowTitle(QCoreApplication::translate("bookout", "bookout", nullptr));
        But_BookOut->setText(QCoreApplication::translate("bookout", "\345\207\272\345\272\223", nullptr));
        label_ID->setText(QCoreApplication::translate("bookout", "ID:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class bookout: public Ui_bookout {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BOOKOUT_H
