#include <iostream>
#include <cstring>
using namespace std;

/** 
 * 82 删除所有的重复元素
 * Input: 1->2->3->3->4->4->5
 * Output: 1->2->5
 * 删除一个单链表的重复节点,只要是重复的都删除；
 * 1->1->1->2->3->4
 * 2->3->4
*/

struct ListNode
{
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

void print_list(struct ListNode *head);

/**
 * 方法 1，使用两层while循环判断,推荐解法，
 * 找一个步长是1的节点之间的关系即可，
 * 用before和cur两个节点，因为可能开头的元素就是要删除的元素，
 * 所以设置头结点，每次遍历before这个节点，before后面的设置cur节点，
 * 让子节点cur开始走，如果cur到while循环结束，它的前一个节点还是before
 * 那就相当于before子链cur没有重复数字，接着遍历，否则，有重复数字，
 * before->next = cur->next;这一句是关键。
 */
ListNode *deleteDuplicates(ListNode *head)
{
	ListNode *dummy = new ListNode(-1);
	dummy->next = head;
	ListNode *cur = dummy;
	while (cur->next)
	{
		auto q = cur->next;
		while (q && q->val == cur->next->val)
			q = q->next;
		if (cur->next->next == q) // 如果长度是1那么就cur后移一位即可
			cur = cur->next;
		else // 如果中间间隔了好几个重复的数字，直接指向q即可
			cur->next = q;
	}
	return dummy->next;
}

/**
 * 方法 2，看图说话，两层while循环，如果找到相同的节点，
 * 那么进入第二层while循环，判断到底是有多少个相同的节点，然后开始把这些节点删除即可。
 * 边界条件需要考虑多种情况，比较麻烦，需要一一举例测试一下
 * 比如：
 * [1,1,2], [1,2,2,3], [1,2,2], [1,1,2,2,3,3]
 */
ListNode *deleteDuplicates2(ListNode *head)
{
	ListNode *cur = head, *pre = head;
	ListNode *dummy = new ListNode(-1);
	ListNode *before = dummy;
	dummy->next = head;
	while (cur && cur->next)
	{
		pre = cur->next;
		if (cur->val == pre->val)
		{
			ListNode *tmp = pre;
			while (tmp)
			{
				if (cur->val == tmp->val)
					tmp = tmp->next;
				else
				{
					before->next = tmp;
					cur = tmp;
					break;
				}
			}
			cur = before;
			before->next = tmp;
		}
		else
		{
			before = cur;
			cur = cur->next;
		}
	}
	if (cur)
		return dummy->next;
	else
		return before == dummy ? NULL : before;
}

/**
 * 方法 3，使用递归来做。教科书解法，这个就更仙儿了，思路挺好的，但是不容易想到递归的结束条件，还有递归设计。
 * 思路是开头有重复的话那么直接把开头重复的全部删除，然后返回一个开头不是重复的节点，再来判断后面的链表是否重复，
 * 总之有点像是切三段，掐头去尾来做。
*/
ListNode *deleteDuplicates3(ListNode *head)
{
	if (!head || !head->next)
		return head;
	if (head->next && head->next->val == head->val)
	{
		while (head->next && head->val == head->next->val) // 开头重复
			head = head->next;
		return deleteDuplicates3(head->next); // 中间重复
	}
	head->next = deleteDuplicates3(head->next); // 尾部重复
	return head;
}

int main()
{
	ListNode *head = new ListNode(1);
	ListNode *node2 = new ListNode(1);
	ListNode *node3 = new ListNode(2);
	ListNode *node4 = new ListNode(3);
	ListNode *node5 = new ListNode(3);
	ListNode *node6 = new ListNode(3);
	ListNode *node7 = new ListNode(3);

	head->next = node2;
	node2->next = node3;
	node3->next = node4;
	node4->next = node5;
	node5->next = node6;
	node6->next = node7;
	print_list(head);
	print_list(deleteDuplicates3(head));
	return 0;
}

void print_list(struct ListNode *head)
{
	while (head)
	{
		cout << head->val << "->";
		head = head->next;
	}
	cout << "end" << endl;
}