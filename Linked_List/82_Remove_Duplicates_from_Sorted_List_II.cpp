/* --------------- description -----------------
	删除一个单链表的重复节点
	1->1->1->2->3->4 变成 2->3->4
*/



#include<iostream>
#include<cstring>
using namespace std;

// struct linkList
// {
	// int num;
	// linkList *next;
// };

// int main()
// {
	
	// int i;
	// linkList f = {4,NULL};
	// linkList e = {3,&f};
	// linkList d = {2,&e};
	// linkList c = {1,&d};
	// linkList b = {1,&c};
	// linkList a = {1,&b};
	// linkList *head = &a;
	// linkList *p = head;
	// linkList *before = NULL;
	// cout<<"在1,1,1,2,3,4中请输入你要删除的数字："<<endl;
	// cin>>i;
	// /*查找位置部分*/
	// while(p)
	// {
		// if(p->num == i)
			// break;
		// before = p;
		// p = p->next;	
	// }
	
	// if(before == NULL)//如果是开头删除的话
		// head = p->next;
	// else
	// {
		// before->next = p->next;
	// }
	
	
	// p = head;
	// while(p)
	// {
		// cout<<p->num<<"->";
		// p = p->next;
	// }
	
	// cout<<"end"<<endl;
	// return 0;
	

// }


struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x):val(x),next(NULL){}
};

// 正确的版本；
ListNode* deleteDuplicates(ListNode*head)
{
	
	if(!head || !head->next)
		return head;
	ListNode*start = new ListNode(-1);
	start->next = head;
	ListNode* pre = start;
	while(pre->next)
	{
		ListNode*cur = pre->next;
		while(cur->next && cur->next->val==cur->val)
			cur = cur->next;
		if(cur!=pre->next) pre->next = cur->next;
		else pre = pre->next;
	}	
	return start->next;	
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

// 自己写错的版本。里面还应该嵌套一个while循环
ListNode * deleteDuplicate(ListNode *head)
{
	ListNode * dummy = new ListNode(-1);
	ListNode*pre = head,*cur = head;
	dummy->next = head;
	while(pre->next)
	{
		if(cur->next->val == pre->val)
		{
			cout<<"xiayige: "<<cur->next->val<<endl;
			cur = cur->next;
		}
		if(pre!=cur){dummy->next = cur->next;}
		else pre = pre->next;
	
		
	}
	dummy->next = pre;
	return dummy->next ;
}


int main()
{
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
	
	// ListNode* p = deleteDuplicate(head);
	// while(p)
	// {
	// 	cout<<p->val<<" ";
	// 	p = p->next;
	// }
	// cout<<endl;
	print_list(deleteDuplicates(head));
	return 0;
}
























