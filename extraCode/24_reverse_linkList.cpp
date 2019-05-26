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


void print_list(ListNode* head)
{
	while(head)
	{
		cout<<head->val<<" ";
		head = head->next;
	}

}

// Iterative

ListNode* reverseList(ListNode* head) 
{
	if (!head) return head;
	ListNode *dummy = new ListNode(-1);
	dummy->next = head;
	ListNode *cur = head;
	while (cur->next)
	{
		ListNode *tmp = cur->next;
		cur->next = tmp->next;
		tmp->next = dummy->next;
		dummy->next = tmp;
	}
	return dummy->next;
}




int main()
{
	//create a linklist
	ListNode* head = new ListNode(1);
    ListNode* node2 = new ListNode(2);
    ListNode* node3 = new ListNode(3);
    ListNode* node4 = new ListNode(4);
    ListNode* node5 = new ListNode(5);
    ListNode* node6 = new ListNode(6);
    ListNode* node7 = new ListNode(7);

    head->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;
    node5->next = node6;
    node6->next = node7;

	ListNode* rehead = reverseList(head);
	print_list(rehead);



	return 0;
}
