#include <iostream>
using namespace std;
/**
 * Remove all elements from a linked list of integers that have value val.
 * Example:
 * Input:  1->2->6->3->4->5->6, val = 6
 * Output: 1->2->3->4->5
 * 删除一个符合条件的节点。
 * 有很多思路，我是用的是两个指针来做，这样效率很高！
 */
struct ListNode
{
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

void printf_list(ListNode *u);

/**
 * 方法 1,给一个前继节点
*/
ListNode *removeElements1(ListNode *head, int val)
{
	ListNode *dummy = new ListNode(-1);
	dummy->next = head;
	ListNode *pre = dummy;
	while (pre->next)
	{
		if (pre->next->val == val)
		{
			ListNode *tmp = pre->next;
			pre->next = pre->next->next;
			delete tmp;
		}
		else
			pre = pre->next;
	}
	return dummy->next;
}

/**
 * 方法 2，使用递归的方法, 写法很简洁，通过递归调用到链表末尾，然后回来，需要要删的元素，将链表next指针指向下一个元素即可：
*/
ListNode *removeElements2(ListNode *head, int val)
{
	if (!head)
		return NULL;
	head->next = removeElements2(head->next, val);
	return head->val == val ? head->next : head;
}

int main()
{
	ListNode *g1 = new ListNode(7);
	ListNode *f1 = new ListNode(6);
	ListNode *e1 = new ListNode(5);
	ListNode *d1 = new ListNode(4);
	ListNode *c1 = new ListNode(3);
	ListNode *b1 = new ListNode(6);
	ListNode *a1 = new ListNode(1);

	ListNode *head = a1;
	a1->next = b1;
	b1->next = c1;
	c1->next = d1;
	d1->next = e1;
	e1->next = f1;
	f1->next = g1;
	ListNode *before = head;
	printf_list(head);
	before = removeElements1(head, 6);
	//打印出链表的值
	printf_list(head);
	return 0;
}

void printf_list(ListNode *u) //输出链表的函数
{
	while (u)
	{
		cout << u->val << "->";
		u = u->next;
	}
	cout << "end" << endl;
}
