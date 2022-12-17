#include <iostream>
#include <cstring>
#include <string.h>
using namespace std;
/**
 * 链表部分操作包括生成，遍历，查找，创建，插入，删除等
*/
struct linkList
{
	// char name[20];
	// string name;
	int age;
	linkList *next;
	linkList(int b) : age(b), next(NULL) {}
};

/**
 * 例题一：链表的创建,常规创建，使用链表构造函数来做
 */
// int main()
// {
// 	linkList *c = new linkList{"guest", 15};
// 	linkList *b = new linkList{"herry", 10};
// 	linkList *a = new linkList{"bruce", 5};
// 	linkList *head = a;
// 	linkList *p = head;
// 	a->next = b;
// 	b->next = c;

// 	while (p)
// 	{
// 		cout << p->name << "->" << p->age << "->";
// 		p = p->next;
// 	}
// 	cout << "end" << endl;
// 	return 0;
// }

/**
 * 链表创建方法 2，使用结构体，不用构造函数，后面均以第二种方法为准来说明
*/
// struct linkList
// {
// 	/**
// 	 * 定义结构体，name可以用string 也可以用 字符数组来定义
// 	*/
// 	// char name[20];
// 	string name;
// 	int age;
// 	linkList *next;
// };

// int main()
// {
// 	// 因为a, b, c 不是链表指针，head需要指向地址；
// 	linkList c = {"guest", 15, nullptr};
// 	linkList b = {"herry", 10, &c};
// 	linkList a = {"bruce", 5, &b};
// 	linkList *head = &a;
// 	linkList *p = head;

// 	while (p)
// 	{
// 		cout << p->name << "->" << p->age << "->";
// 		p = p->next;
// 	}
// 	cout << "end" << endl;
// 	return 0;
// }

/**
 * 例题二：链表的遍历和查找
 */
// int main()
// {
// 	bool isFalse = false;
// 	linkList c = {"guest", 15, NULL};
// 	linkList b = {"herry", 10, &c};
// 	linkList a = {"bruce", 5, &b};
// 	linkList *head = &a;
// 	linkList *p = head;
// 	while (p)
// 	{
// 		// if (p->name == "bruce")
// 		if (strcmp("bruce", p->name.c_str()) == 0)
// 		{
// 			cout << p->age << endl;
// 			isFalse = true;
// 			break;
// 		}
// 		p = p->next;
// 	}
// 	if (!isFalse)
// 		cout << "没有找到该元素：" << endl;
// 	return 0;
// }

/**
 * 例题三：链表的插入，我都是只用一个工作节点，所以自己的做法是
 * 工作节点之后的数值插入和删除。
 */
// int main()
// {
// 	linkList c = {"guest", 15, NULL};
// 	linkList b = {"herry", 10, &c};
// 	linkList a = {"bruce", 5, &b};
// 	linkList *head = &a;
// 	linkList *p = head;

// 	linkList x = {"Xname", 19, NULL}; //待插节点；
// 	while (p)
// 	{
// 		if (strcmp("bruce", p->name.c_str()) == 0) // 寻找插入节点,就是在bruce的后面节点插入
// 		{
// 			x.next = p->next;
// 			p->next = &x;
// 			cout << "yes" << endl;
// 			break;
// 		}
// 		p = p->next;
// 	}
// 	p = head;
// 	while (p)
// 	{
// 		cout << p->name << "->";
// 		p = p->next;
// 	}
// 	cout << "end" << endl;
// 	return 0;
// }

/**
 * 例题四：链表的删除，只用一个工作节点，一般是寻找删除节点的前一个节点来删除
 */

// int main()
// {
// 	linkList d = {"Xname", 19, NULL};
// 	linkList c = {"guest", 15, &d};
// 	linkList b = {"herry", 10, &c};
// 	linkList a = {"bruce", 5, &b};
// 	linkList *head = &a;
// 	linkList *p = head;
// 	while (p)
// 	{
// 		if (strcmp("herry", p->name.c_str()) == 0) // 寻找删除节点，在herry后面的节点删除
// 		{
// 			p->next = p->next->next;
// 		}
// 		p = p->next;
// 	}
// 	p = head;
// 	while (p)
// 	{
// 		cout << p->name << "->";
// 		p = p->next;
// 	}
// 	cout << "end" << endl;
// 	return 0;
// }

/**
 * 例题五：删除做法，书上的做法，用两个节点，一个之前一个，一个之后一个节点
 * 优点是删除谁就找谁，而一个节点的缺点是删除谁就要找到他的前一个节点。
 */
// int main()
// {
// 	linkList d = {"Xname", 19, NULL};
// 	linkList c = {"guest", 15, &d};
// 	linkList b = {"herry", 10, &c};
// 	linkList a = {"bruce", 5, &b};
// 	linkList *head = &a;
// 	linkList *p = head;
// 	linkList *before = NULL;
// 	while (p)
// 	{
// 		if (strcmp("herry", p->name.c_str()) == 0) // 寻找删除节点，在herry后面的节点删除
// 		{
// 			before->next = p->next;
// 		}
// 		before = p;
// 		p = p->next;
// 	}

// 	p = head;
// 	while (p)
// 	{
// 		cout << p->name << "->";
// 		p = p->next;
// 	}
// 	cout << "end" << endl;
// 	return 0;
// }

/**
 * 例题六：头部插入,头部插入的问题之一就是要判断头结点，给一个指针，如果
 * 该节点指针依旧是NULL的话，那么就应该是头结点插入，
 */

// int main()
// {
// 	linkList d = {"Xname",19,NULL};
// 	linkList c = {"guest",15,&d};
// 	linkList b = {"herry",10,&c};
// 	linkList a = {"bruce",5,&b};
// 	linkList *head =&a;
// 	linkList *p = head;
// 	linkList *before = NULL;

// 	linkList insertD = {"insertD",23,NULL};
// 	cout<<"请输入一个年龄：0-100之间"<<endl;
// 	cin>>insertD.age;

// 	while(p) /*寻找要插入结点位置*/
// 	{
// 		if(insertD.age<=p->age)// 寻找删除节点，在herry后面的节点删除
// 		{
// 			break;
// 		}
// 		before = p;
// 		p = p->next;
// 	}
// 	if(before==NULL) /*头结点插入，头结点没有next域。直接用head来赋值*/
// 	{
// 		insertD.next = head;
// 		head = &insertD;
// 	}
// 	else  /* 除了头结点之外的其他位置 */
// 	{
// 		insertD.next = p;
// 		before->next = &insertD;
// 	}
// 	p = head;
// 	while(p)
// 	{
// 		cout<<p->name<<"->"<<p->age<<"->";
// 		p = p->next;
// 	}
// 	cout<<"end"<<endl;
// 	return 0;
// }

int main()
{
	linkList *p, *head;
	int k = 4;
	head = new linkList(0);
	p = head;
	while (k > 0)
	{
		cout << k << endl;
		linkList *s = new linkList(k);
		p->next = s;
		p = s;
		k--;
	}
	cout << " after: " << endl;
	head = head->next;
	while (head)
	{
		cout << head->age << endl;
		head = head->next;
	}
}
