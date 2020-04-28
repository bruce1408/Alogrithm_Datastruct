#include<iostream>
using namespace std;
/**
 * Remove all elements from a linked list of integers that have value val.
 * Example:
 * Input:  1->2->6->3->4->5->6, val = 6
 * Output: 1->2->3->4->5
 * 删除一个符合条件的节点。
 * 有很多思路，我是用的是两个指针来做，这样效率很高！
 */
struct ListNode
{
	int val;
	ListNode *next;
	ListNode (int x): val(x), next(NULL){}
};

void printf_list(struct linkList *u);

/**
 * 方法 1,给一个前继节点
*/
ListNode *removeElements1(ListNode * head, int val)
{
	ListNode *dummy = new ListNode(-1);
	dummy->next = head;
	ListNode *pre = dummy;
	while(pre->next)
	{
		if(pre->next->val == val)
		{
			ListNode *tmp = pre->next;
			pre->next = pre->next->next;
			delete tmp;
		}
		else pre = pre->next;
	}
	return dummy->next;
}

/**
 * 方法 2，使用递归的方法
*/
ListNode* removeElements(ListNode* head, int val) 
{
	if (!head) return NULL;
	head->next = removeElements(head->next, val);
	return head->val == val ? head->next : head;
}

int main()
{
	linkList g1 = {6,NULL};
	linkList f1 = {5,&g1};
	linkList e1 = {4,&f1};
	linkList d1 = {3,&e1};
	linkList c1 = {6,&d1};
	linkList b1 = {2,&c1};
	linkList a1 = {1,&b1};
	linkList *head = &a1;
	linkList *p = head;
	linkList *before = head;

	//打印出链表的值
	printf_list(p);

	int i = 6;//这里i是可以自己选择的值；
	cout<<"请输入你要删除的节点的值："<<endl;
	// cin>>i;
	while(p)
	{
		if(p->val==i)//删除节点的值是6的节点；
		{
			before->next = p->next;
			cout<<"正在删除"<<i<<"····"<<endl;
		}
		before = p;
		p = p->next;
	}
	p = head;
	printf_list(p);
	return 0;
}

void printf_list(struct linkList *u)//输出链表的函数
{
	while(u)
	{
		cout<<u->val<<"->";
		u = u->next;
	}
	cout<<"end"<<endl;	
}



