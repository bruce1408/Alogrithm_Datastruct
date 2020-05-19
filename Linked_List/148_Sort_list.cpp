#include <iostream>
#include <vector>
#include <algorithm>
#include<cmath>
using namespace std;

/**
 * 给定一个无序的链表，然后对这个链表进行排序；
 * 综合题目，对一个链表排序，利用归并方法进行排序；
 * Input: 4->2->1->3
 * Output: 1->2->3->4
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
 * 方法一；递归且用归并排序
 */
ListNode *merge(ListNode *l1, ListNode *l2)
{
    if (!l1)
        return l2;
    if (!l2)
        return l1;
    if (l1->val < l2->val)
    {
        l1->next = merge(l1->next, l2);
        return l1;
    }
    else
    {
        l2->next = merge(l1, l2->next);
        return l2;
    }
}

ListNode *sortList(ListNode *head)
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
    return merge(sortList(head), sortList(slow));
}

/**
 * 方法二： 不用递归，归并排序
 */
ListNode *merge2(ListNode *l1, ListNode *l2)
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
ListNode *sortList2(ListNode *head)
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
    return merge2(sortList2(head), sortList2(mid));
}
/**
 * 方法 3，使用额外的空间，虽然不满足要求，还是写出来作为一种补充
*/
ListNode *sortList3(ListNode *head)
{
    ListNode *cur = head;
    vector<int> res;
    while (cur)
    {
        res.push_back(cur->val);
        cur = cur->next;
    }
    sort(res.begin(), res.end());
    cur = head;
    int i = 0;
    while (cur)
    {
        cur->val = res[i];
        i++;
        cur = cur->next;
    }
    return head;
}

int main()
{
    ListNode e1(0, nullptr);
    ListNode d1(4, &e1);
    ListNode c1(3, &d1);
    ListNode b1(5, &c1);
    ListNode a1(-1, &b1);
    ListNode *head = &a1;
    print_list(sortList3(head));
    cout << ceil(3.14) << endl;
}