#include <iostream>
#include <stack>
#include <vector>
using namespace std;
/**
 * 给一个链表，然后交换相邻的两个节点，返回的是它的头结点
 * 
 * Example:
 * Given 1->2->3->4, 
 * you should return the list as 2->1->4->3.
*/
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

/**
 * 方法 1，因为头结点会替换，所以使用新的头结点来做。
*/
ListNode *swapPairs1(ListNode *head)
{
    ListNode *dummy = new ListNode(-1), *cur = dummy;
    dummy->next = head;
    while (cur->next && cur->next->next)
    {
        ListNode *pre = cur->next->next;
        cur->next->next = pre->next;
        pre->next = cur->next;
        cur->next = pre;
        cur = pre->next;
    }
    return dummy->next;
}

/**
 * 方法 2，使用回溯的思想。使用递归到链表的末尾，然后交换末尾的两个
*/
ListNode *swapPairs2(ListNode *head)
{
    if (!head || !head->next)
        return head;
    ListNode *t = head->next;
    head->next = swapPairs2(head->next->next);
    t->next = head;
    return t;
}

int main()
{
    ListNode *head = new ListNode(1);
    ListNode *a = new ListNode(2);
    ListNode *b = new ListNode(3);
    ListNode *c = new ListNode(4);
    head->next = a;
    a->next = b;
    b->next = c;
    swapPairs1(head);
    return 0;
}
