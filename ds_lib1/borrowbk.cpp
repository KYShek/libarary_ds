#pragma once
#include "borrowbk.h"
#include <QFile>
#include <qtextstream>
#include <QMessagebox>

#include "ui_reader_information.h"
#include "reader_information.h"
extern Ui::reader_information* reader_window;
extern const char file_path[];
extern QString userid_value;
extern std::string borrow_state[4];
extern const std::string borrow_path;
borrowbk::borrowbk(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
}

borrowbk::~borrowbk()
{}

void borrowbk::BorrowClicked()
{
	//reader_window->label_acvalue->setText("test");
    QString borrowid = ui.lineEdit_BrId->text();

    bool flag = 0;


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

        QFile out(file_path);
        if (out.open(QIODevice::WriteOnly | QIODevice::Text)) {        //文件流写文件
            QTextStream output(&out);      //通过文本流控制文件写操作
            output.setCodec("UTF-8");
            for (int i = 0; i < linestr.size(); i++) {
                QStringList linelist = linestr.at(i).split(",");

                if (linelist.at(0) == borrowid && linelist.at(8) == "0")
                {
                    int times_temp = 0;
                    times_temp = linelist.at(7).toInt();
                    times_temp++;
                    linelist.replace(7, QString::number(times_temp));
                    linelist.replace(8, userid_value);
                    QString temp = linelist.join(",");
                    if (i != 0)output << endl;
                    output << temp;

                    int rowCount = reader_window->tableWidget->rowCount();
                    reader_window->tableWidget->insertRow(rowCount);
                    QFile borrowout(borrow_path.c_str());
                    if (borrowout.open(QIODevice::Append | QIODevice::Text)) {        //文件流写文件
                        QTextStream borrowoutput(&borrowout);      //通过文本流控制文件写操作
                        borrowoutput.setCodec("UTF-8");
                        borrowoutput << endl;
                        borrowoutput << userid_value << ",";
                        for (int j = 0; j < 2; j++)
                        {
                            reader_window->tableWidget->setItem(rowCount, j, new QTableWidgetItem(linelist[j]));
                            borrowoutput << linelist[j] << ",";
                        }
                        reader_window->tableWidget->setItem(rowCount, 2, new QTableWidgetItem(
                            QString::fromStdString(borrow_state[1])));
                        borrowoutput << "1";
                        flag = 1;
                    }
                    borrowout.close();
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
        QMessageBox::StandardButton result = QMessageBox::critical(this, "借阅失败", "借阅失败");
    else
        this->close();
}