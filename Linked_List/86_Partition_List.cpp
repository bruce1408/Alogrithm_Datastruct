/**
 * 就是将所有小于给定值的节点取出组成一个新的链表，此时原链表中剩余的节点的值都大于或等于给定值，
 * 只要将原链表直接接在新链表后即可，代码如下：
 * Original: 4 -> 3 -> 5 -> 2 
 * New:　  1 -> 2
 * Original: 4 -> 3 -> 5 
 * New:　  1 -> 2 -> 2
 * Original: 
 * New:　  1 -> 2 -> 2 -> 4 -> 3 -> 5
 * */
#include<iostream>
#include<vector>
using namespace std;


struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x):val(x),next(NULL){}
}; 

ListNode* partition(ListNode* head, int x)
{
    ListNode *dummy = new ListNode(-1);
    ListNode *newdummy = new ListNode(-1);
    dummy->next = head;
    ListNode *pre = dummy;
    ListNode *cur = newdummy;
    while(pre->next)
    {
        if(pre->next->val<x)
        {
            cur->next = pre->next;
            cur = cur->next;
            pre->next = pre->next->next;
            cur->next = nullptr;
        }
        else
        {
            pre = pre->next;
        }
    }
    cur->next = dummy->next;
    return newdummy->next;
}

void print_list(struct ListNode *head);

int main()
{
	
	ListNode *e = new ListNode(5);
	ListNode *d = new ListNode(2);
	ListNode *c = new ListNode(3);
	ListNode *b = new ListNode(4);
	ListNode *a = new ListNode(1);
	a->next = b;
	b->next = c;
	c->next = d;
	d->next = e;
	
	
	// print_list(head);
    print_list(partition(a, 3));

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