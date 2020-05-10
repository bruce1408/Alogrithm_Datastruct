#include <iostream>
#include <cstring>
using namespace std;

/**
 * Input: 1->2->3->3->4->4->5
 * Output: 1->2->5
 * 删除一个单链表的重复节点,只要是重复的都删除；
 * 1->1->1->2->3->4
 * 2->3->4
*/

struct ListNode
{
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
void print_list(struct ListNode *head);

/**
 * 方法 1，使用两层while循环判断。
 */
ListNode *deleteDuplicates(ListNode *head)
{
	if (!head || !head->next)
		return head;
	ListNode *start = new ListNode(-1);
	start->next = head;
	ListNode *pre = start;
	while (pre->next)
	{
		ListNode *cur = pre->next;
		while (cur->next && cur->next->val == cur->val)
			cur = cur->next;
		if (cur != pre->next)
			pre->next = cur->next;
		else
			pre = pre->next;
	}
	return start->next;
}

/**
 * 方法 2，使用的是逻辑算法，两层while循环，如果找到相同的节点，
 * 那么进入第二层while循环，判断到底是有多少个相同的节点，然后开始把这些节点删除即可。但是发现超时了！=_=
 */
ListNode *deleteDuplicates2(ListNode *head)
{
	ListNode *cur = head, *pre = head;
	ListNode *dummy = new ListNode(-1);
	ListNode *before = dummy;
	dummy->next = head;
	while (cur && cur->next)
	{
		pre = cur->next;
		if (cur->val == pre->val)
		{
			ListNode *tmp = pre->next;
			while (tmp)
			{
				if (cur->val == tmp->val)
				{
					tmp = tmp->next;
				}
				else
				{
					before->next = tmp;
					cur = tmp;
					break;
				}
			}
		}
		else
		{
			before = cur;
			cur = cur->next;
		}
	}
	return dummy->next;
}

int main()
{
	ListNode *head = new ListNode(1);
	ListNode *node2 = new ListNode(1);
	ListNode *node3 = new ListNode(4);
	ListNode *node4 = new ListNode(4);
	ListNode *node5 = new ListNode(5);
	ListNode *node6 = new ListNode(6);
	ListNode *node7 = new ListNode(7);

	head->next = node2;
	node2->next = node3;
	node3->next = node4;
	node4->next = node5;
	node5->next = node6;
	node6->next = node7;
	print_list(head);
	print_list(deleteDuplicates2(head));
	return 0;
}

void print_list(struct ListNode *head)
{
	while (head)
	{
		cout << head->val << "->";
		head = head->next;
	}
	cout << "end" << endl;
}