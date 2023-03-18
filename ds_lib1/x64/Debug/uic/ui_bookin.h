/********************************************************************************
** Form generated from reading UI file 'bookin.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BOOKIN_H
#define UI_BOOKIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_bookin
{
public:
    QPushButton *But_BookIn;
    QWidget *layoutWidget;
    QFormLayout *formLayout;
    QLabel *label_ID;
    QLabel *label_ISBN;
    QLineEdit *lineEdit_ID;
    QLineEdit *lineEdit_ISBN;
    QLabel *label_name;
    QLineEdit *lineEdit_name;
    QLabel *label_author;
    QLineEdit *lineEdit_author;
    QLabel *label_publisher;
    QLineEdit *lineEdit_publisher;
    QLabel *label_pubdate;
    QLineEdit *lineEdit_pubdate;
    QLabel *label_score;
    QLineEdit *lineEdit_score;

    void setupUi(QWidget *bookin)
    {
        if (bookin->objectName().isEmpty())
            bookin->setObjectName(QString::fromUtf8("bookin"));
        bookin->resize(286, 281);
        But_BookIn = new QPushButton(bookin);
        But_BookIn->setObjectName(QString::fromUtf8("But_BookIn"));
        But_BookIn->setGeometry(QRect(110, 240, 80, 31));
        layoutWidget = new QWidget(bookin);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(20, 19, 251, 213));
        formLayout = new QFormLayout(layoutWidget);
        formLayout->setSpacing(6);
        formLayout->setContentsMargins(11, 11, 11, 11);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        formLayout->setContentsMargins(0, 0, 0, 0);
        label_ID = new QLabel(layoutWidget);
        label_ID->setObjectName(QString::fromUtf8("label_ID"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label_ID);

        label_ISBN = new QLabel(layoutWidget);
        label_ISBN->setObjectName(QString::fromUtf8("label_ISBN"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_ISBN);

        lineEdit_ID = new QLineEdit(layoutWidget);
        lineEdit_ID->setObjectName(QString::fromUtf8("lineEdit_ID"));

        formLayout->setWidget(0, QFormLayout::FieldRole, lineEdit_ID);

        lineEdit_ISBN = new QLineEdit(layoutWidget);
        lineEdit_ISBN->setObjectName(QString::fromUtf8("lineEdit_ISBN"));

        formLayout->setWidget(1, QFormLayout::FieldRole, lineEdit_ISBN);

        label_name = new QLabel(layoutWidget);
        label_name->setObjectName(QString::fromUtf8("label_name"));

        formLayout->setWidget(2, QFormLayout::LabelRole, label_name);

        lineEdit_name = new QLineEdit(layoutWidget);
        lineEdit_name->setObjectName(QString::fromUtf8("lineEdit_name"));

        formLayout->setWidget(2, QFormLayout::FieldRole, lineEdit_name);

        label_author = new QLabel(layoutWidget);
        label_author->setObjectName(QString::fromUtf8("label_author"));

        formLayout->setWidget(3, QFormLayout::LabelRole, label_author);

        lineEdit_author = new QLineEdit(layoutWidget);
        lineEdit_author->setObjectName(QString::fromUtf8("lineEdit_author"));

        formLayout->setWidget(3, QFormLayout::FieldRole, lineEdit_author);

        label_publisher = new QLabel(layoutWidget);
        label_publisher->setObjectName(QString::fromUtf8("label_publisher"));

        formLayout->setWidget(4, QFormLayout::LabelRole, label_publisher);

        lineEdit_publisher = new QLineEdit(layoutWidget);
        lineEdit_publisher->setObjectName(QString::fromUtf8("lineEdit_publisher"));

        formLayout->setWidget(4, QFormLayout::FieldRole, lineEdit_publisher);

        label_pubdate = new QLabel(layoutWidget);
        label_pubdate->setObjectName(QString::fromUtf8("label_pubdate"));

        formLayout->setWidget(5, QFormLayout::LabelRole, label_pubdate);

        lineEdit_pubdate = new QLineEdit(layoutWidget);
        lineEdit_pubdate->setObjectName(QString::fromUtf8("lineEdit_pubdate"));

        formLayout->setWidget(5, QFormLayout::FieldRole, lineEdit_pubdate);

        label_score = new QLabel(layoutWidget);
        label_score->setObjectName(QString::fromUtf8("label_score"));

        formLayout->setWidget(6, QFormLayout::LabelRole, label_score);

        lineEdit_score = new QLineEdit(layoutWidget);
        lineEdit_score->setObjectName(QString::fromUtf8("lineEdit_score"));

        formLayout->setWidget(6, QFormLayout::FieldRole, lineEdit_score);


        retranslateUi(bookin);
        QObject::connect(But_BookIn, SIGNAL(clicked()), bookin, SLOT(Bookin()));

        QMetaObject::connectSlotsByName(bookin);
    } // setupUi

    void retranslateUi(QWidget *bookin)
    {
        bookin->setWindowTitle(QCoreApplication::translate("bookin", "bookin", nullptr));
        But_BookIn->setText(QCoreApplication::translate("bookin", "\345\205\245\345\272\223", nullptr));
        label_ID->setText(QCoreApplication::translate("bookin", "ID:", nullptr));
        label_ISBN->setText(QCoreApplication::translate("bookin", "ISBN:", nullptr));
        label_name->setText(QCoreApplication::translate("bookin", "\344\271\246\345\220\215\357\274\232", nullptr));
        label_author->setText(QCoreApplication::translate("bookin", "\344\275\234\350\200\205\357\274\232", nullptr));
        label_publisher->setText(QCoreApplication::translate("bookin", "\345\207\272\347\211\210\347\244\276\357\274\232", nullptr));
        label_pubdate->setText(QCoreApplication::translate("bookin", "\345\207\272\347\211\210\346\227\245\346\234\237\357\274\232", nullptr));
        label_score->setText(QCoreApplication::translate("bookin", "\350\257\204\345\210\206\357\274\232", nullptr));
    } // retranslateUi

};

namespace Ui {
    class bookin: public Ui_bookin {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BOOKIN_H
