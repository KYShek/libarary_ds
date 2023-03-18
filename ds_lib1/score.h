#pragma once
#pragma once
#include "book.h"
class Solution1
{
public:
	BookInfo* listMergeSort(BookInfo* head) //传入需要归并排序的链表的头指针
	{
		//一个元素就返回
		if (head->next == NULL)
			return head;
		//使用 slow-fast方法找到链表的中间位置，注意这里写的链表的头节点是非空的，即头节点也是存贮数据的
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


		if (newLeft->book_score < newRight->book_score)
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
		while (newLeft != NULL || newRight != NULL)//在&&和||之间踩了大坑，调了一个多小时的bug,让我骂一句真是mmp
		{
			if (newLeft == NULL)			//左边全部接完了
			{
				tail->next = newRight; //右边就直接整条链表接上去
				newRight = NULL;
			}
			else if (newRight == NULL) {	//同理，右边接完了
				tail->next = newLeft;  //左边就直接整条链表接上去，复杂度为O（1）
				newLeft = NULL;
			}
			else if (newLeft->book_score < newRight->book_score)
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
		return newList;   //返回新接好的List，美滋滋。
	}

};
