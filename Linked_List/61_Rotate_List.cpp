#include <iostream>
using namespace std;
/**
 * 61 旋转链表
 * 思路就是构成环，不用加一个哑结点，直接循环技术即可。
 * */
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

/**
 * 方法 1，使用两个节点来记录最后一个节点和倒数第二个节点，倒数第二个
 * 节点用来最后设置空节点，最后一个节点用来插入到头部位置
 * 但是在200000000次旋转的时候超时了
*/
ListNode *rotateRight1(ListNode *head, int k)
{
    // 空链表，返回自身
    if (head == nullptr)
        return head;
    ListNode *cur = head;
    int cnt = 0;
    // 获得链表的总长度
    while (cur)
    {
        cnt++;
        cur = cur->next;
    }
    // 链表长度是1，那么返回自身
    if (cnt == 1)
        return head;
    ListNode *dummy = new ListNode(-1);
    dummy->next = head;
    for (int i = 0; i < k; i++)
    {
        ListNode *slow = head;
        ListNode *fast = head->next;
        // 每次旋转的时候都找都最后两个链表节点方便进行反转和插入
        while (fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next;
        }
        ListNode *p = dummy->next;
        dummy->next = fast;
        fast->next = p;
        slow->next = nullptr;
        head = fast;
    }
    return dummy->next;
}

/**
 * 方法 2，上面超时的原因是每次都要进行查找链表的结尾两个节点，而且k很大的
 * 时候就会超时，那么考虑一下k，如果k==n，那么链表就不发生变化，所以假设
 * 链表的长度是n，k%n如果没有余数，返回本身链表，否则，那么只发生余数次翻转即可
 * 这样上面方法经过改造就可以通过
*/
ListNode *rotateRight1(ListNode *head, int k)
{
    // 空链表，返回自身
    if (head == nullptr)
        return head;
    ListNode *cur = head;
    int cnt = 0;
    // 获得链表的总长度
    while (cur)
    {
        cnt++;
        cur = cur->next;
    }
    // 链表长度是1，那么返回自身，求余数次翻转
    if (k % cnt == 0)
        return head;
    else if (k % cnt)
        k = k % cnt;
    else if (cnt == 1)
        return head;
    ListNode *dummy = new ListNode(-1);
    dummy->next = head;
    for (int i = 0; i < k; i++)
    {
        ListNode *slow = head;
        ListNode *fast = head->next;
        // 每次旋转的时候都找都最后两个链表节点方便进行反转和插入
        while (fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next;
        }
        ListNode *p = dummy->next;
        dummy->next = fast;
        fast->next = p;
        slow->next = nullptr;
        head = fast;
    }
    return dummy->next;
}
/**
 * 方法 3，因为k可能的值会很大，对k%链表长度求余数,然后
 * 再把最后k个链表插入到前面来即可
*/
ListNode *rotateRight3(ListNode *head, int k)
{
    if (!head)
        return nullptr;
    ListNode *cur = head;
    int n = 1;
    while (cur->next)
    {
        ++n;
        cur = cur->next;
    }
    cur->next = head;
    int m = n - k % n;
    for (int i = 0; i < m; i++)
    {
        cur = cur->next;
    }
    ListNode *newhead = cur->next;
    cur->next = nullptr;
    return newhead;
}

/**
 * 方法 4，和方法 3思路都一样，就是写法略有不同
*/
ListNode *rotateRight4(ListNode *head, int k)
{
    if (!head)
        return nullptr;
    ListNode *cur = head;
    ListNode *tail;
    int cnt = 1;
    while (cur->next)
    {
        cur = cur->next;
        cnt++;
    }
    tail = cur;
    cur = head;
    k %= cnt;
    if (!k)
        return head;
    for (int i = 0; i < cnt - k - 1; i++)
        cur = cur->next;
    tail->next = head;
    head = cur->next;
    cur->next = nullptr;
    return head;
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
    print_list(rotateRight(a1, 2));
    return 0;
}
