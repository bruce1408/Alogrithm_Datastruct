/*找出两个链表的交集，(链表的值是数字，不是其他类型的)
  这个前提是已经排好序了，然后利用下面的算法来找，
  */
// #include<iostream>
// using namespace std;


// struct linkList
// {
	// int val;
	// linkList *next;
// };

// void printf_list(struct linkList *u);
// int main()
// {
	// linkList d1 = {4,NULL};
	// linkList c1 = {3,&d1};
	// linkList b1 = {2,&c1};
	// linkList a1 = {1,&b1};
	// linkList *head1 = &a1;
	// linkList*p1 = head1;
	
	// linkList c2 = {4,NULL};
	// linkList b2 = {3,&c2};
	// linkList a2 = {2,&b2};
	// linkList *head2 = &a2;
	// linkList*p2 = head2;
	
	// //打印出两个链表的值
	// printf_list(p1);
	// printf_list(p2);
	
	// /*找出两组链表的交集：*/
	// while(p1&&p2)
	// {
		// if(p1->val==p2->val)
		// {
			// cout<<p1->val<<" ";
			// p1 = p1->next;
			// p2 = p2->next;
		// }
		// else if(p1->val>p2->val)
		// {
			// p2 = p2->next;
		// }
		// else
		// {p1 = p1->next;}
	// }
	// return 0;
// }
// void printf_list(struct linkList *u)//输出链表的函数
// {
	// while(u)
	// {
		// cout<<u->val<<"->";
		// u = u->next;
	// }
	// cout<<"end"<<endl;
	
// }



/*找出两个链表的交集，(链表的值是数字，不是其他类型的)
  这个前提是已经排好序了，然后利用下面的算法来找，
  */
#include<iostream>
using namespace std;


struct linkList
{
	string val;
	linkList *next;
};

void printf_list(struct linkList *u);

int main()
{
	//生成第一个链表
	linkList e1 = {"c3",NULL};
	linkList d1 = {"c2",&e1};
	linkList c1 = {"c1",&d1};
	linkList b1 = {"a2",&c1};
	linkList a1 = {"a1",&b1};
	linkList *head1 = &a1;
	linkList*p1 = head1;
	
	
	//生成第二个链表
	linkList f2 = {"c3",NULL};
	linkList e2 = {"c2",&f2};
	linkList d2 = {"c1",&e2};
	linkList c2 = {"b3",&d2};
	linkList b2 = {"b2",&c2};
	linkList a2 = {"b1",&b2};
	linkList *head2 = &a2;
	linkList*p2 = head2;
	
	//打印出两个链表的值
	cout<<"两个链表的如下："<<endl;
	printf_list(p1);
	printf_list(p2);
	
	/*找出两组链表的交集：*/
	while(p1&&p2)
	{
		if(p1->val==p2->val)
		{
			cout<<p1->val<<"->";
			p1 = p1->next;
			p2 = p2->next;
		}
		else if(p1->val>p2->val)
		{
			p2 = p2->next;
		}
		else
		{p1 = p1->next;}
		
	
	}
	
	cout<<"end"<<endl;
	
	
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


//2019-3-5 第一是比较长度,然后是长度长的那个减去短的，差值进行循环。
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
{
	ListNode *a = headA, *b = headB;
	int lena = getLength(a), lenb = getLength(b);
	if(lena < lenb)
	{
		for (int i=0;i<lenb-lena;i++)
		{
			b = b->next;
		}
	}
	else
	{
		for (int i=0;i<lena-lenb;i++)
		{
			a = a ->next;
		}
	}

	while(a && b && a!=b)
	{
		a = a->next;
		b = b->next;
	}
	return (a && b)? a : NULL;
}
int getLength(ListNode *head)
{
	int cnt=0;
	while(head)
	{
		head = head->next;
		cnt+=1;
	}
	return cnt;
}


// 方法二是利用环的思想。
ListNode *getIntersectionNode1(ListNode *headA, ListNode *headB)
{
	if(!headA || !headB) return NULL;// 边界条件给忘了？
	ListNode *a = headA, *b = headB;
	while(a!=b)
	{
		a = a? a->next:headB;
		b = b? b->next:headA;
	}
	return a;
	
}
