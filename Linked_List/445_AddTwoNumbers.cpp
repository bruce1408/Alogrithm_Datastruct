/*两个链表相加的第二种类型
  用到了栈的概念，这里用容器，也是一样的效果。
  这种方法一定要掌握！*/
#include<iostream>
#include<vector>
using namespace std;
 struct ListNode
 {
     int val;
     ListNode *next;
     ListNode(int x):val(x),next(nullptr){}
 };

 
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    vector<int> nums1, nums2;
    while(l1)//l1  
	{
        nums1.push_back(l1->val);
        l1 = l1->next;
    }
    while(l2)//l2 
	{
        nums2.push_back(l2->val);
        l2 = l2->next;
    }

    int m = nums1.size(), n = nums2.size();
    int sumResult = 0, carry = 0;

    ListNode *head = nullptr, *p = nullptr;
	/*算法的核心部分：*/
    for(int i = m - 1, j = n - 1; i >= 0 || j >= 0 || carry > 0; i--, j--) {
        sumResult = carry;
        if(i >= 0) 
            sumResult += nums1[i];

        if(j >= 0)
            sumResult += nums2[j];

        carry = sumResult / 10;

        p = new ListNode(sumResult%10);
		/*头部插入算法！*/
        p->next = head;
        head = p;
    }

    return head;
}
};


