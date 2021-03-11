#include <iostream>
#include <cstring>
using namespace std;
struct ListNode
{
    char c;
    ListNode *next;
    ListNode(char x, ListNode *next_) : c(x), next(next_) {}
};

/**
 * 141 判断链表啊是否有环
 * 判断是否链表环
 * */
bool hasCycle(struct ListNode *head)
{
    ListNode *fast = head;
    ListNode *slow = head;

    while (fast != NULL && fast->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
        if (fast == slow)
            return true;
    }
    return false; //如果到最后没有跳出，那么就是说链表没有环
}

/**
 * 求链表环的第一个结点
 * */
class Solution
{
public:
    ListNode *detectCycle(ListNode *head)
    {

        if (head == NULL || head->next == NULL)
            return NULL;

        ListNode *fast = head;
        ListNode *slow = head;
        while (fast->next->next && fast->next)
        {

            fast = fast->next->next;
            slow = slow->next;
            if (fast == slow)
                break;
        }
        if (fast->next == NULL || fast->next->next == NULL)
            return NULL;

        fast = head;
        while (fast != slow)
        {
            fast = fast->next;
            slow = slow->next;
        }
        return slow;
    }
};
