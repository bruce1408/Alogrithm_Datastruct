/*判断是否是有链表环*/
#include <iostream>
#include <cstring>
using namespace std;

struct ListNode
{
    char c;
    ListNode *next;
    ListNode(char x, ListNode *next_) : c(x), next(next_) {}
};

// int main()
// {
// 	ListNode *p = head;
// 	ListNode *head = &a;
// 	ListNode a = {'a',&b};
// 	ListNode b = {'b',&c};
// 	ListNode c = {'c',&d};
// 	ListNode d = {'d',&e};
// 	ListNode e = {'e',&f};
// 	ListNode f = {'f',&d};
// 	return 0;
// }

/*判断是否链表环*/
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

/*求链表环的第一个结点*/
class Solution
{
public:
    ListNode *detectCycle(ListNode *head)
    {

        if (head == NULL || head->next == NULL)
            return NULL;

        ListNode *fast = head;
        ListNode *slow = head;

        // do
        // {
        // if(fast != NULL)
        // fast = fast->next;
        // else
        // return NULL;
        // if(fast != NULL)
        // fast = fast->next;
        // else
        // return NULL;
        // slow = slow->next;
        // }while(fast != slow);

        //这种方法有错误
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

/*C++寻找环的第一个入口交点的第二种方法*/

// ListNode *detectCycle(ListNode *head) {
// if (head == NULL || head->next == NULL)
// return NULL;

// ListNode *slow  = head;
// ListNode *fast  = head;
// ListNode *entry = head;

// while (fast->next && fast->next->next) {
// slow = slow->next;
// fast = fast->next->next;
// if (slow == fast) {                      // there is a cycle
// while(slow != entry) {               // found the entry location
// slow  = slow->next;
// entry = entry->next;
// }
// return entry;
// }
// }
// return NULL;                                 // there has no cycle
// }

// 判断链表是否有环。代码的循环条件是while(fast && fast->next)
while (fast && fast->next)
{
    slow = slow->next;
    fast = fast->next->next;
    if (fast == slow)
        return true; //如果是环一定会推出循环，否则不是换，最后一个链表也会推出循环
}
// 另外判断一个环的入口怎么办，就是在两个环第一次相交的地方，停下来，让其中一个指针从头开始，然后两个指针每次走一步。再次相遇的地方就是入口的交点
while (fast && fast->next)
{
    slow = slow->next;
    fast = fast->next->next;
    if (slow == fast)
        break;
}
if (!fast || !fast->next)
    return NULL;
slow = head;
while (slow != fast)
{
    slow = slow->next;
    fast = fast->next;
}
return slow;
