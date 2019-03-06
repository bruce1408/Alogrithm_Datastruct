#include<iostream>
// 判断环的入口，在相遇的地方，让一个指针回到head，然后每次走一步即可。
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x):val(x),next(NULL){}
};

class Solution
{
    public:
    ListNode *detectCycle(ListNode *head)
    {
        ListNode * slow = head, *fast = head;
        while(fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
            if(fast == slow) break;
        }
        if(!fast || !fast->next) return NULL;
        slow = head;
        while(slow!=fast)
        {
            slow = slow->next;
            fast = fast->next;
        }
        return slow;
    }
};