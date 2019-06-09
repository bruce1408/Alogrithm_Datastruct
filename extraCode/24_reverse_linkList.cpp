#include<iostream>
#include<string>
#include<stack>
using namespace std;
/**
 * 题目：反转链表
 * 方法 加头结点
 * 思路：
 * 链表的经典题目，利用指针操作来对每一个链表进行反转，利用头结点来做
*/
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x):val(x),next(NULL){}
};

void print_list(ListNode* head)
{
	while(head)
	{
		cout<<head->val<<" ";
		head = head->next;
	}
}

// 带头结点的做法
ListNode* reverseList(ListNode* head) 
{
	if (!head) return head;
	ListNode *dummy = new ListNode(-1);
	dummy->next = head;
	ListNode *cur = head;
	while (cur->next)
	{
		ListNode *tmp = cur->next;
		cur->next = tmp->next;
		tmp->next = dummy->next;
		dummy->next = tmp;
	}
	return dummy->next;
}

// 不带头结点的做法
ListNode* reverseNode(ListNode * head)
{
	if(head==nullptr) return NULL;
	ListNode *dummy = nullptr;
	while(head)
	{
		ListNode *t = head->next;
		head->next = dummy;
		dummy = head;
		head = t;	
	}

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

	ListNode* rehead = reverseList(head);
	print_list(rehead);
	return 0;
}
