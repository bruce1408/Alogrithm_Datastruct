#include <iostream>
using namespace std;

/**
 * Given a linked list, remove the n-th node from the end of list and return its head.
 * 
 * 给定一个单链表，从尾部开始删除第N个节点的链表，然后返回head
 * 比如 Given linked list: 1->2->3->4->5, and n = 2.
*/
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
/**
 * 方法 1，使用两个指针，快指针先走n步之后，然后判断快指针是不是为空
 * 如果是空的话，那么就说明倒数第n个节点其实是首元素，移除首元素，返回head->next即可
 * 如果不是空的话，那么慢指针从头开始，快指针和快指针都往后遍历知道结束，最后删除慢指针的节点
 * 返回头结点即可；
*/
ListNode *removeNthFromEnd(ListNode *head, int n)
{
    if (!head->next)
        return nullptr;
    ListNode *p = head;
    ListNode *q = head;
    for (int i = 0; i < n; ++i)
        q = q->next;
    cout << q->val << endl;
    if (!q)
        return head->next;
    while (q->next)
    {
        q = q->next;
        p = p->next;
        cout << "the p val is: " << p->val << endl;
    }
    p->next = p->next->next;
    return head;
}
/**
 * 方法 2，先求出所有长度，然后删除第k个点，就是从前往后遍历。
*/
ListNode *removeNthFromEnd1(ListNode *head, int n)
{
    ListNode *dummy = new ListNode(-1);
    dummy->next = head;
    ListNode *cur = dummy;
    int len = 0;
    for (auto p = head; p; p = p->next)
        len++;

    for (int i = 0; i < len - n; i++)
    {
        cur = cur->next;
    }
    cur->next = cur->next->next;
    // cout << len << endl;
    return dummy->next;
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
    // print_list(removeNthFromEnd(head,5));
    print_list(removeNthFromEnd1(head, 2));

    return 0;
}