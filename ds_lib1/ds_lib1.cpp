#pragma once
#include "ds_lib1.h"
#include "book.h"
#include <QFile>
#include <string>
#include <qtextstream>
#include <QMessagebox>
const string login_path = "username.txt";

const string borrow_path = "borrow.csv";

QString userid_value;
QString name_value;

ds_lib1::ds_lib1(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
    userid_value = "";
    name_value = "";
}

ds_lib1::~ds_lib1()
{}

void ds_lib1::ReturnButtonClicked()
{
    //this->hide();
    returnbk* rtn = new returnbk;
    rtn->show();
}

void ds_lib1::LoginButtonClicked()
{
    bool flag = 0;
    flag = ds_lib1::LoginJudge();
    if (flag == true)
    {
        this->hide();
        reader_information* rinfo = new reader_information;
        rinfo->show();
    }
    else
    {
        QMessageBox::StandardButton result = QMessageBox::critical(this, "登陆失败", "请检查用户名");
    }
}

void ds_lib1::QueryButtonClicked()
{
    querybk* qbk = new querybk();
    qbk->show();
}

void ds_lib1::AdmButtonClicked()
{
    bkstock* bks = new bkstock;
    bks->show();
    this->close();
}


bool ds_lib1::LoginJudge()
{


    //从文件读取数据，in
    QFile login(login_path.c_str());
    //对in文件只读模式|对于读： end-of-line结束符被转译为 '\n'；
    login.open(QIODevice::ReadOnly | QIODevice::Text);
    //引用in的数据，生成文本流output
    QTextStream output(&login);
    //output编码方式为UTF-8
    output.setCodec("UTF-8");

    QString linestr;// 
    QStringList linelist;
    linelist.clear();
    int i = 0;

    //记得修改
    if (!output.atEnd())output.readLine();//略去第一行
    //


    while (!output.atEnd())//output文件按行读取，直至最后一行读完
    {
        linestr = output.readLine();//对output文本流按行读取，每次循环自动到下一行
        linelist = linestr.split(",");//读到的每行按","分割成字符串链
        if (ui.lineEdit->text() == linelist[0])
        {
            userid_value = ui.lineEdit->text();
            name_value = linelist[1];
            return true;
        }

    }
    return false;
}