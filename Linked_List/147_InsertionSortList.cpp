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
	int i, j, key;
	for (i = 1; i < 7; i++)
	{
		key = arr[i];
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
 * 方法 2，直接使用链表来排序
 **/
ListNode *insertionSortList(ListNode *head)
{
	ListNode *sortHead = new ListNode(-1);
	while (head)
	{
		ListNode *cur = sortHead;
		ListNode *temp = head->next;
		//如果是cur第一次是空或者前面小于后面的，那么依次遍历
		while (cur->next != NULL && cur->next->val < head->val)
		{
			cur = cur->next; // 满足条件，依次向后移动元素。
		}
		head->next = cur->next;
		cur->next = head;
		head = temp;
	}
	return sortHead->next;
}

int main()
{
	ListNode *head = new ListNode(1);
	ListNode *node2 = new ListNode(2);
	ListNode *node3 = new ListNode(3);
	ListNode *node4 = new ListNode(4);
	ListNode *node5 = new ListNode(3);
	ListNode *node6 = new ListNode(2);
	ListNode *node7 = new ListNode(1);
	head->next = node2;
	node2->next = node3;
	node3->next = node4;
	node4->next = node5;
	node5->next = node6;
	node6->next = node7;
	print_list(head);

	ListNode *p;
	p = insertionSortList(head);
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
