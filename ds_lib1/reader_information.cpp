#pragma once
#include <string>
#include <QMessageBox>
#include "reader_information.h"
#include "book.h"
#include <qfile.h>
#include <qtextstream.h>
#include "ui_reader_information.h"

extern QString userid_value;
extern QString name_value;
extern const string borrow_path;

string borrow_state[4] = { "已归还","30","60", "逾期" };

Ui::reader_information* reader_window;


reader_information::reader_information(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
    //ui_pointer = &ui;
    reader_window = &ui;
    CurrentRow_value = -1;
    //用户信息刷新
    ui.label_acvalue->setText(userid_value);
    ui.label_nvalue->setText(name_value);
    //表格列数
    ui.tableWidget->setColumnCount(3);
    //建立表头
    QStringList header;
    header << "编号" << "书名" << "借阅状态";
    ui.tableWidget->setHorizontalHeaderLabels(header);
    //设置表头显示模式,这里设置的是拉伸模式
    ui.tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    //从文件读取数据
    QFile bf(borrow_path.c_str());
    bf.open(QIODevice::ReadOnly | QIODevice::Text);
    QTextStream output(&bf);
    output.setCodec("UTF-8");

    QString linestr;// 
    QStringList linelist;//

    linelist.clear();

    int i = 0;

    //记得修改
    if (!output.atEnd())output.readLine();//略去第一行
    //


    while (!output.atEnd())//output文件按行读取，直至最后一行读完
    {
        linestr = output.readLine();//对output文本流按行读取，每次循环自动到下一行
        linelist = linestr.split(",");//读到的每行按","分割成字符串链

        if (linelist[0] != userid_value)continue;
        //向表里面动态添加参数
        int rowCount = ui.tableWidget->rowCount();
        ui.tableWidget->insertRow(rowCount);
        
        for (int j = 1; j < 3; j++)
        {
            ui.tableWidget->setItem(rowCount, j-1, new QTableWidgetItem(linelist[j]));

        }
        ui.tableWidget->setItem(rowCount, 2, new QTableWidgetItem(
            QString::fromStdString(borrow_state[linelist[3].toInt()])));
    }

    bf.close();//关闭文件
}

reader_information::~reader_information()
{}



void reader_information::BorrowbkButton()
{
	borrowbk* bbk = new borrowbk;
	bbk->show();
}

void reader_information::ReborrowbkButton()
{
    QString borrowid = ui.tableWidget->model()->index(CurrentRow_value, 0).data().toString();

    QStringList linestr;
    linestr.clear();

    //从文件读取数据，in
    QFile in(borrow_path.c_str());
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

    bool flag = 0;

    QFile out(borrow_path.c_str());
    if (out.open(QIODevice::WriteOnly | QIODevice::Text)) {        //文件流写文件
        QTextStream output(&out);      //通过文本流控制文件写操作
        output.setCodec("UTF-8");
        for (int i = 0; i < linestr.size(); i++) {
            QStringList linelist = linestr.at(i).split(",");

            if (linelist.at(1) == borrowid && linelist.at(3) == "1")
            {
                linelist.replace(3, "2");
                QString temp = linelist.join(",");
                if (i != 0)output << endl;
                output << temp;

                
                ui.tableWidget->setItem(CurrentRow_value, 2, new QTableWidgetItem(
                    QString::fromStdString(borrow_state[2])));
                flag = 1;
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

    if (flag == 0)
        QMessageBox::StandardButton result = QMessageBox::critical(this, "续借失败", "续借失败");
}

void reader_information::QuitloginButton()
{
    userid_value = "";
    name_value = "";
	ds_lib1* rinfo = new ds_lib1;
	this->close ();
	rinfo->show();
}

void reader_information::TableClicked(int row, int col)
{
    ui.tableWidget->setCurrentCell(row, QItemSelectionModel::Select);
    emit SendCurrentRow(row);
}
void reader_information::RowSelected(int row)
{
    CurrentRow_value = row;
}