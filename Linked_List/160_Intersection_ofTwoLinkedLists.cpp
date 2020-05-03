#include <iostream>
using namespace std;
/**
 * Write a program to find the node at which the intersection of two singly linked lists begins.
 * 找出两个单链表的交集的开始节点
*/

struct ListNode
{
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

void printf_list(ListNode *u);

/**
 * 方法 1，假设这个单链表是升序排列的，找出两组链表的交集：
 * 但是本题目不是升序排列的，所以这个方法不可取；
 */
ListNode *getIntersectionNode1(ListNode *headA, ListNode *headB)
{
	ListNode *p1 = headA, *p2 = headB;
	while (p1 && p2)
	{
		if (p1->val == p2->val)
		{
			return p1;
		}
		else if (p1->val > p2->val)
		{
			p2 = p2->next;
		}
		else
		{
			p1 = p1->next;
		}
	}
	return nullptr;
}

int main()
{
	ListNode *d1 = new ListNode(4);
	ListNode *c1 = new ListNode(3);
	ListNode *b1 = new ListNode(2);
	ListNode *a1 = new ListNode(1);
	ListNode *head1 = a1;
	ListNode *p1 = head1;
	a1->next = b1;
	b1->next = c1;
	c1->next = d1;

	ListNode *c2 = new ListNode(4);
	ListNode *b2 = new ListNode(3);
	ListNode *a2 = new ListNode(2);
	a2->next = b2;
	b2->next = c2;

	ListNode *head2 = a2;
	ListNode *p2 = head2;

	//打印出两个链表的值
	printf_list(p1);
	printf_list(p2);
	getIntersectionNode1(p1, p2);
	return 0;
}

void printf_list(ListNode *u) //输出链表的函数
{
	while (u)
	{
		cout << u->val << "->";
		u = u->next;
	}
	cout << "end" << endl;
}

/*找出两个链表的交集，(链表的值是数字，不是其他类型的)
  这个前提是已经排好序了，然后利用下面的算法来找，
  */
// #include<iostream>
// using namespace std;
// struct linkList
// {
// 	string val;
// 	linkList *next;
// };

// void printf_list(struct linkList *u);

// int main()
// {
// 	//生成第一个链表
// 	linkList e1 = {"c3",NULL};
// 	linkList d1 = {"c2",&e1};
// 	linkList c1 = {"c1",&d1};
// 	linkList b1 = {"a2",&c1};
// 	linkList a1 = {"a1",&b1};
// 	linkList *head1 = &a1;
// 	linkList*p1 = head1;

// 	//生成第二个链表
// 	linkList f2 = {"c3",NULL};
// 	linkList e2 = {"c2",&f2};
// 	linkList d2 = {"c1",&e2};
// 	linkList c2 = {"b3",&d2};
// 	linkList b2 = {"b2",&c2};
// 	linkList a2 = {"b1",&b2};
// 	linkList *head2 = &a2;
// 	linkList*p2 = head2;

// 	//打印出两个链表的值
// 	cout<<"两个链表的如下："<<endl;
// 	printf_list(p1);
// 	printf_list(p2);

// 	/*找出两组链表的交集：*/
// 	while(p1&&p2)
// 	{
// 		if(p1->val==p2->val)
// 		{
// 			cout<<p1->val<<"->";
// 			p1 = p1->next;
// 			p2 = p2->next;
// 		}
// 		else if(p1->val>p2->val)
// 		{
// 			p2 = p2->next;
// 		}
// 		else
// 		{p1 = p1->next;}

// 	}

// 	cout<<"end"<<endl;

// 	return 0;

// }

// void printf_list(struct linkList *u)//输出链表的函数
// {
// 	while(u)
// 	{
// 		cout<<u->val<<"->";
// 		u = u->next;
// 	}
// 	cout<<"end"<<endl;

// }

// //2019-3-5 第一是比较长度,然后是长度长的那个减去短的，差值进行循环。
// ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
// {
// 	ListNode *a = headA, *b = headB;
// 	int lena = getLength(a), lenb = getLength(b);
// 	if(lena < lenb)
// 	{
// 		for (int i=0;i<lenb-lena;i++)
// 		{
// 			b = b->next;
// 		}
// 	}
// 	else
// 	{
// 		for (int i=0;i<lena-lenb;i++)
// 		{
// 			a = a ->next;
// 		}
// 	}

// 	while(a && b && a!=b)
// 	{
// 		a = a->next;
// 		b = b->next;
// 	}
// 	return (a && b)? a : NULL;
// }

// int getLength(ListNode *head)
// {
// 	int cnt=0;
// 	while(head)
// 	{
// 		head = head->next;
// 		cnt+=1;
// 	}
// 	return cnt;
// }

// // 方法二是利用环的思想。
// ListNode *getIntersectionNode1(ListNode *headA, ListNode *headB)
// {
// 	if(!headA || !headB) return NULL;// 边界条件给忘了？
// 	ListNode *a = headA, *b = headB;
// 	while(a!=b)
// 	{
// 		a = a? a->next:headB;
// 		b = b? b->next:headA;
// 	}
// 	return a;

// }
