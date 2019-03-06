#include<iostream>
#include<vector>
using namespace std;


/** merge two sorted Linkedlist
 * 方法一：递归方法，每次比较大小，把小的和剩余的链表拿来再次比较，
 * */
struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x):val(x),next(nullptr){}
};
// 递归方法简介。
ListNode* mergeTwoLists(ListNode* l1, ListNode* l2)
{
    if(!l1||!l2) return l1?l1:l2;
    if(l1->val < l2->val)
    {
        l1->next = mergeTwoLists(l1->next, l2);
        return l1;
    }
    else
    {
        l2->next = mergeTwoLists(l1, l2->next);
        return l2;
    }
}

// 方法二,不用递归，依次比较两个链表的大小
ListNode * mergeTwoLists2(ListNode* l1, ListNode* l2)
{
    if(!l1 || !l2) return l1?l1:l2;
    ListNode dummy(0);
    ListNode *cur = &dummy;
    while(l1&&l2)
    {
        if(l1->val<l2->val)
        {
            cur->next = l1;
            l1 = l1->next;
        }
        else
        {
            cur->next = l2;
            l2 = l2->next;
        }
        cur = cur->next;
    }
    if(l1) cur->next = l1;
    if(l2) cur->next = l2;
    return dummy.next; // 这里注意是点，不是->，原因是dummy不是指针，而是普通的节点
}


// 20190306
class Solution
{
    public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2)
    {
        if(!l1|| !l2) return l1?l1:l2; // 有一个是空的情况下怎么操作。
        ListNode * dummy = NULL;
        ListNode * cur = dummy;
        while(l1 && l2)
        {
            if(l1->val > l2->val)
            {
                cur->next = l1; 
                l1 = l1->next;
            }
            else
            {
                cur->next = l2;
                l2 = l2->next;
            }
            cur = cur->next;
        }
        if(l1) cur->next = l1;
        if(l2) cur->next = l2;
        return dummy->next;
    }
}

