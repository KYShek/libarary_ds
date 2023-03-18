/********************************************************************************
** Form generated from reading UI file 'ds_lib1.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DS_LIB1_H
#define UI_DS_LIB1_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LoginPage
{
public:
    QWidget *centralWidget;
    QLineEdit *lineEdit;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *btn2_return;
    QPushButton *btn3_query;
    QLabel *label;
    QPushButton *btn1_login;
    QLabel *titlelabel;
    QPushButton *btn_adm_test;

    void setupUi(QMainWindow *LoginPage)
    {
        if (LoginPage->objectName().isEmpty())
            LoginPage->setObjectName(QString::fromUtf8("LoginPage"));
        LoginPage->resize(811, 412);
        centralWidget = new QWidget(LoginPage);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        lineEdit = new QLineEdit(centralWidget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(250, 130, 350, 40));
        lineEdit->setMinimumSize(QSize(350, 40));
        lineEdit->setMaximumSize(QSize(350, 40));
        layoutWidget = new QWidget(centralWidget);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 340, 791, 52));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        btn2_return = new QPushButton(layoutWidget);
        btn2_return->setObjectName(QString::fromUtf8("btn2_return"));
        btn2_return->setMinimumSize(QSize(100, 50));
        btn2_return->setMaximumSize(QSize(100, 50));
        QFont font;
        font.setFamily(QString::fromUtf8("\346\245\267\344\275\223"));
        font.setPointSize(14);
        btn2_return->setFont(font);

        horizontalLayout->addWidget(btn2_return);

        btn3_query = new QPushButton(layoutWidget);
        btn3_query->setObjectName(QString::fromUtf8("btn3_query"));
        btn3_query->setMinimumSize(QSize(100, 50));
        btn3_query->setMaximumSize(QSize(100, 50));
        btn3_query->setFont(font);

        horizontalLayout->addWidget(btn3_query);

        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(150, 140, 100, 30));
        label->setMinimumSize(QSize(100, 30));
        label->setMaximumSize(QSize(100, 30));
        label->setFont(font);
        btn1_login = new QPushButton(centralWidget);
        btn1_login->setObjectName(QString::fromUtf8("btn1_login"));
        btn1_login->setGeometry(QRect(360, 200, 100, 50));
        btn1_login->setMinimumSize(QSize(100, 50));
        btn1_login->setMaximumSize(QSize(100, 50));
        btn1_login->setFont(font);
        titlelabel = new QLabel(centralWidget);
        titlelabel->setObjectName(QString::fromUtf8("titlelabel"));
        titlelabel->setGeometry(QRect(270, 30, 300, 50));
        titlelabel->setMinimumSize(QSize(300, 50));
        titlelabel->setMaximumSize(QSize(300, 50));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\346\245\267\344\275\223"));
        font1.setPointSize(16);
        titlelabel->setFont(font1);
        btn_adm_test = new QPushButton(centralWidget);
        btn_adm_test->setObjectName(QString::fromUtf8("btn_adm_test"));
        btn_adm_test->setGeometry(QRect(360, 270, 101, 51));
        btn_adm_test->setFont(font);
        LoginPage->setCentralWidget(centralWidget);

        retranslateUi(LoginPage);
        QObject::connect(btn2_return, SIGNAL(clicked()), LoginPage, SLOT(ReturnButtonClicked()));
        QObject::connect(btn1_login, SIGNAL(clicked()), LoginPage, SLOT(LoginButtonClicked()));
        QObject::connect(btn3_query, SIGNAL(clicked()), LoginPage, SLOT(QueryButtonClicked()));
        QObject::connect(btn_adm_test, SIGNAL(clicked()), LoginPage, SLOT(AdmButtonClicked()));

        QMetaObject::connectSlotsByName(LoginPage);
    } // setupUi

    void retranslateUi(QMainWindow *LoginPage)
    {
        LoginPage->setWindowTitle(QCoreApplication::translate("LoginPage", "ds_lib1", nullptr));
        btn2_return->setText(QCoreApplication::translate("LoginPage", "\345\275\222\350\277\230", nullptr));
        btn3_query->setText(QCoreApplication::translate("LoginPage", "\346\237\245\350\257\242", nullptr));
        label->setText(QCoreApplication::translate("LoginPage", "<html><head/><body><p align=\"center\">\350\264\246\345\217\267</p></body></html>", nullptr));
        btn1_login->setText(QCoreApplication::translate("LoginPage", "\347\231\273\345\275\225", nullptr));
        titlelabel->setText(QCoreApplication::translate("LoginPage", "<html><head/><body><p align=\"center\">\350\231\232\346\213\237\346\231\272\346\205\247\345\233\276\344\271\246\351\246\206</p></body></html>", nullptr));
        btn_adm_test->setText(QCoreApplication::translate("LoginPage", "\347\256\241\347\220\206\345\221\230", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LoginPage: public Ui_LoginPage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DS_LIB1_H
