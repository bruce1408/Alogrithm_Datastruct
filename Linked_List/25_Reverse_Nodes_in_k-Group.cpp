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

void print_list(ListNode *head)
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
 * 推荐此算法来解题
*/
ListNode *reverseKGroup1(ListNode *head, int k)
{
    ListNode *dummy = new ListNode(-1), *pre = dummy;
    dummy->next = head;
    ListNode *cur = pre->next;
    int num = 0;
    while (cur)
    {
        cur = cur->next;
        num += 1;
    }
    cout << num << endl;
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
        pre = cur; // 最关键的一步，头结点dummy=pre;然后移动pre来代替头结点即可；
        num -= k;
    }
    return dummy->next;
}

int main()
{
    ListNode *head = new ListNode(1);
    ListNode *a = new ListNode(2);
    ListNode *b = new ListNode(3);
    ListNode *c = new ListNode(4);
    ListNode *d = new ListNode(5);
    head->next = a;
    a->next = b;
    b->next = c;
    c->next = d;
    ListNode *res = reverseKGroup1(head, 3);
    print_list(res);
    return 0;
}
