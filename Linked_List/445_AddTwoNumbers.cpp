#include<iostream>
#include<vector>
#include<stack>
using namespace std;
 struct ListNode
 {
     int val;
     ListNode *next;
     ListNode(int x):val(x),next(nullptr){}
 };


 /**
  * 两个链表相加即可
  * 两个链表相加的第二种类型,用到了栈的概念，这里用容器，也是一样的效果。这种方法一定要掌握！
  * Example:
  * Input: (7 -> 2 -> 4 -> 3) + (5 -> 6 -> 4)
  * Output: 7 -> 8 -> 0 -> 7
 */


/**
 * 方法 1,使用栈，生成一个栈容器，每次把栈顶的元素相加即可；
*/
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
{
    ListNode *p1 = l1, *p2 = l2;
    stack<int>res1;
    stack<int>res2;
    while(p1)
    {
        res1.push(p1->val);
        p1 = p1->next;
    }
    while(p2)
    {
        res2.push(p2->val);
        p2 = p2->next;
    }

    int carry = 0, bitSum = 0;
    stack<int>res;
    while(!res1.empty() && !res2.empty())
    {
        bitSum = res1.top() + res2.top() + carry;
        carry = bitSum/10;
        res.push(bitSum%10);
        res1.pop();
        res2.pop();
    }
    while(!res1.empty())
    {
        res.push(res1.top());
        res1.pop();
    }
    while(!res2.empty())
    {
        res.push(res2.top());
        res2.pop();
    }
    ListNode *head = new ListNode(-1);
    while(res.empty())
    {
        
    }

}

// ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

//     vector<int> nums1, nums2;
//     while(l1)//l1  
//     {
//         nums1.push_back(l1->val);
//         l1 = l1->next;
//     }
//     while(l2)//l2 
//     {
//         nums2.push_back(l2->val);
//         l2 = l2->next;
//     }

//     int m = nums1.size(), n = nums2.size();
//     int sumResult = 0, carry = 0;

//     ListNode *head = nullptr, *p = nullptr;
//     /*算法的核心部分：*/
//     for(int i = m - 1, j = n - 1; i >= 0 || j >= 0 || carry > 0; i--, j--) {
//         sumResult = carry;
//         if(i >= 0) 
//             sumResult += nums1[i];

//         if(j >= 0)
//             sumResult += nums2[j];

//         carry = sumResult / 10;

//         p = new ListNode(sumResult%10);
//         /*头部插入算法！*/
//         p->next = head;
//         head = p;
//     }
//     return head;
// }



