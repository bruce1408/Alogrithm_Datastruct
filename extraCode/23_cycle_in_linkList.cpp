#include<iostream>
#include<vector>
using namespace std;

/**
 * 题目：链表中环的入口，一个链表中包含环，如何找到环的入口
 * 方法1 两个指针，顺带计算了环的长度！
 * 思路：
 * 快、慢指针即可，如果有环的话，那么一定存在交点，然后给一个标志位isCycle为2，除了第一次相遇在头指针，以后计算环的长度就只能相遇两次，
 * 只要标志位不是2，那么说明相遇了，所以后面环的长度自加1，到第二次相遇，标志位清零退出循环，如果退出循环发现标志位还是2，那么说明根本没有环，直接返回NULL
 * 如果是有环，我们计算的环的长度多算了一次，在下一步让快慢指针都从头开始，快指针走环的长度步，这个时候和慢指针一起每次只走一步，如果相遇，那么直接退出，这个
 * 相遇的点就是环的入口节点
*/
struct ListNode
{
	int val;
	ListNode *next;
	ListNode(int x):val(x),next(nullptr){}
};

// 方法1 利用快慢双指针，
ListNode *entryListNode(ListNode * head)
{
	if(head == nullptr) return nullptr;
	ListNode *fast = head, *slow = head;
	int cycleLength = 0;
	int isCycle = 2;
	while(isCycle && fast->next->next) // 此部分还计算了环的长度
	{
		slow = slow->next;
		fast = fast->next->next;
		if(slow == fast) isCycle--; //第一次相遇
		if(isCycle != 2) cycleLength++; // 第一次相遇之后的每次加1操作
	}
	if(isCycle==2) return nullptr; // 没有环，直接退出，否则下面是有环的操作
	cycleLength -= 1;
	slow = head, fast = head;
	for(int i=0;i<cycleLength;i++) fast = fast->next;
	while(slow != fast)
	{
		slow = slow->next;
		fast = fast->next;
	}
	return slow;
}

// 方法2 利用两个指针，但是不用计算环的长度，当两个指针除了头指针外的第一次相遇时，慢指针开始从头指针出发，和快指针每次只走一步，下一次相遇点就是环的入口！
ListNode *entryListNode1(ListNode *head)
{
	if(head==nullptr) return nullptr;
	ListNode *slow = head, *fast = head;
	while(fast && fast->next)
	{
		slow = slow->next;
		fast = fast->next->next;
		if(slow == fast) break;
	}
	if(!fast || !fast->next) return nullptr; // 如果没有环，就直接退出

	slow = head;
	while(fast!=slow)
	{
		slow = slow ->next;
		fast = fast->next;
	}
	return fast;
}

int main()
{
	ListNode* head = new ListNode(1);
    ListNode* node2 = new ListNode(2);
    ListNode* node3 = new ListNode(3);
    ListNode* node4 = new ListNode(4);
    ListNode* node5 = new ListNode(5);
    ListNode* node6 = new ListNode(6);
	
    head->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;
    node5->next = node6;
	node6->next = node3;
	
	cout<<entryListNode(head)->val<<endl;
	
	return 0;
}