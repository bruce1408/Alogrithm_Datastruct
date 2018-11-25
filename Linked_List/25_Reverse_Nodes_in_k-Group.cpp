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

void print_list(struct ListNode *head)
{
	while(head)
	{
		cout<<head->val<<"->";
		head = head->next;
	}
	cout<<"end"<<endl;
}

// 移动节点函数
ListNode *reverseOneGroup(ListNode *pre, ListNode *cur)
{
    ListNode * start = pre;
    ListNode * temp = pre->next;
    while(start!=cur)
    {
        pre->next = temp->next;
        temp->next = temp->next->next;
        pre->next->next = temp;
        start = temp;
    }
    return start->next;
}

ListNode* reverseKGroup(ListNode* head, int k) 
{
    ListNode *dummy = new ListNode(-1), *pre = dummy;
    dummy->next = head;
    ListNode *cur = head;
    int i=0;
    while(cur)
    {
        ++i;
        if(i%k==0)
        {
            pre = reverseOneGroup(pre, cur->next); // 在这之间的节点都要翻转
        }
        else cur = cur->next;
    }
    
    return dummy->next;
}



int main()
{
	ListNode head(1);
	ListNode a(2);
	ListNode b(3);
	ListNode c(4);
	ListNode d(5);
    head.next = &a;
    a.next = &b;
    b.next = &c;
    c.next = &d;
    ListNode * res = reverseKGroup(&head, 2);
    print_list(res);
    return 0;
	
}