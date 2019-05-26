#include<iostream>
#include<string>
#include<stack>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x):val(x),next(NULL){}
};


//非递归算法
ListNode*merge1(ListNode*head1,ListNode*head2)
{
	if(head1==nullptr)
		return head2;
	else if(head2==nullptr)
		return head1;
	
	ListNode* start = new ListNode(-1);
	ListNode* cur = start;
	while(head1 && head2)
	{
		
		if(head1->val < head2->val)
		{
			cur->next = head1;
			head1 = head1->next;
		}
		else 
		{
			cur->next = head2;
			head2 = head2->next;
		}
		cur = cur->next;
		
	}
	// start->next = head1?head1 : head2;
	if(head1)
		cur->next = head1;
	else
		cur->next = head2;
	return start->next;
}


//递归算法
ListNode*merge(ListNode*head1,ListNode*head2)
{
	if(head1==nullptr)
		return head2;
	else if(head2==nullptr)
		return head1;
	
	ListNode* start = nullptr;
	
	if(head1->val < head2->val)
	{
		start= head1;
		start->next = merge(head1->next,head2);
	}
	
	else
	{
		start = head2;
		start->next = merge(head1,head2->next);
	}
	return start;
}

int main()
{
	//create a linklist
	ListNode* head1 = new ListNode(1);
    ListNode* node2 = new ListNode(2);
    ListNode* node3 = new ListNode(3);
    ListNode* node4 = new ListNode(4);
	
    ListNode* head2 = new ListNode(3);
    ListNode* node6 = new ListNode(5);
    ListNode* node7 = new ListNode(7);
	
    head1->next = node2;
    node2->next = node3;
    node3->next = node4;
	
    head2->next = node6;
    node6->next = node7;
	
	//测试
	ListNode*p;
	p = merge1(head1,head2);
	while(p)
	{
		cout<<p->val<<" ";
		p = p->next;
	}
	
	
	
}