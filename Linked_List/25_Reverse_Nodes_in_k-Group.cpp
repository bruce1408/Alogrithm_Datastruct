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
 * 方法 1，翻转 k 个节点的链表。
 * 分两步，第一步，找翻转区间，第二步，在区间内翻转链表
 * 主要看方法 2-3
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
 * 推荐此算法来解题,这里需要3个指针节点来进行
 * dummy -> 1 -> 2 -> 3 -> 4 -> 5
 *   pre    a    b
 * 三个节点，pre, a, b,每次翻转结束之后再把pre放到翻转的前一个点
 * 就是 pre = 1, a = 4, b = 5
*/
ListNode *reverseKGroup1(ListNode *head, int k)
{
    ListNode *dummy = new ListNode(-1), *pre = dummy;
    dummy->next = head;
    ListNode *a = pre->next;
    int num = 0;
    while (a)
    {
        a = a->next;
        num += 1;
    }
    cout << num << endl;
    while (num >= k)
    {
        a = pre->next;
        for (int i = 1; i < k; ++i)
        {
            ListNode *b = a->next;
            a->next = b->next;
            b->next = pre->next;
            pre->next = b;
        }
        pre = a; // 最关键的一步，头结点dummy=pre;然后移动pre来代替头结点即可；
        num -= k;
    }
    return dummy->next;
}

/**
 * 方法 3，和方法 2思路都是一样的，就是翻转部分不一样，参考链表翻转的算法
 * 最好画图容易理解
*/
ListNode *reverseKGroup3(ListNode *head, int k)
{
    ListNode *dummy = new ListNode(-1);
    // ListNode *p = dummy;
    dummy->next = head;
    for (auto p = dummy;;)
    {
        ListNode *q = p;
        for (int i = 0; i < k && q; i++)
            q = q->next; // 遍历q，如果小于k且q存在的情况
        if (!q)          // 如果q不存在是空，那么直接退出
            break;
        ListNode *a = p->next, *b = a->next;
        for (int i = 0; i < k - 1; i++)
        {
            ListNode *c = b->next;
            b->next = a;
            a = b;
            b = c;
        }
        // 遍历结束之后还要对这个翻转的链表的头尾做处理
        ListNode *c = p->next; // 把p->next 保存再来，然后下次从c开始作为新的p翻转
        p->next = a;
        c->next = b;
        p = c;
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
