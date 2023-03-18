#include "book.h"
#include "bookout.h"

#include <qfile.h>
#include <qtextstream.h>
#include <qmessagebox>


#include "ui_bkstock.h"
#include "bkstock.h"
extern Ui::bkstock* bkstock_window;

bookout::bookout(QWidget* parent)
    : QWidget(parent)
{
    ui.setupUi(this);
}

bookout::~bookout()
{}
void bookout::BookOut()
{
    QString ID = ui.lineEdit_ID->text();
    QStringList linestr;
    //从文件读取数据，outread
    QFile outread(file_path);
    //对outread文件只读模式|对于读： end-of-line结束符被转译为 '\n'；
    if (outread.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        //引用in的数据，生成文本流readbook
        QTextStream readbook(&outread);
        //readbook编码方式为UTF-8
        readbook.setCodec("UTF-8");
        //QHash<QString, QString> varHash;//建了一个哈希表
        //varHash.clear();
        QString arryread;
        arryread = outread.readAll();
        linestr = arryread.split("\n");
    }
    outread.close();
    bool flag1 = 0;
    QFile out(file_path);
    if (out.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        QTextStream outbook(&out);
        outbook.setCodec("UTF-8");
        for (int i = 0; i < linestr.size(); i++)
        {
            QStringList linelist = linestr.at(i).split(",");
            if (linelist.at(0) == ID)
            {
                flag1 = 1;
            }
            else
            {
                if (i != 0)
                    outbook << endl;
                outbook << linestr.at(i);
            }
        }
        out.close();

        //循环读取数据
        for (int i = 0; i < bkstock_window->tableWidget->rowCount(); i++) {
            if (bkstock_window->tableWidget->item(i, 0)->text() == ID) {               //一定要先判断非空，否则会报错
                bkstock_window->tableWidget->removeRow(i);
            }
        }

        if (!flag1)
        {
            QMessageBox::StandardButton result = QMessageBox::critical(this, "出库失败", "出库失败");
        }
        else
            this->close();
    }
}
