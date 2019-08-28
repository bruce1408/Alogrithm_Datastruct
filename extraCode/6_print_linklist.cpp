//反序打印链表的值
#include<iostream>
#include<vector>
#include<stack>
using namespace std;

/**
 * 题目： 从尾到头打印链表，输入链表的头结点，从尾到头打印每一个节点的值
 * 方法1：利用栈的先进后出的
 * 思路：利用特性，把每一个元素放到栈中，然后开始打印
*/

struct Linklist
{
	int val;
	Linklist *next;
	Linklist(int x):val(x),next(NULL) {}
};

void print_reverse(Linklist* head)
{
	stack<int>res;
	while(head)
	{
		res.push(head->val);
		head = head->next;
	}
	while(!res.empty())
	{
		cout<<res.top()<<" ";
		res.pop();
	}
}
int main()
{
	Linklist *head = new Linklist(4);
	Linklist *h1 = new Linklist(5);
	Linklist *h2 = new Linklist(6);
	Linklist *h3 = new Linklist(7);
	Linklist *h4 = new Linklist(8);
	head->next = h1;
	h1->next = h2;
	h2->next = h3;
	h3->next = h4;
	
	cout<<endl;
	cout<<"反序打印链表"<<endl;
	print_reverse(head);
	return 0;	
}