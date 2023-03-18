#include "book.h"
#include "bookin.h"

#include <qfile.h>
#include <qtextstream.h>
#include <QMessageBox>

#include "ui_bkstock.h"
#include "bkstock.h"
extern Ui::bkstock* bkstock_window;

bookin::bookin(QWidget* parent)
    : QWidget(parent)
{
    ui.setupUi(this);
}

bookin::~bookin()
{}

void bookin::Bookin()
{
    //表格列数
    QString Id = ui.lineEdit_ID->text();
    QString Isbn = ui.lineEdit_ISBN->text();
    QString Name = ui.lineEdit_name->text();
    QString Author = ui.lineEdit_author->text();
    QString Publisher = ui.lineEdit_publisher->text();
    QString Pub_date = ui.lineEdit_pubdate->text();
    QString Score = ui.lineEdit_score->text();
    if (Id.isEmpty() || Isbn.isEmpty() || Name.isEmpty() || Author.isEmpty() || Publisher.isEmpty() || Pub_date.isEmpty() || Score.isEmpty())
    {
        QMessageBox::StandardButton result = QMessageBox::critical(this, "入库失败", "输入数据不可为空");
    }
    else {

        QFile outFile(file_path);
        if (outFile.open(QIODevice::Append | QIODevice::Text))
        {
            // 创建stream
            QTextStream in(&outFile);
            in.setCodec("UTF-8");//设置编码格式
           
            
            in << endl << Id << "," << Name << "," << Isbn << "," << Author << "," << Publisher << "," << Pub_date <<"," << Score <<","<< "0"<<","<<"0";// 在stream追加数据，并换行
            
        }
        outFile.close();
        int rowCount = bkstock_window->tableWidget->rowCount();
        bkstock_window->tableWidget->insertRow(rowCount);
        //header << "编号" << "书名" << "ISBN" << "作者" << "出版社" << "出版日期" << "评分" << "借阅次数" << "出借状态";
        bkstock_window->tableWidget->setItem(rowCount, 0, new QTableWidgetItem(Id));
        bkstock_window->tableWidget->setItem(rowCount, 1, new QTableWidgetItem(Name));
        bkstock_window->tableWidget->setItem(rowCount, 2, new QTableWidgetItem(Isbn));
        bkstock_window->tableWidget->setItem(rowCount, 3, new QTableWidgetItem(Author));
        bkstock_window->tableWidget->setItem(rowCount, 4, new QTableWidgetItem(Publisher));
        bkstock_window->tableWidget->setItem(rowCount, 5, new QTableWidgetItem(Pub_date));
        bkstock_window->tableWidget->setItem(rowCount, 6, new QTableWidgetItem(Score));
        bkstock_window->tableWidget->setItem(rowCount, 7, new QTableWidgetItem(QString::number(0)));
        bkstock_window->tableWidget->setItem(rowCount, 8, new QTableWidgetItem(QString::number(0)));
        QMessageBox::StandardButton result = QMessageBox::information(this, "入库成功", "入库成功");
    }
}

