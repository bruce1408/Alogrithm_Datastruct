/*已经排好序的链表去重
  就两句话，如果比较当前节点和下一节点的数值相同的话，
  那么，让下下节点指向当前节点，
  否则，继续向后移动节点，继续判断当前节点和下一节点不为空；*/
#include<iostream>
#include<vector>
using namespace std;

struct ListNode
{
	int val;
	ListNode *next;
	
};

void print_list(struct ListNode *head);

class Solution
{
	public:
	ListNode *deleteDuplicates(ListNode *head)
	{
		ListNode *p = head;
		while(p&&p->next)
		{
			if(p->next->val == p->val)
			{
				p->next = p->next->next;
			}
			else
			{
				p = p->next;
			}
		}
		return head;
	}
	
};

int main()
{
	
	ListNode e = {3,NULL};
	ListNode d = {3,&e};
	ListNode c = {2,&d};
	ListNode b = {1,&c};
	ListNode a = {1,&b};
	ListNode *head = &a;
	ListNode *before = head;
	
	print_list(head);
	
	Solution s;
	print_list(s.deleteDuplicates(before));

	
	return 0;
	
}



void print_list(struct ListNode *head)
{
	while(head)
	{
		cout<<head->val<<"->";
		head = head->next;
	}
	cout<<"end"<<endl;
}