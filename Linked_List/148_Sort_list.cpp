#include<iostream>
using namespace std;


struct ListNode
{
    int val;
    ListNode *next;
    // ListNode(int x):val(x),next(nullptr){}
    // ListNode(int x, ListNode* next_):val(x),next(next_){}
};


void print_list(struct ListNode *head)
{
	while(head)
	{
		cout<<head->val<<"->";
		head = head->next;
	}
	cout<<"end"<<endl;
}


ListNode * merge(ListNode *l1, ListNode *l2)
{
    if(!l1) return l2;
    if(!l2) return l1;
    if(l1->val<l2->val)
    {
        l1->next = merge(l1->next, l2);
        return l1;
    }
    else
    {
        l2->next = merge(l1,l2->next);
        return l2;
    }
}
ListNode * sortList(ListNode * head)
{
    if(head==nullptr|| head->next==nullptr) return head;
    ListNode *slow = head;
    ListNode *fast = head;
    ListNode *pre = head;
    while(fast && fast->next)
    {
        pre = slow;
        slow = slow->next;
        fast = fast->next->next;
    }
    pre->next = nullptr;
    return merge(sortList(head),sortList(slow));
}

int main()
{
	ListNode e1 = {0,nullptr};
	ListNode d1 = {4,&e1};
	ListNode c1 = {3,&d1};
	ListNode b1 = {5,&c1};
	ListNode a1 = {-1,&b1};
	ListNode *head = &a1;
    print_list(sortList(head));
}