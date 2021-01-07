#include <iostream>
#include <vector>
using namespace std;
/**
 * 147 对链表进行插入排序，两轮遍历，一轮是遍历所有的元素，
 * 一轮是遍历已经排序的部分。
 * 思路2 是正确解答，思路一是一种尝试。
 **/
struct ListNode
{
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

void print_list(ListNode *l);

/**
 * 方法 1，使用链表转化成数组，然后通过数组来排序,不推荐
 * */
int list_length(ListNode *l) //求链表长度
{
	int count = 0;
	while (l)
	{
		count++;
		l = l->next;
	}
	return count;
}

int *list_to_array(ListNode *l)
{
	int lenth = list_length(l);
	int *arrlist = new int[lenth];
	cout << lenth << endl;
	int i = 0;
	while (l)
	{
		arrlist[i++] = l->val;
		l = l->next;
	}
	return arrlist;
}

// 插入排序
void InsertSort(int *arr)
{
	for (int i = 1; i < 7; i++)
	{
		int key = arr[i];
		int j = i - 1;
		while (j >= 0 && arr[j] > key)
		{
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = key;
	}
}

/**
 * 方法 2，直接使用链表来排序,推荐做法，首先head节点给dummy
 * 然后在依次判断，temp节点和数组排序的时候一样，都是从head->next节点开始
 **/
ListNode *insertionSortList(ListNode *head)
{
	ListNode *dummy = new ListNode(-1);
	while (head)
	{
		ListNode *cur = dummy;
		ListNode *temp = head->next;
		//如果是cur第一次是空或者前面小于后面的，那么依次遍历
		while (cur->next != NULL && cur->next->val < head->val)
			cur = cur->next; // 满足条件，依次向后移动元素。
		head->next = cur->next;
		cur->next = head;
		head = temp;
	}
	return dummy->next;
}

/**
 * 方法 3，插入排序
*/
ListNode *insertionSortList3(ListNode *head)
{
	ListNode *dummy = new ListNode(-1);
	ListNode *p = head;
	while (p)
	{
		ListNode *cur = dummy, *temp = p->next;		  // 这里提前保存p->next这个位置，后面会覆盖
		while (cur->next && cur->next->val <= p->val) // 时候下一个链表的值小于当前值，那么就继续向后遍历
			cur = cur->next;
		p->next = cur->next; // 这里cur的下一个值就是大于p的值，p插入的位置就是在p和p->next之间
		cur->next = p;
		p = temp;
	}
	return dummy->next;
}

int main()
{
	ListNode *head = new ListNode(-1);
	ListNode *node2 = new ListNode(5);
	ListNode *node3 = new ListNode(3);
	ListNode *node4 = new ListNode(4);
	ListNode *node5 = new ListNode(0);
	head->next = node2;
	node2->next = node3;
	node3->next = node4;
	node4->next = node5;
	print_list(head);

	ListNode *p;
	p = insertionSortList3(head);
	print_list(p);
	return 0;
}

void print_list(ListNode *l)
{
	while (l)
	{
		cout << l->val << "->";
		l = l->next;
	}
	cout << "end" << endl;
}
