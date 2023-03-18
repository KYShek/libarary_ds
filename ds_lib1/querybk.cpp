#include "querybk.h"
#include "book.h"
#include "score.h"
#include "times.h"

#include <qfile.h>
#include <qtextstream.h>

string state[2] = { "已借出" , "在架上" };

querybk::querybk(QWidget* parent)
    : QWidget(parent)
{
    ui.setupUi(this);

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
        for (int j = 0; j < 8; j++)
        {
            ui.tableWidget->setItem(rowCount, j, new QTableWidgetItem(linelist[j]));

        }
        ui.tableWidget->setItem(rowCount, 8, new QTableWidgetItem(QString::fromStdString(state[((linelist[8].toInt() == 0) ? 1 : 0)])));
    }
    in.close();//关闭文件
}

querybk::~querybk()
{}

void querybk::TimesRank() //兴趣度
{
    //清空表
    for (int i = ui.tableWidget->rowCount() - 1; i >= 0; i--)
    {
        ui.tableWidget->removeRow(i);
    }

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
        //p到下个结点
        if (!output.atEnd())
        {
            p->next = new BookInfo;
            p = p->next;
        }
    }
    in.close();//关闭文件
    Solution2 s2;
    BookInfo* timesrank = s2.listMergeSort(book);
    
    static int m = 0; m++;
    if (m % 2 == 0) {
        BookInfo::reverse(timesrank);
    }

    //向表里面动态添加参数
    int rowCount = ui.tableWidget->rowCount();
    while (!timesrank == NULL)
    {
        ui.tableWidget->insertRow(rowCount);
        QString temp = QString::number(timesrank->book_id);
        ui.tableWidget->setItem(rowCount, 0, new QTableWidgetItem(temp));
        ui.tableWidget->setItem(rowCount, 1, new QTableWidgetItem(timesrank->book_name));
        ui.tableWidget->setItem(rowCount, 2, new QTableWidgetItem(timesrank->book_isbn));
        ui.tableWidget->setItem(rowCount, 3, new QTableWidgetItem(timesrank->book_author));
        ui.tableWidget->setItem(rowCount, 4, new QTableWidgetItem(timesrank->book_publisher));
        ui.tableWidget->setItem(rowCount, 5, new QTableWidgetItem(timesrank->book_pub_date));
        temp = QString::number(timesrank->book_score);
        ui.tableWidget->setItem(rowCount, 6, new QTableWidgetItem(temp));
        temp = QString::number(timesrank->book_times);
        ui.tableWidget->setItem(rowCount, 7, new QTableWidgetItem(temp));
        temp = QString::fromStdString(state[((timesrank->book_state == 0) ? 1 : 0)]);
        ui.tableWidget->setItem(rowCount, 8, new QTableWidgetItem(temp));

        timesrank = timesrank->next;
    }

}

void querybk::ScoreRank()
{
    //清空表
    for (int i = ui.tableWidget->rowCount() - 1; i >= 0; i--)
    {
        ui.tableWidget->removeRow(i);
    }

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
    int row = 0;

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
        //p到下个结点
        if (!output.atEnd())
        {
            p->next = new BookInfo;
            p = p->next;
        }
    }
    in.close();//关闭文件
    Solution1 s1;
    BookInfo* scorerank = s1.listMergeSort(book);

    static int m = 0; m++;
    if (m % 2 == 0) {
        BookInfo::reverse(scorerank);
    }

    //向表里面动态添加参数
    int rowCount = ui.tableWidget->rowCount();
    while (!scorerank == NULL)
    {
        ui.tableWidget->insertRow(rowCount);
        QString temp = QString::number(scorerank->book_id);
        ui.tableWidget->setItem(rowCount, 0, new QTableWidgetItem(temp));
        ui.tableWidget->setItem(rowCount, 1, new QTableWidgetItem(scorerank->book_name));
        ui.tableWidget->setItem(rowCount, 2, new QTableWidgetItem(scorerank->book_isbn));
        ui.tableWidget->setItem(rowCount, 3, new QTableWidgetItem(scorerank->book_author));
        ui.tableWidget->setItem(rowCount, 4, new QTableWidgetItem(scorerank->book_publisher));
        ui.tableWidget->setItem(rowCount, 5, new QTableWidgetItem(scorerank->book_pub_date));
        temp = QString::number(scorerank->book_score);
        ui.tableWidget->setItem(rowCount, 6, new QTableWidgetItem(temp));
        temp = QString::number(scorerank->book_times);
        ui.tableWidget->setItem(rowCount, 7, new QTableWidgetItem(temp));
        temp = QString::fromStdString(state[((scorerank->book_state == 0) ? 1 : 0)]);
        ui.tableWidget->setItem(rowCount, 8, new QTableWidgetItem(temp));
        scorerank = scorerank->next;
    }
}

