#include <iostream>
#include <vector>
using namespace std;
/**
 * 链表的反转算法：
 * 核心的思想是一个工作指针p、一个rear指针初始值设为NULL,还有一个从后往前指的指针before。
*/
struct ListNode
{
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

void print_list(ListNode *head);
/**
 * 方法 1，不带头结点，直接反转链表，链表反转算法：不带头结点的写法,需要三个指针，一个当前cur，一个rear，一个pre。
*/
ListNode *reverseList1(ListNode *pHead)
{
	if (pHead == NULL || pHead->next == NULL)
		return pHead;
	ListNode *rear = NULL;
	ListNode *cur = pHead;
	ListNode *pre = pHead;
	while (cur)
	{
		pre = cur;
		cur = cur->next; //工作指针
		pre->next = rear;
		rear = pre;
	}
	return rear;
}

/**
 * 方法 2，带头结点的写法,temp指针来保存cur 的下一个地址即可 
*/
ListNode *reverseList2(ListNode *head)
{
	ListNode *p = head;
	ListNode *dummy = new ListNode(-1);
	dummy->next = head;
	while (p->next)
	{
		ListNode *tmp = p->next;
		p->next = tmp->next;
		tmp->next = dummy->next;
		dummy->next = tmp;
	}
	return dummy->next;
}

int main()
{
	//自己造一个回文链表

	ListNode *a1 = new ListNode(1);
	ListNode *a2 = new ListNode(2);
	ListNode *a3 = new ListNode(3);
	ListNode *a4 = new ListNode(4);
	ListNode *a5 = new ListNode(5);
	a1->next = a2;
	a2->next = a3;
	a3->next = a4;
	a4->next = a5;

	print_list(a1);
	// print_list(ReverseList(a1));
	print_list(reverseList2(a1));
	delete a1;
	delete a2;
	delete a3;
	delete a4;
	delete a5;
	return 0;
}

//打印部分：
void print_list(ListNode *head)
{
	while (head)
	{
		cout << head->val << "->";
		head = head->next;
	}
	cout << "end" << endl;
}
