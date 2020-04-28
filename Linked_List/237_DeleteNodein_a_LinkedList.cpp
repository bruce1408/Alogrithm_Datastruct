#include<iostream>
#include<cstring>
using namespace std;

/**
 * 删除一个单链表的某个结点
 * 1->2->3->4 变成 1->2->4
 * 
 * Input: head = [4,5,1,9], node = 5
 * Output: [4,1,9]
*/
struct ListNode
{
	int val;
	ListNode *next;
	ListNode (int x): val(x), next(NULL){}
};


/**
 * 方法 1,
*/
void deleteNode1(ListNode *node, int node)
{
	ListNode *head = new ListNode(-1);
	head ->next = node;
	ListNode *cur = head;
	while(cur->next)
	{
		if()
	}

}

int main()
{
    // 链表 1生成过程
    ListNode *c1 = new ListNode(4);
    ListNode *b1 = new ListNode(3);
    ListNode *a1 = new ListNode(1);
    ListNode *head1 = a1;
    a1->next = b1;
    b1->next = c1;

    print_list(head1);
	int node = 3;
    deleteNode1(head1, node);
    print_list(head1);
    return 0;
}