void querybk::DateRank()
{
    //清空表
    for (int i = ui.tableWidget->rowCount() - 1; i >= 0; i--)
    {
        ui.tableWidget->removeRow(i);
    }

    //从文件读取数据，in
    QFile in(file_path);
    //对in文件只读模式|对于读： end-of-line结束符被转译为 '\n'；
    in.open(QIODevice::ReadOnly | QIODevice::Text);
    //引用in的数据，生成文本流output
    QTextStream output(&in);
    //output编码方式为UTF-8
    output.setCodec("UTF-8");
    //QHash<QString, QString> varHash;//建了一个哈希表
    QString linestr;// 
    QStringList linelist;//
    //varHash.clear();
    linelist.clear();

    BookInfo* daterank = NULL;
    BookInfo* p = NULL;
    daterank = p = new BookInfo;

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
        //p到下个结点
        if (!output.atEnd())
        {
            p->next = new BookInfo;
            p = p->next;
        }
    }
    in.close();//关闭文件

    BookInfo::sortbydate(daterank);

    static int m = 0; m++;
    if (m % 2 == 0) {
        BookInfo::reverse(daterank);
    }

    //向表里面动态添加参数
    int rowCount = ui.tableWidget->rowCount();
    while (!daterank == NULL)
    {
        ui.tableWidget->insertRow(rowCount);
        QString temp = QString::number(daterank->book_id);
        ui.tableWidget->setItem(rowCount, 0, new QTableWidgetItem(temp));
        ui.tableWidget->setItem(rowCount, 1, new QTableWidgetItem(daterank->book_name));
        ui.tableWidget->setItem(rowCount, 2, new QTableWidgetItem(daterank->book_isbn));
        ui.tableWidget->setItem(rowCount, 3, new QTableWidgetItem(daterank->book_author));
        ui.tableWidget->setItem(rowCount, 4, new QTableWidgetItem(daterank->book_publisher));
        ui.tableWidget->setItem(rowCount, 5, new QTableWidgetItem(daterank->book_pub_date));
        temp = QString::number(daterank->book_score);
        ui.tableWidget->setItem(rowCount, 6, new QTableWidgetItem(temp));
        temp = QString::number(daterank->book_times);
        ui.tableWidget->setItem(rowCount, 7, new QTableWidgetItem(temp));
        temp = QString::fromStdString(state[((daterank->book_state == 0) ? 1 : 0)]);
        ui.tableWidget->setItem(rowCount, 8, new QTableWidgetItem(temp));
        daterank = daterank->next;
    }
}

void querybk::DefaltRank()
{
    //清空表
    for (int i = ui.tableWidget->rowCount() - 1; i >= 0; i--)
    {
        ui.tableWidget->removeRow(i);
    }

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
    //QHash<QString, QString> varHash;//建了一个哈希表
    QString linestr;// 
    QStringList linelist;//
    //varHash.clear();
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
    }
    in.close();//关闭文件

    static int m = 0; m++;
    if (m % 2 == 0) {
        BookInfo::reverse(book);
    }

    //向表里面动态添加参数
    int rowCount = ui.tableWidget->rowCount();
    while (!book == NULL)
    {
        ui.tableWidget->insertRow(rowCount);
        QString temp = QString::number(book->book_id);
        ui.tableWidget->setItem(rowCount, 0, new QTableWidgetItem(temp));
        ui.tableWidget->setItem(rowCount, 1, new QTableWidgetItem(book->book_name));
        ui.tableWidget->setItem(rowCount, 2, new QTableWidgetItem(book->book_isbn));
        ui.tableWidget->setItem(rowCount, 3, new QTableWidgetItem(book->book_author));
        ui.tableWidget->setItem(rowCount, 4, new QTableWidgetItem(book->book_publisher));
        ui.tableWidget->setItem(rowCount, 5, new QTableWidgetItem(book->book_pub_date));
        temp = QString::number(book->book_score);
        ui.tableWidget->setItem(rowCount, 6, new QTableWidgetItem(temp));
        temp = QString::number(book->book_times);
        ui.tableWidget->setItem(rowCount, 7, new QTableWidgetItem(temp));
        temp = QString::fromStdString(state[((book->book_state == 0) ? 1 : 0)]);
        ui.tableWidget->setItem(rowCount, 8, new QTableWidgetItem(temp));
        book = book->next;
    }
}

