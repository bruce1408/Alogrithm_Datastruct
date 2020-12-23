#include <iostream>
#include <vector>
using namespace std;
/**
 * 就是将所有小于给定值的节点取出组成一个新的链表，
 * 此时原链表中剩余的节点的值都大于或等于给定值，
 * 只要将原链表直接接在新链表后即可，代码如下：
 * Original: 4 -> 3 -> 5 -> 2 
 * New:　  1 -> 2
 * Original: 4 -> 3 -> 5 
 * New:　  1 -> 2 -> 2
 * Original: 
 * New:　  1 -> 2 -> 2 -> 4 -> 3 -> 5
 * */

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

/**
 * 方法 1，
 * 使用两个虚拟头结点，然后小于x的放第一个，大于等于x的节点放第二个，
 * 最后把两个节点合并起来就可以了，注意最后要加上末尾的节点为空NULL
*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode *partition(ListNode *head, int x)
{
    if (!head)
        return head;
    ListNode *left = new ListNode(-1), *curL = left;
    ListNode *right = new ListNode(-2), *curR = right;
    ListNode *cur = head;
    while (cur)
    {
        if (cur->val < x)
        {
            curL->next = cur;
            curL = curL->next;
        }
        else
        {
            curR->next = cur;
            curR = curR->next;
        }
        cur = cur->next;
    }
    curL->next = right->next;
    curR->next = NULL;
    return left->next;
}

void print_list(struct ListNode *head);

int main()
{
    ListNode *e = new ListNode(5);
    ListNode *d = new ListNode(2);
    ListNode *c = new ListNode(3);
    ListNode *b = new ListNode(4);
    ListNode *a = new ListNode(1);
    a->next = b;
    b->next = c;
    c->next = d;
    d->next = e;
    // print_list(head);
    print_list(partition(a, 3));
    return 0;
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