#include <iostream>
#include <cstring>
using namespace std;

/**
 * 删除一个单链表的某个结点，不是从头开始，而是给定一个节点,删除这个节点
 * 1->2->3->4 变成 1->2->4
 * 
 * Input: head = [4,5,1,9], node = 5
 * Output: [4,1,9]
*/
struct ListNode
{
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

/**
 * 方法 1, 删除链表中间的某个节点，用后面的值来覆盖到前面的值，然后再把后面的值
 * 删除掉就可以了
*/
void deleteNode1(ListNode *node)
{
	node->val = node->next->val;
	ListNode *temp = node->next;
	node->next = temp->next;
	delete temp;
}

void print(ListNode *cur)
{
	while (cur)
	{
		cout << cur->val << endl;
		cur = cur->next;
	}
}

ListNode *deleteHead(ListNode *head, ListNode *p)
{
	if (p->next)
	{
		p->val = p->next->val;
		p->next = p->next->next;
	}
	else
	{
		cout << "delete last node : " << endl;
		p->val = head->val;
		head = head->next;
	}
	return head;
}

int main()
{
	ListNode *head = new ListNode(3);
	head->next = new ListNode(4);
	head->next->next = new ListNode(5);
	print(head);

	ListNode *cur = head;
	ListNode *p = nullptr;
	while (cur)
	{
		if (cur->val == 5)
		{
			p = cur;
			break;
		}
		cur = cur->next;
	}
	cout << p->val << endl;
	cout << "after delete is: " << endl;

	ListNode *q = deleteHead(head, p);
	print(q);
}
