#include <iostream>
#include <vector>
using namespace std;
/**
 * 链表的反转
 * 核心的思想是一个工作指针p、一个rear指针初始值设为NULL,还有一个从后往前指的指针before。
*/
struct ListNode
{
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

void print_list(ListNode *head);
/**
 * 方法 1，不带头结点，直接反转链表，链表反转算法：不带头结点的写法,需要三个指针，一个当前cur，一个rear，一个pre。
*/
ListNode *reverseList1(ListNode *pHead)
{
	if (pHead == NULL || pHead->next == NULL)
		return pHead;
	ListNode *rear = NULL;
	ListNode *cur = pHead;
	ListNode *pre = pHead;
	while (cur)
	{
		pre = cur;
		cur = cur->next; //工作指针
		pre->next = rear;
		rear = pre;
	}
	return rear;
}

/**
 * 方法 2，带头结点的写法,temp指针来保存cur 的下一个地址即可，推荐使用这种清晰的思路；
 * 秘诀就是首个节点指向下一个的下一个节点；然后中间隔开的那个节点要进行临时保存；
*/
ListNode *reverseList2(ListNode *head)
{
	if (head == nullptr)
		return head;
	ListNode *dummy = new ListNode(-1);
	dummy->next = head;
	ListNode *cur = head;
	while (cur->next)
	{
		ListNode *p = cur->next;
		cur->next = p->next;
		p->next = dummy->next;
		dummy->next = p;
	}
	return dummy->next;
}

/**
 * 方法 3，yxc推荐使用没有头节点的算法：
 * 使用两个相邻的指针来维护，一个从头指针开始a，一个从头指针的下一位开始b，
 * 然后每次后面的指针指向前一位，b->next = a;然后两个指针向后移动一位；
*/
ListNode *reverseList3(ListNode *head)
{
	if (head == nullptr)
		return head;
	ListNode *a = head, *b = a->next;
	while (b)
	{
		ListNode *c = b->next;
		b->next = a;
		a = b;
		b = c; // b要指向自己的下一位，所以一开始设c保存b的初始位置
	}
	head->next = nullptr;
	return a;
}
/**
 * 方法 4，使用递归的话，在方法 3的基础上做一个黑盒测试即可
 * reverseList4函数就是翻转head作为头结点的链表，然后返回的是
 * 最后一个节点，也是翻转之后的第一个节点；
 * 		1->2->3->4->5 翻转之前
 * 
 * 		1         2<-3<-4<-5  翻转之后
 * 		head   head->next
 * 
 * 然后把head->next->next  = head，也就是2的指向1，然后1next指向NULL
 * head->next = nullptr即可
*/
ListNode *reverseList4(ListNode *head)
{
	if (head == nullptr || head->next == nullptr)
		return head;

	// 这个函数以head为头结点翻转
	auto tail = reverseList4(head->next); // 返回翻转之后的头指针
	head->next->next = head;			  // 原来链表断开的地方指向head，然后head指向空即可
	head->next = nullptr;
	return tail;
}

ListNode *reverseListNode(ListNode* head){
    if(head == nullptr) return head;
    ListNode* dummy = new ListNode(-1);
    dummy->next = head;
    ListNode*cur = head;
    while(cur->next){
        ListNode*temp = cur->next;
        cur->next = temp->next;
        temp->next = dummy->next;
        dummy->next = temp;
    }
    return dummy->next;
}

// 递归的方法来反转链表
ListNode *reverseList(ListNode *head)
{
    if(head->next==nullptr || head==nullptr) return head;
    ListNode *t1 = reverseList(head->next);
    ListNode *l1 = head->next;
    l1->next = head;
    head->next = nullptr;
    return t1;
}

int main()
{
	//自己造一个回文链表

	ListNode *a1 = new ListNode(1);
	ListNode *a2 = new ListNode(2);
	ListNode *a3 = new ListNode(3);
	ListNode *a4 = new ListNode(4);
	ListNode *a5 = new ListNode(5);
	a1->next = a2;
	a2->next = a3;
	a3->next = a4;
	a4->next = a5;

	print_list(a1);
	// print_list(ReverseList(a1));
	// print_list(reverseList4(a1));
    print_list(reverseListNode(a1));
	delete a1;
	delete a2;
	delete a3;
	delete a4;
	delete a5;
	return 0;
}

//打印部分：
void print_list(ListNode *head)
{
	while (head)
	{
		cout << head->val << "->";
		head = head->next;
	}
	cout << "end" << endl;
}
