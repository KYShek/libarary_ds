#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_ds_lib1.h"

#include "returnbk.h"
#include "reader_information.h"
#include "querybk.h"
#include "bkstock.h"
extern const string login_path;
extern const string borrow_path;


class ds_lib1 : public QMainWindow
{
    Q_OBJECT

public:
    ds_lib1(QWidget *parent = nullptr);
    ~ds_lib1();

private slots:
    void ReturnButtonClicked();
    void LoginButtonClicked();
    void QueryButtonClicked();
    void AdmButtonClicked();

private:
    Ui::LoginPage ui;
    bool LoginJudge();
};
