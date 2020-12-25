#include <iostream>
#include <vector>
#include <stack>
using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

/**
  * 两个链表相加即可
  * 两个链表相加的第二种类型,用到了栈的概念，这里用容器，也是一样的效果。这种方法一定要掌握！
  * Example:
  * Input: (7 -> 2 -> 4 -> 3) + (5 -> 6 -> 4)
  * Output: 7 -> 8 -> 0 -> 7
 */

/**
 * 方法 1,使用栈，生成一个栈容器，每次把栈顶的元素相加即可；注意考虑进位，比如[5], [5]的情况。
 * 具体就是两个栈分别装两个链表的值，然后栈顶元素相加的和放进新的栈空间，然后每次取这个栈的元素来构成一个链表即可，但是
 * 空间上要开辟三个栈元素空间，时间复杂度是O(max(m,n))
*/
ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
{
    ListNode *p1 = l1, *p2 = l2;
    stack<int> res1, res2;
    while (p1) // 链表1 入栈
    {
        res1.push(p1->val);
        p1 = p1->next;
    }
    while (p2) // 链表2 入栈
    {
        res2.push(p2->val);
        p2 = p2->next;
    }

    int carry = 0, bitSum = 0;
    stack<int> res;
    // 两个链表的和放入到新的栈中，这一部分可以用方法 1.1来优化一下。写的太冗长了
    while (!res1.empty() && !res2.empty())
    {
        bitSum = res1.top() + res2.top() + carry;
        carry = bitSum / 10;
        res.push(bitSum % 10);
        res1.pop();
        res2.pop();
    }
    while (!res1.empty())
    {
        int temp = res1.top() + carry;
        res.push(temp % 10);
        res1.pop();
        carry = temp / 10;
    }
    while (!res2.empty())
    {
        int temp = res1.top() + carry;
        res.push(temp % 10);
        res2.pop();
        carry = temp / 10;
    }
    // 考虑进位
    if (carry != 0)
    {
        res.push(carry);
        carry = 0;
    }
    ListNode *head = new ListNode(-1);
    ListNode *cur = head;
    // 生成链表
    while (!res.empty())
    {
        ListNode *temp = new ListNode(res.top());
        cur->next = temp;
        cur = temp;
        res.pop();
    }
    return head->next;
}

/**
 * 方法 1.1,思路和方法 1完全一样，只不过就是写法上更加简单和简洁，非常值得借鉴一下
*/
ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
{
    stack<int> s1, s2;
    while (l1)
    {
        s1.push(l1->val);
        l1 = l1->next;
    }
    while (l2)
    {
        s2.push(l2->val);
        l2 = l2->next;
    }
    int sum = 0;
    ListNode *res = new ListNode(0);
    while (!s1.empty() || !s2.empty())
    {
        if (!s1.empty())
        {
            sum += s1.top();
            s1.pop();
        }
        if (!s2.empty())
        {
            sum += s2.top();
            s2.pop();
        }
        res->val = sum % 10;
        ListNode *head = new ListNode(sum / 10);
        head->next = res;
        res = head;
        sum /= 10;
    }
    return res->val == 0 ? res->next : res;
}
/**
 * 方法 2，使用链表反转的技术。一般链表翻转，空间上可以用栈来解决，但是如果解决空间问题，那么就用
 * 带头结点的或者是不带头结点的算法来反转链表；这是常用的方法
*/
ListNode *reverse(ListNode *head)
{
    ListNode *pre = nullptr;
    while (head)
    {
        ListNode *t = head->next;
        head->next = pre;
        pre = head;
        head = t;
    }
    return pre;
}

ListNode *addTwoNumbers2(ListNode *l1, ListNode *l2)
{
    l1 = reverse(l1);
    l2 = reverse(l2);
    ListNode dummy_head(0);
    ListNode *it = &dummy_head;
    int sum = 0, carry = 0;
    while (l1 || l2 || carry)
    {
        sum = carry + (l1 ? l1->val : 0) + (l2 ? l2->val : 0);
        carry = sum / 10;
        it->next = new ListNode(sum % 10);
        it = it->next;
        l1 = l1 ? l1->next : nullptr;
        l2 = l2 ? l2->next : nullptr;
    }
    return reverse(dummy_head.next);
}

/**
 * 方法 4，使用翻转链表来做，每个都翻转相加，然后结果再翻转链表即可
*/
class Solution
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        // 思路就是先写一个翻转链表函数，然后l1和l2翻转，结果相加之后再翻转即可
        ListNode *r1 = reverseNode(l1);
        ListNode *r2 = reverseNode(l2);
        ListNode *dummy = new ListNode(-1), *cur = dummy;
        int t = 0;
        while (r1 || r2)
        {
            if (r1)
                t += r1->val, r1 = r1->next;
            if (r2)
                t += r2->val, r2 = r2->next;
            cur->next = new ListNode(t % 10);
            t /= 10;
            cur = cur->next;
        }
        if (t)
            cur->next = new ListNode(t); // 这个地方要考虑最后还有进位，不能漏了
        return reverseNode(dummy->next);
    }
    // 链表的翻转
    ListNode *reverseNode(ListNode *head)
    {
        if (!head || !head->next)
            return head;
        ListNode *a = head, *b = head->next;
        while (b)
        {
            ListNode *c = b->next;
            b->next = a;
            a = b;
            b = c;
        }
        head->next = NULL;
        return a;
    }
};

void printf_list(ListNode *head)
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
    ListNode *d1 = new ListNode(3);
    ListNode *c1 = new ListNode(4);
    ListNode *b1 = new ListNode(2);
    ListNode *a1 = new ListNode(7);
    ListNode *head1 = a1;
    ListNode *p1 = head1;
    a1->next = b1;
    b1->next = c1;
    c1->next = d1;

    ListNode *c2 = new ListNode(4);
    ListNode *b2 = new ListNode(6);
    ListNode *a2 = new ListNode(5);
    a2->next = b2;
    b2->next = c2;

    ListNode *head2 = a2;
    ListNode *p2 = head2;

    //打印出两个链表的值
    printf_list(p1);
    printf_list(p2);
    printf_list(addTwoNumbers(head1, head2));
    return 0;
}
