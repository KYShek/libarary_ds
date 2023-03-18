#pragma once
#include<algorithm>
#include <iostream>
#include <string.h>
#include "book.h"


using namespace std;
class Solution2
{
public:
	BookInfo* listMergeSort(BookInfo* head) //传入需要归并排序的链表的头指针
	{
		//一个元素就返回
		if (head->next == NULL)
			return head;
		BookInfo* fast = head->next;  //   fast指向第2个节点
		BookInfo* slow = head;	  //   slow指向第1个节点	
		while (fast != NULL && fast->next != NULL)
		{
			fast = fast->next->next; //fast每次走两步
			slow = slow->next;	//slow每次走一步，这样slow就会到lian'biao中点
		}
		//slow最后指向有n个元素的链表的第n/2个元素。如一共6个元素，slow指向第3个，一共5个元素，slow指向第2个。
		BookInfo* left = head;
		BookInfo* right = slow->next;
		slow->next = NULL;
		BookInfo* newLeft = listMergeSort(left);
		BookInfo* newRight = listMergeSort(right);

		BookInfo* newList;  //注意指针tail才是后面进行操作的指针，newList是为了保存起点
		BookInfo* tail;


		if (newLeft->book_times < newRight->book_times)
		{
			newList = newLeft;
			newLeft = newLeft->next;
		}
		else
		{
			newList = newRight;
			newRight = newRight->next;
		}
		tail = newList;
		tail->next = NULL;
		//以上代码是向newList的第一个节点存入左右两个链表的头节点的较小的元素
		while (newLeft != NULL || newRight != NULL)
		{
			if (newLeft == NULL)			//左边全部接完了
			{
				tail->next = newRight; //右边就直接整条链表接上去
				newRight = NULL;
			}
			else if (newRight == NULL) {	//同理，右边接完了
				tail->next = newLeft;  //左边就直接整条链表接上去
				newLeft = NULL;
			}
			else if (newLeft->book_times < newRight->book_times)
			{
				tail->next = newLeft;		//上面接一整个链表，这里就是接链表中单个元素的操作
				newLeft = newLeft->next;
				tail = tail->next;
				tail->next = NULL;
			}
			else {
				tail->next = newRight;
				newRight = newRight->next;
				tail = tail->next;
				tail->next = NULL;
			}
		}
		return newList;   //返回新接好的List
	}
};