void querybk::VagueQ()
{
    //清空表
    for (int i = ui.tableWidget->rowCount() - 1; i >= 0; i--)
    {
        ui.tableWidget->removeRow(i);
    }
    //从lineedit里面获取字符
    QString name = ui.lineEdit->text();
    QString publisher = ui.lineEdit_2->text();
    QString author = ui.lineEdit_3->text();
    //字符串切开变成字符串链
    QStringList  nm = name.split("");
    QStringList  ath = author.split("");
    QStringList  pb = publisher.split("");

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

    if (!output.atEnd())output.readLine();//略去文件的第一行

    while (!output.atEnd())//output文件按行读取，直至最后一行读完
    {
        linestr = output.readLine();//对output文本流按行读取，每次循环自动到下一行
        linelist = linestr.split(",");//读到的每行按","分割成字符串链

        QString temp1 = linelist.at(1);//把字符串从链中单独拿出来
        QStringList t1 = temp1.split("");//把书名切成新的字符串链
        QString temp3 = linelist.at(3);
        QStringList t3 = temp3.split("");//作者切开
        QString temp4 = linelist.at(4);
        QStringList t4 = temp4.split("");//出版社切开

        bool b1 = whether(nm, t1);
        bool b3 = whether(ath, t3);
        bool b4 = whether(pb, t4);

        //向表里面动态添加参数
        int rowCount = ui.tableWidget->rowCount();
        if (b1 * b3 * b4) {
            ui.tableWidget->insertRow(rowCount);
            for (int k = 0; k < 8; k++)
            {
                ui.tableWidget->setItem(rowCount, k, new QTableWidgetItem(linelist[k]));
                ui.tableWidget->setItem(rowCount, 8, new QTableWidgetItem(QString::fromStdString(state[((linelist[8].toInt() == 0) ? 1 : 0)])));
            }
        }
        temp1 = "";
        temp3 = "";
        temp4 = "";
    }
    in.close();//关闭文件

    ui.lineEdit->clear();
    ui.lineEdit_2->clear();
    ui.lineEdit_3->clear();
}

bool querybk::whether(QStringList str1, QStringList str2)//查询字，所在字符串
{

    if (QString(str1.join("")).isEmpty()) return true;
    else {
        QStringList midresult;
        int flag = 0;
        for (int j = 1; j < str1.length() - 1; j++)
        {
            midresult = str2.filter(str1.at(j));
            if (QString(midresult.join("")).isEmpty())
            {
                return false;
            }
            else flag++;
        }
        if (flag == str1.length())
        {
            return false;
        }
        else return true;
    }
}

void querybk::PreciseQ()
{
    //从lineedit里面获取字符
    QString isbn = ui.lineEdit_4->text();
    //清空表
    for (int i = ui.tableWidget->rowCount() - 1; i >= 0; i--)
    {
        ui.tableWidget->removeRow(i);
    }
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

    if (!output.atEnd())output.readLine();//略去第一行

    while (!output.atEnd())//output文件按行读取，直至最后一行读完
    {
        linestr = output.readLine();//对output文本流按行读取，每次循环自动到下一行
        linelist = linestr.split(",");//读到的每行按","分割成字符串链

        //向表里面动态添加参数
        int rowCount = ui.tableWidget->rowCount();
        if (linelist[2] == isbn)
        {
            ui.tableWidget->insertRow(rowCount);
            for (int k = 0; k < 8; k++)
            {
                ui.tableWidget->setItem(rowCount, k, new QTableWidgetItem(linelist[k]));
                ui.tableWidget->setItem(rowCount, 8, new QTableWidgetItem(QString::fromStdString(state[((linelist[8].toInt() == 0) ? 1 : 0)])));
            }
        }
    }

    in.close();//关闭文件

    ui.lineEdit_4->clear();
}