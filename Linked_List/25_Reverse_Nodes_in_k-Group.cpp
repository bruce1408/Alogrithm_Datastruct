#include <iostream>
#include <stack>
#include <vector>
using namespace std;

/**
 * Example:
 * Given this linked list: 1->2->3->4->5
 * For k = 2, you should return: 2->1->4->3->5
 * For k = 3, you should return: 3->2->1->4->5
 * 反转链表中的n个节点。
*/
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

void print_list(struct ListNode *head)
{
    while (head)
    {
        cout << head->val << "->";
        head = head->next;
    }
    cout << "end" << endl;
}

/** 
 * 方法 1，翻转 k 个节点的链表。分两步，第一步，找翻转区间，第二步，在区间内翻转链表
 */
ListNode *reverseOneGroup(ListNode *pre, ListNode *last)
{
    ListNode *start = pre->next;
    ListNode *cur = start->next;
    while (cur != last)
    {
        start->next = cur->next;
        cur->next = pre->next;
        pre->next = cur;
        cur = start->next;
    }
    return start;
}

ListNode *reverseKGroup(ListNode *head, int k)
{
    if (!head || k == 1)
        return head;
    ListNode *dummy = new ListNode(-1), *pre = dummy;
    dummy->next = head;
    ListNode *cur = head;
    int i = 0;
    while (cur)
    {
        ++i;
        if (i % k == 0)
        {
            pre = reverseOneGroup(pre, cur->next); // 在这之间的节点都要翻转
            cur = pre->next;
        }
        else
            cur = cur->next;
    }

    return dummy->next;
}

/**
 * 方法 2，用一个函数。计算总长度，然后每次在k长度内进行翻转
*/
ListNode *reverseKGroup1(ListNode *head, int k)
{
    ListNode *dummy = new ListNode(-1), *pre = dummy;
    dummy->next = head;
    ListNode *cur = pre->next;
    int num = 0;
    while (cur && cur->next)
        ++num;
    while (num >= k)
    {
        cur = pre->next;
        for (int i = 1; i < k; ++i)
        {
            ListNode *t = cur->next;
            cur->next = t->next;
            t->next = pre->next;
            pre->next = t;
        }
        pre = cur;
        num -= k;
    }
    return dummy->next;
}
/**
 * 方法 3，使用cur
*/
ListNode *reverseKGroup3(ListNode *head, int k)
{
    ListNode *dummy = new ListNode(-1);
    dummy->next = head;
    ListNode *cur = head;
    int count = 1;
    while (cur)
    {
        ListNode *tmp = cur;
        ListNode *pre = tmp, *rear = NULL, *before = tmp;
        while (tmp && count <= k)
        {
            before = tmp;
            tmp = tmp->next;
            before->next = rear;
            rear = before;
            count += 1;
            pre = pre->next;
        }
        rear->next = pre;
        count = 1;
        cur = pre;
    }
    return dummy->next;
}
int main()
{
    ListNode head(1);
    ListNode a(2);
    ListNode b(3);
    ListNode c(4);
    ListNode d(5);
    head.next = &a;
    a.next = &b;
    b.next = &c;
    c.next = &d;
    ListNode *res = reverseKGroup3(&head, 3);
    print_list(res);
    return 0;
}
