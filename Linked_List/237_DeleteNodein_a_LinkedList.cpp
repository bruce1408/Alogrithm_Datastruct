/* --------------- description -----------------
	删除一个单链表的某个结点
	1->2->3->4 变成 1->2->4
*/
#include<iostream>
#include<cstring>
using namespace std;
struct linkList
{
	int num;
	linkList *next;
};
int main()
{
	int i;
	linkList d = {4,NULL};
	linkList c = {3,&d};
	linkList b = {2,&c};
	linkList a = {1,&b};
	linkList *head = &a;
	linkList *p = head;
	linkList *before = NULL;
	cout<<"在1,2,3,4中请输入你要删除的数字："<<endl;
	cin>>i;
	/*查找位置部分*/
	while(p)
	{
		if(p->num == i)
			break;
		before = p;
		p = p->next;
		
			
	}
	if(before == NULL)//如果是删除第一个节点的话
		head = p->next;
	else
	{
		before->next = p->next;
	}
	p = head;
	while(p)
	{
		cout<<p->num<<"->";
		p = p->next;
	}
	cout<<"end"<<endl;
	return 0;
}

// 这个题目的意思是没有给你头结点，直接是给你要删除的节点让你删改节点
class Solution
{
	pubic:
	void deleteNode(ListNode *node)
	{
		//先把后一个值覆盖到当前节点
		node->val = node->next->val;
		//现在两个节点值完全一样，删除后面的几点
		ListNode*tmp =node->next;
		node->next = node->next->next;
		delete node->next;
	}
};