#include <iostream>
#include <vector>
using namespace std;

/**
 * 这道题是把所有的奇数节点放到前面，偶数节点放到后面去。
 * */
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
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
 * 方法 1，两个指针，一个是指向偶数节点，一个指向奇数节点，把偶数节点后面的奇数节点提前到第一个奇数的后面。
 * 然后两个指针各前进一步即可
 * */
ListNode *oddEvenList(ListNode *head)
{
    if (head == nullptr || head->next == nullptr)
        return head;
    ListNode *cur = head->next;
    ListNode *pre = head;
    while (cur && cur->next)
    {
        ListNode *temp = pre->next;
        pre->next = cur->next;
        cur->next = cur->next->next;
        pre->next->next = temp;
        cur = cur->next;
        pre = pre->next;
    }
    return head;
}

/**
 * 方法 2，使用两个指针分别保存奇数和偶数下标的链表
 * 最后把这两个链表合并即可，注意在偶数链表保存的时候要记录偶数的头指针
*/
ListNode *oddEvenList(ListNode *head)
{
    if (!head || !head->next)
        return head;
    ListNode *odd = head, *evn = head->next, *evnhead = evn;
    ListNode *cur = head;
    while (odd->next && evn->next)
    {
        odd->next = evn->next;
        odd = odd->next;

        evn->next = odd->next;
        evn = evn->next;
    }
    odd->next = evnhead;
    return head;
}

int main()
{
    ListNode *head = new ListNode(2);
    ListNode *node2 = new ListNode(1);
    ListNode *node3 = new ListNode(3);
    ListNode *node4 = new ListNode(5);
    ListNode *node5 = new ListNode(6);
    ListNode *node6 = new ListNode(4);
    ListNode *node7 = new ListNode(7);
    head->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;
    node5->next = node6;
    node6->next = node7;
    print_list(oddEvenList(head));
    delete head;
    delete node2;
    delete node3;
    delete node4;
    delete node5;
    delete node6;
    delete node7;
    return 0;
}
