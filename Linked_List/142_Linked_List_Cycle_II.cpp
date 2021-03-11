#include<iostream>
using namespace std;
/**
 * 142 找到环的入口的链表
 * 题目的要求是一个带环的链表，如果有环，那么给出这个环的入口，否则返回null
 * 思路：
 * 判断环的入口，设置两个指针，一个快指针每次走两步，一个慢指针每次走一步，如果相遇，那么就让慢指针回到head第一个节点，然后快慢指针
 * 每次都走一步，下次再相遇就是环的入口处。
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode*slow = head, *fast = head;
        while(fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast) break;
        }
        if(fast==NULL || fast->next==NULL) return NULL;
        fast = head;
        while(fast != slow)
        {
            slow = slow ->next; 
            fast = fast->next;
        }
        return fast; 
    }
};



class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if (!head || !head->next) return 0;
        ListNode *first = head, *second = head;

        while (first && second)
        {
            first = first->next;
            second = second->next;
            if (second) second = second->next;
            else return 0;

            if (first == second)
            {
                first = head;
                while (first != second)
                {
                    first = first->next;
                    second = second->next;
                }
                return first;
            }
        }

        return 0;
    }
};
