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

// 正确的版本；
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

void print_list(struct ListNode *head)
{
	while (head)
	{
		cout << head->val << "->";
		head = head->next;
	}
	cout << "end" << endl;
}

// 自己写错的版本。里面还应该嵌套一个while循环
ListNode *deleteDuplicate(ListNode *head)
{
	ListNode *dummy = new ListNode(-1);
	ListNode *pre = head, *cur = head;
	dummy->next = head;
	while (pre->next)
	{
		if (cur->next->val == pre->val) // 这个错犯了好几次
		{
			cout << "next one is: " << cur->next->val << endl;
			cur = cur->next;
		}
		if (pre != cur)
		{
			dummy->next = cur->next;
		}
		else
			pre = pre->next;
	}
	dummy->next = pre;
	return dummy->next;
}

ListNode* deleteDuplicates2(ListNode* head)
{
	ListNode *cur = head;
	ListNode * dummy = new ListNode(-1);
	dummy->next = head;
	
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

	// ListNode* p = deleteDuplicate(head);
	// while(p)
	// {
	// 	cout<<p->val<<" ";
	// 	p = p->next;
	// }
	// cout<<endl;
	print_list(deleteDuplicates(head));
	return 0;
}
