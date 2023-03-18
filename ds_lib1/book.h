#pragma once
#include <iostream>
#include <fstream>
#include <iomanip>
#include <sstream>
#include <string>
#include <stdlib.h>
#include <cstring>
//#define FILE_PATH "booklist1020.csv"
extern const char file_path[];

using namespace std;

class BookInfo
{
	//id, name, ISBN, author, publisher, book_pub_date, score
public:
	int book_id;//书籍编号
	char book_name[60]; //书籍名称
	char book_isbn[60]; //书籍ISBN
	char book_author[60]; //书籍作者
	char book_publisher[60];//书籍出版社
	char book_pub_date[60]; //书籍发售日期
	float book_score; //书籍评分
	int book_times;//借阅次数（读者兴趣度）
	int book_state;
	//*******************************************************
	BookInfo* next;//定义指向类BookInfo的指针变量next
	BookInfo(int book_id = 0, const char* book_name = "null", const char* book_isbn = "null", const char* book_author = "null", const char* book_publisher = "null", const char* book_pub_date = "null", float book_score = 0, int book_times = 0, int book_state = 0)//定义构造函数
	{
		this->book_id = book_id;
		strcpy_s(this->book_name, book_name);
		strcpy_s(this->book_isbn, book_isbn);
		strcpy_s(this->book_author, book_author);
		strcpy_s(this->book_publisher, book_publisher);
		strcpy_s(this->book_pub_date, book_pub_date);
		this->book_score = book_score;
		this->book_times = book_times;
		this->book_state = book_state;
		//************************************************************************************
		this->next = NULL;
	}

	static void sortbydate(BookInfo* head)
	{
		if (head == NULL || head->next == NULL)
			return;
		BookInfo* cur;
		BookInfo* tem;
		for (cur = head; cur->next != NULL; cur = cur->next) {
			BookInfo* min = cur;
			for (tem = cur; tem != NULL; tem = tem->next) {
				if (string(tem->book_pub_date) < string(min->book_pub_date)) {
					swap(tem->book_id, min->book_id);
					swap(tem->book_name, min->book_name);
					swap(tem->book_isbn, min->book_isbn);
					swap(tem->book_author, min->book_author);
					swap(tem->book_publisher, min->book_publisher);
					swap(tem->book_pub_date, min->book_pub_date);
					swap(tem->book_score, min->book_score);
					swap(tem->book_times, min->book_times);
					swap(tem->book_state, min->book_state);
				}
			}
			swap(cur->book_pub_date, min->book_pub_date);
		}
	}
	static void reverse(BookInfo*& head)
	{

		BookInfo* cur = NULL;
		BookInfo* pre = head;
		while (pre != NULL)
		{
			BookInfo* t = pre->next;
			pre->next = cur;
			cur = pre;
			pre = t;
		}
		head = cur;
	}
	/*控制台测试用函数
	static void printList(BookInfo* n)
	{
		while (n != NULL) {
			cout << n->book_id << " ";
			cout << n->book_name << " ";
			cout << n->book_isbn << " ";
			cout << n->book_author << " ";
			cout << n->book_publisher << " ";
			cout << n->book_pub_date << " ";
			cout << n->book_score << " ";
			cout << n->book_times << " ";
			cout << n->book_state << endl;
			//**************************************************************
			n = n->next;
		}
	}*/
};