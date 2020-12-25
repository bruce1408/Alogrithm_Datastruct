#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

/**
 * 给定一个无序的链表，然后对这个链表进行排序；
 * 综合题目，对一个链表排序，利用归并方法进行排序；
 * Input: 4->2->1->3
 * Output: 1->2->3->4
 * 快速排序时间复杂度满足，但是空间复杂度不满足
 * 归并排序时间复杂度满足，非递归版本空间复杂度满足
 * 因此选择归并非递归做法
 * */
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next_) : val(x), next(next_) {}
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
 * 方法 1， 使用自底向上策略,空间复杂度O(1)，时间复杂度O(NlgN)
*/
// 函数声明
ListNode *split(ListNode *head, int n);
ListNode *merge(ListNode *l1, ListNode *l2, ListNode *head);
ListNode *sortList(ListNode *head)
{
    if (!head || !(head->next))
        return head;

    //get the linked list's length
    ListNode *cur = head;
    int length = 0;
    while (cur)
    {
        length++;
        cur = cur->next;
    }

    ListNode *dummy = new ListNode(0);
    dummy->next = head;
    ListNode *left, *right, *tail;
    for (int step = 1; step < length; step <<= 1)
    {
        cur = dummy->next;
        tail = dummy;
        while (cur)
        {
            left = cur;
            right = split(left, step);
            cur = split(right, step);
            tail = merge(left, right, tail);
        }
    }
    return dummy->next;
}

/**
 * Divide the linked list into two lists,
 * while the first list contains first n nodes
 * return the second list's head
 */
ListNode *split(ListNode *head, int n)
{
    //if(!head) return NULL;
    for (int i = 1; head && i < n; i++)
        head = head->next;

    if (!head)
        return NULL;
    ListNode *second = head->next;
    head->next = NULL;
    return second;
}
/**
     * merge the two sorted linked list l1 and l2,
     * then append the merged sorted linked list to the node head
     * return the tail of the merged sorted linked list
 */
ListNode *merge(ListNode *l1, ListNode *l2, ListNode *head)
{
    ListNode *cur = head;
    while (l1 && l2)
    {
        if (l1->val > l2->val)
        {
            cur->next = l2;
            cur = l2;
            l2 = l2->next;
        }
        else
        {
            cur->next = l1;
            cur = l1;
            l1 = l1->next;
        }
    }
    cur->next = (l1 ? l1 : l2);
    while (cur->next)
        cur = cur->next;
    return cur;
}

/**
 * 方法 2；归并排序，递归解法不满足空间要求
 */
ListNode *merge2(ListNode *l1, ListNode *l2)
{
    if (!l1)
        return l2;
    if (!l2)
        return l1;
    if (l1->val < l2->val)
    {
        l1->next = merge2(l1->next, l2);
        return l1;
    }
    else
    {
        l2->next = merge2(l1, l2->next);
        return l2;
    }
}

ListNode *sortList2(ListNode *head)
{
    if (head == nullptr || head->next == nullptr)
        return head;
    ListNode *slow = head;
    ListNode *fast = head; // 不用fast为head的下一个节点。因为设了pre节点。
    ListNode *pre = head;
    while (fast && fast->next)
    {
        pre = slow; // pre就是slow的前一个节点
        slow = slow->next;
        fast = fast->next->next;
    }
    pre->next = nullptr;
    return merge2(sortList2(head), sortList2(slow));
}

/**
 * 方法 3： 不用递归，归并排序满足时间要去，空间要求不满足
 */
ListNode *merge3(ListNode *l1, ListNode *l2)
{
    if (!l1)
        return l2;
    if (!l2)
        return l1;
    ListNode *dummy = new ListNode(0);
    ListNode *tail = dummy;
    while (l1 && l2)
    {
        if (l1->val < l2->val)
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
    if (l1 || l2)
        l1 ? tail->next = l1 : tail->next = l2;

    return dummy->next;
}

ListNode *sortList3(ListNode *head)
{
    if (head == nullptr || head->next == nullptr)
        return head;
    ListNode *slow = head;
    ListNode *fast = head->next; // 这里要从head的下一个开始才能断开。
    while (fast && fast->next)
    {
        fast = fast->next->next;
        slow = slow->next;
    }
    ListNode *mid = slow->next;
    slow->next = nullptr;
    print_list(head);
    print_list(mid);
    return merge3(sortList3(head), sortList3(mid));
}

int main()
{
    ListNode e1(0, nullptr);
    ListNode d1(4, &e1);
    ListNode c1(3, &d1);
    ListNode b1(5, &c1);
    ListNode a1(-1, &b1);
    ListNode *head = &a1;
    print_list(sortList(head));
}