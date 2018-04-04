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
	
	if(before == NULL)//如果是开头删除的话
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