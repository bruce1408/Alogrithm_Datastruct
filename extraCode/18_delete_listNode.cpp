/*
	删除节点，用两个指针，一个是下一个节点，一个是指向当前节点；
	注意第一个结点如何删除。非常重要
*/

#include<iostream>
#include<vector>
#include<string>
using namespace std;

/*
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

}

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
//method 1 删除指定val值的节点，时间复杂度较高(因为涉及查找)，用两个指针，注意第一个节点的删除。不过不是赋值后在链接，而是直接删除即可。
void deleteNode1(ListNode* head,int key)
{
	if(!head)
		return ;
	ListNode*cur = head;
	ListNode*pre = NULL; //可以用来判断是否删除第一个节点

	while(cur)//先查找，一个之前当前，一个指向前驱
	{
		if(cur->val==key)
			break;
		pre = cur;
		cur= cur->next;
	}

	if(pre==NULL) //判断是否是删除第一个结点，如果是，就直接删除，接下一个节点即可，否则，正常删除
		head = cur->next;
	else
		pre->next = cur->next;

	print_list(head);
	cout<<endl;
}


//method 2 节点作为参数，不过要注意尾节点的处理
void deleteNode2(ListNode* node,ListNode* head)
{
	if(node->next!=nullptr) //判断不是尾节点的情况
	{
		node->val = node->next->val; //把值复制过来之后，让当前的指向下一个next即可
		ListNode *tmp = node->next;
		node->next = tmp->next;
		delete tmp;
	}

	else   //尾节点的情况
	{
		ListNode* cur = head;
		while(cur->next!=node)
		{
			cur = cur->next;
		}
		cur->next= NULL;
		delete node;
		node=nullptr;
	}

	print_list(head);
	cout<<endl;

}


//相关题目1：除去重复节点的数,但是不删除重复项
ListNode* delete_deplicateNode(ListNode*head)
{
	if (!head || !head->next) return head;

	ListNode *start = head;
	while (start && start->next)
	{
		if (start->val == start->next->val)
		{
			ListNode *tmp = start->next;
			start->next = start->next->next;
			delete tmp;
		} else start = start->next;
	}
	return head;
}


//相关题目2：删除重复项，都删除，注意头指针；这道题对于头指针会变的，要加一个头指针来定位！
/*删除重复节点的情况很经典。*/
// ListNode* delete_deplicateNode(ListNode*head)
// {
//
// 	if(!head || !head->next)
// 		return head;
// 	ListNode*start = new ListNode(0);
// 	start->next = head;
// 	ListNode* pre = start;
// 	while(pre->next)
// 	{
// 		ListNode*cur = pre->next;
// 		while(cur->next && cur->next->val==cur->val)
// 			cur = cur->next;
// 		if(cur!=pre->next) pre->next = cur->next;
// 		else pre = pre->next;
// 	}
// 	return head;
// }

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



	ListNode* p = head;
	print_list(p);
	cout<<endl;

	// //method1
	// cout<<endl;
	// cout<<"选择删除的节点是："<<endl;
	// int key;
	// cin>>key;
	// cout<<"删除节点之后"<<endl;
	// deleteNode1(head,key);


	//method 2
	// deleteNode2(node7,head);

	// 重复节点删除
	ListNode* q;
	q = delete_deplicateNode(head);

	return 0;
}
