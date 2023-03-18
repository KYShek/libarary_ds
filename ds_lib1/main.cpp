#include "ds_lib1.h"
#include <QtWidgets/QApplication>

#include "book.h"
const char file_path[] = "booklist1025.csv";
#include "book.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ds_lib1 w;
    w.show();
    return a.exec();
}
