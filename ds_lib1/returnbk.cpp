#pragma once
#include "returnbk.h"
#include <QFile>
#include <QTextStream>
#include <QMessageBox>

extern const std::string borrow_path;
extern const char file_path[];
returnbk::returnbk(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
}

returnbk::~returnbk()
{}
void returnbk::ReturnBook()
{
   
    QString borrowid = ui.lineEdit->text();
    QStringList linestr;
    linestr.clear();

    //从文件读取数据，in
    QFile in(file_path);
    //对in文件只读模式|对于读： end-of-line结束符被转译为 '\n'；
    if (in.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        //引用in的数据，生成文本流output
        QTextStream fileread(&in);
        //output编码方式为UTF-8
        fileread.setCodec("UTF-8");

        QString arryRead;
        arryRead = fileread.readAll();
        linestr = arryRead.split("\n");        //存储每一段信息
    }
    in.close();




    bool flag0 = 0;

    QFile out(file_path);
    if (out.open(QIODevice::WriteOnly | QIODevice::Text)) {        //文件流写文件
        QTextStream output(&out);      //通过文本流控制文件写操作
        output.setCodec("UTF-8");
        for (int i = 0; i < linestr.size(); i++) {
            QStringList linelist = linestr.at(i).split(",");

            if (linelist.at(0) == borrowid && linelist.at(8) != "0")
            {
                
                linelist.replace(8, "0");
                QString temp = linelist.join(",");
                if (i != 0)output << endl;
                output << temp;
                flag0 = 1;
            }
            else
            {
                if (i != 0)
                    output << endl;
                output << linestr.at(i);
            }

        }
    }

    out.close();

    QFile borrowread(borrow_path.c_str());
    //对in文件只读模式|对于读： end-of-line结束符被转译为 '\n'；
    if (borrowread.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        //引用in的数据，生成文本流output
        QTextStream fileread(&borrowread);
        //output编码方式为UTF-8
        fileread.setCodec("UTF-8");

        QString arryRead;
        arryRead = fileread.readAll();
        linestr = arryRead.split("\n");        //存储每一段信息
    }
    borrowread.close();




    bool flag1 = 0;

    QFile borrowout(borrow_path.c_str());

    if (borrowout.open(QIODevice::WriteOnly | QIODevice::Text)) {        //文件流写文件
        QTextStream borrowoutput(&borrowout);      //通过文本流控制文件写操作
        borrowoutput.setCodec("UTF-8");
        for (int i = 0; i < linestr.size(); i++) {
            QStringList linelist = linestr.at(i).split(",");

            if (linelist.at(1) == borrowid && linelist.at(3) != "0")
            {
                flag1 = 1;

            }
            else
            {
                if (i != 0)
                   borrowoutput << endl;
                borrowoutput << linestr.at(i);
            }
        }
        
    }
    borrowout.close();


    if (!(flag0 && flag1))
        QMessageBox::StandardButton result = QMessageBox::critical(this, "归还失败", "归还失败");
    else
        this->close();
}