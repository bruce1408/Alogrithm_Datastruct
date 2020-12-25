#include <iostream>
#include <vector>
#include <stack>
using namespace std;
/**
 * Given a singly linked list, determine if it is a palindrome.
 * 判断是否是回文链表,思路：
 * 反转链表来做。
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

/** 方法 1，
 * 值放到容器中去，在容器中判断是否是回文数，
 * 容器中，设置两个数值，i和j，一个从0开始，一个从最后一个位置开始比较，分别自增
 * 和自减1。然后通过下标来判断是不是相同，算法的时间复杂度是O(n),但是空间复杂度也是O(n),不满足常数空间复杂度
 */
bool isPalindrome1(ListNode *head)
{
    vector<int> res;
    ListNode *cur = head;
    while (cur)
    {
        res.push_back(cur->val);
        cur = cur->next;
    }
    for (int i = 0, j = res.size() - 1; i < j; i++, j--)
    {
        if (res[i] != res[j])
            return false;
    }
    return true;
}

/**
 * 方法 2，使用栈来做即可，不满足题目条件
*/
bool isPalindrome2(ListNode *head)
{
    stack<int> tmp;
    ListNode *cur = head;
    while (cur)
    {
        tmp.push(cur->val);
        cur = cur->next;
    }
    cur = head;
    while (!tmp.empty())
    {
        if (tmp.top() != cur->val)
        {
            return false;
        }
        else
        {
            tmp.pop();
            cur = cur->next;
        }
    }
    return true;
}

/**
 * 方法 3，回文链表，找到中间节点的链表然后反转。
 */
ListNode *ReverseList3(ListNode *head)
{
    if (head == nullptr)
        return head;
    ListNode *dummy = new ListNode(-1);
    ListNode *p = head;
    ListNode *nextNode = p->next;
    while (p)
    {
        nextNode = p->next;
        p->next = dummy->next;
        dummy->next = p;
        p = nextNode;
    }
    return dummy->next;
}

bool isPalindrome3(ListNode *head)
{
    if (head == nullptr)
        return true;
    ListNode *slow = head;
    ListNode *fast = head->next;

    // 找到链表的中间点
    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    cout << "中点是: " << slow->val << endl;
    slow = slow->next;
    ListNode *q = ReverseList3(slow);

    // 判断是否是回文串
    ListNode *p = head;
    while (p && q)
    {
        if (p->val != q->val)
        {
            return false;
        }
        p = p->next;
        q = q->next;
    }
    return true;
}

/**
 * 方法 4，查找链表的中间节点，慢指针走1步，快指针走2步；
 * 找到之后反转中间节点后面的节点，然后开始比较即可，和方法 2的思路完全一样，
 * 就是反转的算法是不带头结点的。反转之后依次比较，如果值不相同，返回false即可
*/
ListNode *middleList4(ListNode *head)
{
    ListNode *fast = head;
    ListNode *slow = head;
    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}
bool isPalindrome4(ListNode *head)
{
    ListNode *p1 = head;
    //找到链表的中点，然后开始反转后面的链表即可；
    ListNode *middle = middleList4(head);
    // 开始反转后面的链表；
    ListNode *rear = NULL, *cur = middle, *pre = middle;
    while (cur)
    {
        pre = cur;
        cur = cur->next;
        pre->next = rear;
        rear = pre;
    }

    while (rear && p1)
    {
        if (rear->val != p1->val)
            return false;
        else
        {
            rear = rear->next;
            p1 = p1->next;
        }
    }
    return true;
}

int main()
{
    ListNode *head = new ListNode(1);
    ListNode *node2 = new ListNode(2);
    ListNode *node3 = new ListNode(5);
    ListNode *node4 = new ListNode(4);
    ListNode *node5 = new ListNode(5);
    ListNode *node6 = new ListNode(2);
    ListNode *node7 = new ListNode(1);
    head->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;
    node5->next = node6;
    node6->next = node7;

    bool result = isPalindrome3(head);
    if (result)
        cout << "是回文串" << endl;
    else
        cout << "不是回文串" << endl;
    // cout << middleList4(head)->val << endl;
    return 0;
}