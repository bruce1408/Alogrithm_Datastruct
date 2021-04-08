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
 * 归并排序时间复杂度满足，递归写的话空间复杂度logn，非递归版本空间复杂度满足
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
 * 链表最底下的是一个节点一个区间，然后从下往上做，第一次迭代是长度为1的链表合并为长度为2
 * 的区间，然后继续合并。
*/
ListNode *split(ListNode *head, int n);
ListNode *merge(ListNode *l1, ListNode *l2, ListNode *head);
ListNode *sortList(ListNode *head)
{
    ListNode *dummy = new ListNode(-1), *cur = head;
    dummy->next = head;
    int cnt = 0; // 先求解链表长度
    while (cur)
    {
        cnt++;
        cur = cur->next;
    }
    cur = head;
    ListNode *left, *right, *tail;
    // 从长度为1的节点开始遍历
    for (int len = 1; len < cnt; len *= 2) // 从1开始，每次从下往上合并链表，然后step乘2
    {
        // 每一层头结点可能会变，用一个虚拟头结点
        cur = dummy->next;
        tail = dummy;
        while (cur)
        {
            left = cur;
            right = split(left, len);
            cur = split(right, len);
            tail = merge(left, right, tail);
        }
    }
    return dummy->next;
}

/**
 * 合并l1 和 l2，合并后的链表返回最后一个节点，因为下次合并要接在上次合并的链表的
 * 最后一个位置即可
 */
ListNode *merge(ListNode *l1, ListNode *l2, ListNode *head)
{
    if (!l1)
        head->next = l2;
    if (!l2)
        head->next = l1;
    ListNode *cur = head;
    while (l1 && l2)
    {
        if (l1->val < l2->val)
        {
            cur->next = l1, l1 = l1->next;
            cur = cur->next;
        }
        else
        {
            cur->next = l2, l2 = l2->next, cur = cur->next;
        }
    }
    l1 ? cur->next = l1 : cur->next = l2;
    while (cur->next)
        cur = cur->next;
    return cur;
}

/**
 * 传入一个head链表，和参数n，就是把这个链表的前n个链表拆分出来，返回拆分后面部分链表的最后一个节点
 * 例如 1 -> 2 -> 3 -> 4 -> 5 ->6->null ;n 选择 1 拆分，
 *     1 -> null,     2 -> 3 -> 4 -> 5 -> 6 -> null
 * 最后结果返回的是6，即第二个子链表的最后一个节点
 */
ListNode *split(ListNode *head, int n)
{
    for (int i = 1; i < n && head; i++)
    {
        head = head->next;
    }
    if (!head)
        return nullptr;
    ListNode *rear = head->next;
    head->next = nullptr;
    return rear;
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
 * 方法 3： 不用递归，归并排序满足时间要求，空间要求不满足
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
    // print_list(sortList(head));

    print_list(head);

    ListNode *cur = head;
    ListNode *left = split(cur, 1);
    print_list(left);
    print_list(split(left, 1));
    // print_list(split(head, 2));
    // print_list(split(head, 4));
}