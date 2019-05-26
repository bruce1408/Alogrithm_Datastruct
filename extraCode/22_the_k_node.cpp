#include<iostream>
#include<string>
#include<stack>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x):val(x),next(NULL){}
};

void print_list(ListNode* head)
{	
	cout<<head->val<<" ";
	head = head->next;
}

//return the kth num ,not a node
// int findKthtotail(ListNode*head,int k)
// {
	// int res;
	// stack<int>temp;
	// ListNode* p = head;
	// while(p)
	// {
		// temp.push(p->val);
		// p = p->next;
	// }
	// for(int i=0;i<k;i++)
	// {
		// res = temp.top();
		// temp.pop();
	// }
	// return res;
	
// }





ListNode*findKthtotail(ListNode*head,int k)
{
	if(head==nullptr || k==0)
		return NULL;
	
	int n = k-1;
	ListNode* cur = head;
	ListNode* p2 = head;
	while(cur && n>=0)
	{
		cur = cur->next;
		n--;
	}
	
	while(cur)
	{
		cur = cur->next;
		p2 = p2->next;
	}
	return p2;
}

int main()
{
	//create a linklist
	ListNode* head = new ListNode(1);
    ListNode* node2 = new ListNode(1);
    ListNode* node3 = new ListNode(1);
    ListNode* node4 = new ListNode(4);
    ListNode* node5 = new ListNode(5);
    ListNode* node6 = new ListNode(6);
    ListNode* node7 = new ListNode(7);
	
    head->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;
    node5->next = node6;
    node6->next = node7;
	//1:返回第k个数的话可以用栈
	int a;
	cin>>a;
	// cout<<findKthtotail(head,a);
	
	
	//2:返回节点
	ListNode* res;
	res = findKthtotail(head,a);
	if(res)
		cout<<res->val;
	else
		cout<<""<<endl;
	
	
	
	return 0;
}