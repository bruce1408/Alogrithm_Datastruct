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


// 翻转 k 个节点的链表。分两步，第一步，找翻转区间，第二步，在区间内翻转链表
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
ListNode *reverseOneGroup(ListNode *pre, ListNode *last)
{
    ListNode * start = pre->next;
    ListNode * cur = start->next;
    while(cur!=last)
    {
        start->next = cur->next;
        cur->next = pre->next;
        pre->next = cur;
        cur = start->next;
    }
    return start;

}

ListNode* reverseKGroup(ListNode* head, int k) 
{
    if(!head || k==1) return head;
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
            cur = pre->next;
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
    ListNode * res = reverseKGroup(&head, 3);
    print_list(res);
    return 0;
	
}