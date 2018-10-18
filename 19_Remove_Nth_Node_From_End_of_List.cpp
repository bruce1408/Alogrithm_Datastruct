#include<iostream>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode (int x):val(x),next(NULL) {}
} ;

ListNode* removeNthFromEnd(ListNode* head, int n) 
{
    if(!head->next) return nullptr;
    ListNode *p = head;
    ListNode *q = head;
     for (int i = 0; i < n; ++i) q = q->next;
        if (!q) return head->next;
    while(q->next)
    {
        p = p->next;
        q = p->next;
    }
    p->next = p->next->next;
    return head;
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

int main()
{

    ListNode *a1 = new ListNode(1);   
    ListNode *a2 = new ListNode(2);   
    ListNode *a3 = new ListNode(3);   
    ListNode *a4 = new ListNode(4);   
    ListNode *a5 = new ListNode(5);
    ListNode *head = a1;
    a1->next = a2;   
    a2->next = a3;   
    a3->next = a4;   
    a4->next = a5;   
    print_list(removeNthFromEnd(head,5));

    return 0;

}