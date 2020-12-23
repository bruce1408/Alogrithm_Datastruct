#include <iostream>
#include <vector>
using namespace std;

/**
 * Merge two sorted linked lists and return it as a new list.
 * The new list should be made by splicing together the nodes of the first two lists.
 * 
 * Example:
 * Input: 1->2->4, 1->3->4
 * Output: 1->1->2->3->4->4
 * 
 * 给定两个升序排列的链表，然后他们合并成一个新的升序排列的链表即可；
*/
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

/**
 * 打印链表函数
*/
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
 * 方法 1：递归方法，每次比较大小，把小的和剩余的链表拿来再次比较，
 * */
ListNode *mergeTwoLists1(ListNode *l1, ListNode *l2)
{
    if (!l1 || !l2)
        return l1 ? l1 : l2;
    if (l1->val < l2->val)
    {
        l1->next = mergeTwoLists1(l1->next, l2);
        return l1;
    }
    else
    {
        l2->next = mergeTwoLists1(l1, l2->next);
        return l2;
    }
}

/**
 * 方法 2，不用递归，依次比较两个链表的大小，注意这里的头结点有两种写法，一种是指针
 * 还有一种是非头指针的写法，方法 2是用非头指针的写法。
 */
ListNode *mergeTwoLists2(ListNode *l1, ListNode *l2)
{
    if (!l1 || !l2)
        return l1 ? l1 : l2;
    ListNode dummy(0);
    // 如果是这行语句的话，那么就返回的是dummy->next
    // ListNode *dummy = new ListNode(0);
    ListNode *cur = &dummy;
    while (l1 && l2)
    {
        if (l1->val < l2->val)
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
    if (l1)
        cur->next = l1;
    if (l2)
        cur->next = l2;
    return dummy.next; // 这里注意如果dummy不是指针的话，那么next应该是点，不是->，它只是普通的节点
}

/**
 * 方法 3，二路归并递归算法。
*/
ListNode *mergeTwoLists3(ListNode *l1, ListNode *l2)
{
    if (!l1)
        return l2;
    if (!l2)
        return l1;
    ListNode *head = l1->val < l2->val ? l1 : l2;
    ListNode *nonhead = l1->val < l2->val ? l2 : l1;
    head->next = mergeTwoLists3(head->next, nonhead);
    return head;
}

int main()
{
    // 链表 1生成过程
    ListNode *c1 = new ListNode(4);
    ListNode *b1 = new ListNode(3);
    ListNode *a1 = new ListNode(1);
    ListNode *head1 = a1;
    a1->next = b1;
    b1->next = c1;

    // 链表 2生成过程
    ListNode *c2 = new ListNode(4);
    ListNode *b2 = new ListNode(2);
    ListNode *a2 = new ListNode(1);
    ListNode *head2 = a2;
    a2->next = b2;
    b2->next = c2;

    print_list(head1);
    print_list(head2);

    ListNode *before = mergeTwoLists3(head1, head2);
    print_list(before);
    return 0;
}
