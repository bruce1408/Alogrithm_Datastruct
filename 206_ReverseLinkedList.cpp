/*链表的反转算法：
  核心的思想是一个工作指针p、一个rear指针初始值设为NULL、
  还有一个从后往前指的指针before。*/

#include<iostream>
#include<vector>

using namespace std;


struct ListNode
{
	int val;
	ListNode *next;
	
};

// void print_list(struct ListNode *head);
void print_list(ListNode *head);
// ListNode* ReverseList(ListNode* pHead);

//链表反转算法：
class Solution
{
	public:
	ListNode* ReverseList(ListNode* pHead)
	{
		if (pHead == NULL || pHead->next == NULL) return pHead;
 
		ListNode* rear = NULL;
		ListNode* p = pHead;
		ListNode* before = pHead;
		while(p)
		{
			
			before = p; 
			p = p->next;//工作指针		
			before->next = rear;     
			rear = before;
			
		}
    return rear;
	}	
		
};

//主函数
int main()
{
	vector<int> l1;
	//自己造一个回文链表
	
	ListNode e = {5,NULL};
	ListNode d = {4,&e};
	ListNode c = {3,&d};
	ListNode b = {2,&c};
	ListNode a = {1,&b};
	ListNode *head = &a;
	// ListNode *p = head;
	// ListNode *before = head;
	ListNode *f = head;
	
	Solution s;
	print_list(f);
	// before = s.ReverseList(f);
	print_list(s.ReverseList(f));
	

	
return 0;	
}



//打印部分：	
void print_list(struct ListNode *head)
{
	while(head)
	{
		cout<<head->val<<"->";
		head = head->next;
	}
	cout<<"end"<<endl;
}















