#include <iostream>
#include <stack>
using namespace std;
/**
 * 反转链表II
 * 给定一个区间，然后该区间内的数字进行
 * 链表的翻转，然后返回即可
 * 这里还是使用两个节点来进行翻转链表，最后判断前后
 * 指向的关系即可
*/
struct ListNode
{
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
/**
 * 方法 1，和方法 2思路一样，写法略有不同
*/
ListNode *reverseBetween(ListNode *head, int m, int n)
{
	ListNode *dummy = new ListNode(-1);
	dummy->next = head;
	ListNode *cur = dummy;
	ListNode *pre, *front, *last;
	for (int i = 1; i <= m - 1; ++i)
		cur = cur->next;
	pre = cur;
	last = cur->next;
	for (int i = m; i <= n; ++i)
	{
		cur = pre->next;
		pre->next = cur->next;
		cur->next = front;
		front = cur;
	}
	cur = pre->next;
	pre->next = front;
	last->next = cur;
	return dummy->next;
}

/**
 * 方法 2，翻转区间链表
 * 先从虚拟头结点跳m-1次到达翻转的前一个节点；
 * 然后再用两个指针来进行反转
*/
ListNode *reverseBetween(ListNode *head, int m, int n)
{
	if (!head || n == m == 1)
		return head;
	ListNode *dummy = new ListNode(-1), *cur = head;
	dummy->next = head;
	int len = 0, k = n - m;
	// get linklist length
	while (cur)
	{
		len++;
		cur = cur->next;
	}
	cur = dummy;
	for (int i = 0; i < m - 1; i++)
		cur = cur->next;
	ListNode *a = cur->next, *b = a->next;
	while (k-- && b) // 循环n-m=k次，进行反转
	{
		ListNode *c = b->next;
		b->next = a;
		a = b;
		b = c;
	}
	// 上面的写法就是判断b是否存在，但是使用auto就不用判断b
	// 写法如下
	while (k--)
	{
		auto c = b->next;
		b->next = c;
		a = b;
		b = c;
	}
	ListNode *q = cur->next;
	cur->next = a;
	q->next = b;
	return dummy->next;
}

int main()
{
	ListNode *e = new ListNode(5);
	ListNode *d = new ListNode(4);
	ListNode *c = new ListNode(3);
	ListNode *b = new ListNode(2);
	ListNode *a = new ListNode(1);
	ListNode *head = a;
	a->next = b;
	b->next = c;
	c->next = d;
	d->next = e;

	ListNode *p;

	p = reverseBetween(head, 2, 4);
	while (p != NULL)
	{
		cout << p->val;
		cout << " ";
		p = p->next;
	}
	cout << endl;

	return 0;
}