/*
 * @lc app=leetcode id=25 lang=cpp
 *
 * [25] Reverse Nodes in k-Group
 *
 * https://leetcode.com/problems/reverse-nodes-in-k-group/description/
 *
 * algorithms
 * Hard (35.38%)
 * Total Accepted:    169.2K
 * Total Submissions: 478.1K
 * Testcase Example:  '[1,2,3,4,5]\n2'
 *
 * Given a linked list, reverse the nodes of a linked list k at a time and
 * return its modified list.
 * 
 * k is a positive integer and is less than or equal to the length of the
 * linked list. If the number of nodes is not a multiple of k then left-out
 * nodes in the end should remain as it is.
 * 
 * 
 * 
 * 
 * Example:
 * 
 * Given this linked list: 1->2->3->4->5
 * 
 * For k = 2, you should return: 2->1->4->3->5
 * 
 * For k = 3, you should return: 3->2->1->4->5
 * 
 * Note:
 * 
 * 
 * Only constant extra memory is allowed.
 * You may not alter the values in the list's nodes, only nodes itself may be
 * changed.
 * 
 * 
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
    // 方法一：分成两个部分
    // ListNode* reverseKGroup(ListNode* head, int k) {
    //     if(!head || k==1) return head;
    //     ListNode *dummy = new ListNode(-1), *pre = dummy, *cur = head; 
    //     dummy->next = head; 
    //     int cnt = 0;
    //     while(cur)
    //     {
    //         ++cnt;
    //         if(cnt% k ==0)
    //         {
    //             pre = reverseK(pre, cur->next);
    //             cur = pre->next;
    //         }
    //         else cur = cur->next;
    //     }
    //     return dummy->next;      
    // }

    // ListNode *reverseK(ListNode *pre, ListNode *last)
    // {  
    //     ListNode *start = pre->next;
    //     ListNode *cur = start->next;
    //     while(cur != last)
    //     {
    //         start->next = cur->next;
    //         cur->next = pre->next;
    //         pre->next = cur;
    //         cur = start->next; 
    //     }
    //     return start;
    // }

    // 方法二：统计所有长度，然后在长度内翻转
    ListNode* reverseKGroup(ListNode* head, int k)
    {
        ListNode *dummy = new ListNode(-1), *pre = dummy;
        dummy->next = head;
        ListNode *cur = pre;
        int num=0;
        while(cur = cur->next) ++num;
        while(num >= k)
        {
            cur = pre->next;
            for(int i=1; i<k; ++i)
            {
                ListNode *t = cur->next;
                cur->next = t->next;
                t->next = pre->next;
                pre->next = t;
            }
            pre = cur;
            num -= k;
        }
        return dummy->next;
    }
};

