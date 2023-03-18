#include "bkstock.h"
#include "book.h"

#include <qfile.h>
#include <qtextstream.h>

Ui::bkstock * bkstock_window;

string state1[2] = { "已借出" , "在架上" };

bkstock::bkstock(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
    bkstock_window = &ui;

    //表格列数
    ui.tableWidget->setColumnCount(9);
    //建立表头
    QStringList header;
    header << "编号" << "书名" << "ISBN" << "作者" << "出版社" << "出版日期" << "评分" << "借阅次数" << "出借状态";
    ui.tableWidget->setHorizontalHeaderLabels(header);
    //设置显示模式,使得每一项都能看见
    ui.tableWidget->horizontalHeader()->setStretchLastSection(true);
    //设置表格内容不可以修改
    ui.tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);

    //从文件读取数据，in
    QFile in(file_path);
    //对in文件只读模式|对于读： end-of-line结束符被转译为 '\n'；
    in.open(QIODevice::ReadOnly | QIODevice::Text);
    //引用in的数据，生成文本流output
    QTextStream output(&in);
    //output编码方式为UTF-8
    output.setCodec("UTF-8");
    QString linestr;// 
    QStringList linelist;//
    linelist.clear();

    BookInfo* book = NULL;
    BookInfo* p = NULL;
    book = p = new BookInfo;

    int i = 0;

    //记得修改
    if (!output.atEnd())output.readLine();//略去第一行
    //

    while (!output.atEnd())//output文件按行读取，直至最后一行读完
    {
        linestr = output.readLine();//对output文本流按行读取，每次循环自动到下一行
        linelist = linestr.split(",");//读到的每行按","分割成字符串链

        //把linelist字符串链里的每项拿出来存到结点的数据域
        p->book_id = linelist.at(0).toInt();
        strcpy_s(p->book_name, linelist.at(1).toLocal8Bit().data());
        //p->book_isbn=atoi(data[2].c_str());
        strcpy_s(p->book_isbn, linelist.at(2).toLocal8Bit().data());
        strcpy_s(p->book_author, linelist.at(3).toLocal8Bit().data());
        strcpy_s(p->book_publisher, linelist.at(4).toLocal8Bit().data());
        strcpy_s(p->book_pub_date, linelist.at(5).toLocal8Bit().data());
        p->book_score = linelist.at(6).toFloat();
        p->book_times = linelist.at(7).toInt();
        p->book_state = linelist.at(8).toInt();
        //链表到下个结点
        if (!output.atEnd())
        {
            p->next = new BookInfo;
            p = p->next;
        }
        //向表里面动态添加参数
        int rowCount = ui.tableWidget->rowCount();
        ui.tableWidget->insertRow(rowCount);
        for (int j = 0; j < 9; j++)
        {
            ui.tableWidget->setItem(rowCount, j, new QTableWidgetItem(linelist[j]));
        }
    }
    in.close();//关闭文件
}

bkstock::~bkstock()
{}

void bkstock::QueryButton()
{
}

void bkstock::BkinButton()
{
	bookin* bki = new bookin;
	bki->show();
}

void bkstock::BkoutButton()
{
	bookout* bko = new bookout;
	bko->show();
}

void bkstock::QuitloginButton()
{
	ds_lib1* rinfo = new ds_lib1;
	this->close();
	rinfo->show();

}