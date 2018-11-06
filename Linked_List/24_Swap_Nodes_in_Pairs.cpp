#include<iostream>
#include<stack>
#include<vector>
using namespace std;


struct ListNode
{
	int val;
	ListNode *next;
	ListNode(int x):val(x),next(NULL) {}
};


class Solution 
{
	public:
    ListNode* swapPairs(ListNode* head) 
	{
        ListNode *dummy = new ListNode(-1), *pre = dummy;
        dummy->next = head;
        while (pre->next && pre->next->next) 
		{
            ListNode *t = pre->next->next;
            pre->next->next = t->next;
            t->next = pre->next;
            pre->next = t;
            pre = t->next;
        }
        return dummy->next;
    }
};



int main()
{
	vector<int>res;
	res.push_back(10);
	res.push_back(2);
	cout<<res.back();
	return 0;
	
}

















