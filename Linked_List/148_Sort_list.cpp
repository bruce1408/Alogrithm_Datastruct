#include<iostream>
using namespace std;


// 综合题目，对一个链表排序，利用归并方法进行排序；
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x):val(x),next(nullptr){}
    ListNode(int x, ListNode* next_):val(x),next(next_){}
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
// 方法一；递归且用归并排序
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


// 方法二： 不用递归，归并排序

ListNode *merge2(ListNode*l1, ListNode *l2)
{
    if(!l1) return l2;
    if(!l2) return l1;
    ListNode *dummy = new ListNode(0);
    ListNode *tail = dummy;
    while(l1 && l2)
    {
        if(l1->val < l2->val)
        {
            tail->next = l1;
            l1 = l1->next;
        }
        else
        {
            tail->next = l2;
            l2 = l2->next;
        }
        tail = tail->next;
    }
    if(l1||l2) l1?tail->next = l1:tail->next = l2;

    return dummy->next;
}
ListNode*sortList2(ListNode*head)
{
    if(head==nullptr || head->next==nullptr) return head;
    ListNode *slow = head;
    ListNode *fast = head->next;
    while(fast && fast->next)
    {
        fast = fast->next->next;
        slow = slow->next;
    }
    ListNode *mid = slow->next;
    slow->next = nullptr;
    print_list(head);
    print_list(mid);
    return merge2(sortList2(head), sortList2(mid));

}
int main()
{
	ListNode e1(0,nullptr);
	ListNode d1(4,&e1);
	ListNode c1(3,&d1);
	ListNode b1(5,&c1);
	ListNode a1(-1,&b1);
	ListNode *head = &a1;
    print_list(sortList2(head));
}