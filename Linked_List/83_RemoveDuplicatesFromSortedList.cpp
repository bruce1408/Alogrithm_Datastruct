#include<iostream>
#include<vector>
using namespace std;

/**
 * Given a sorted linked list, delete all duplicates such that each element appear only once.
 * Example 1:
 * Input: 1->1->2
 * Output: 1->2
 * 
 * 已经排好序的链表去重，就两句话，如果比较当前节点和下一节点的数值相同的话，
 * 那么，让下下节点指向当前节点，否则，继续向后移动节点，继续判断当前节点和下一节点不为空；*/

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x):val(x),next(NULL){}
}; 

/**
 * 方法 1，
*/
void print_list(struct ListNode *head);

ListNode *deleteDuplicates1(ListNode *head)
{
	ListNode *p = head;
	while(p&&p->next)
	{
		if(p->next->val == p->val)
		{
			p->next = p->next->next;
		}
		else
		{
			p = p->next;
		}
	}
	return head;
}


// 方法二；
ListNode* deleteDuplicates2(ListNode*head)
{
	if (!head || !head->next) return head;
	
	ListNode *start = head;
	while (start && start->next) 
	{
		if (start->val == start->next->val) 
		{
			ListNode *tmp = start->next;
			start->next = start->next->next;
			delete tmp;
		} else start = start->next;
	}
	return head;
}

int main()
{
	ListNode *e = new ListNode(3);
	ListNode *d = new ListNode(3);
	ListNode *c = new ListNode(2);
	ListNode *b = new ListNode(1);
	ListNode *a = new ListNode(1);
	ListNode *head = a;
	a->next = b;
	b->next = c;
	c->next = d;
	d->next = e;
	ListNode *before = head;
	print_list(head);
	print_list(deleteDuplicates1(before));
	return 0;
	
}


void print_list(struct ListNode *head)
{
	while(head)
	{
		cout<<head->val<<"->";
		head = head->next;
	}
	cout<<"end"<<endl;
}