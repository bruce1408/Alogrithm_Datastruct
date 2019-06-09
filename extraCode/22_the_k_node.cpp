#include<iostream>
#include<string>
#include<stack>
using namespace std;
/**
 * 题目：链表中的倒数第 k 个节点，输入是一个链表，输出为该链表中导数第k个节点
 * 例如：1，2，3，4，5，6； k=2，那么输出是 5.
 * 方法1 遍历链表得到长度是n，然后再次遍历一遍到n-k+1就是删除节点的位置；
*/
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

// 方法1 返回的是倒数第 k 个节点的值，利用栈的先进后出的特征，只要读取栈顶的第k个点即可
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

// 方法2 两次遍历这个链表，然后返回这个数
ListNode * findKNode(ListNode * head, int k)
{
	if(k<1 || head==nullptr) return nullptr;
	int lengthNode = 0;
	ListNode *cur = head;
	while(cur)
	{
		lengthNode++;
		cur = cur->next;
	}
	cur = head;
	for(int i=0; i<lengthNode-k; i++)
	{
		cur = cur->next;
	}
	return cur;
}

// 方法3 只遍历一遍，那么需要定义两个指针，一个指针是到k-1之后，和另一个指针一起开始从后遍历，知道第一个指针到尾
ListNode*findKthtotail(ListNode*head, int k)
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
    ListNode* node2 = new ListNode(2);
    ListNode* node3 = new ListNode(3);
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
	cout<<"请输入返回的倒数第 k 个节点的数字："<<endl;
	int a;
	cin>>a;
	// cout<<findKthtotail(head,a);
	
	
	//2:返回节点
	// ListNode* res;
	// res = findKthtotail(head,a);
	// if(res)
	// 	cout<<res->val<<endl;
	// else
	// 	cout<<""<<endl;

	cout<<"倒数第 "<<a<<" 个节点是 ："<<findKthtotail(head, a)->val<<endl;
	return 0;
}