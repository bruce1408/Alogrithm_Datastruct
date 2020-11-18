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

/**
 * 方法 2，使用的是长度比较法，第一是比较两个链表的长度,然后是长度长的那个减去短的，长的链表从差值处开始和
 * 短的链表进行循环。不过链表的交点不是数值相同
 */
int getLength(ListNode *head)
{
	int cnt = 0;
	while (head)
	{
		head = head->next;
		cnt += 1;
	}
	return cnt;
}

ListNode *getIntersectionNode2(ListNode *headA, ListNode *headB)
{
	ListNode *a = headA, *b = headB;
	int lena = getLength(a), lenb = getLength(b);
	if (lena < lenb)
	{
		for (int i = 0; i < lenb - lena; i++)
			b = b->next;
	}
	else
	{
		for (int i = 0; i < lena - lenb; i++)
			a = a->next;
	}
	while (a && b && a != b)
	{
		a = a->next;
		b = b->next;
	}
	return (a && b) ? a : NULL;
}

/**
 * 方法 3，利用环来做
*/
ListNode *getIntersectionNode2_1(ListNode *headA, ListNode *headB)
{
	ListNode *pA = headA, *pB = headB;
	bool continueA = false, continueB = false;
	if (pA == NULL || pB == NULL)
		return NULL;
	while ((pA != NULL) && (pB != NULL))
	{
		if (pA->val == pB->val)
			break;
		pA = pA->next;
		pB = pB->next;

		if (pA == NULL)
		{
			if (continueA)
				break;
			pA = headB;
			continueA = true;
		}
		if (pB == NULL)
		{
			if (continueB)
				break;
			pB = headA;
			continueB = true;
		}
	}
	return pA;
}

/**
 * 方法 3，是利用环的思想。最经典的方法
 * 题目中强调了链表中不存在环，但是我们可以用环的思想来做，
 * 我们让两条链表分别从各自的开头开始往后遍历，当其中一条遍历到末尾时，我们跳到另一个条链表的开头继续遍历。
 * 两个指针最终会相等，而且只有两种情况，一种情况是在交点处相遇，另一种情况是在各自的末尾的空节点处相等。
 * 为什么一定会相等呢，因为两个指针走过的路程相同，是两个链表的长度之和，所以一定会相等。
 * 
 * 比如是
 * a = 4   1 8 4 5
 * b = 5 0 1 8 4 5
 * 如果a 和 b 都走完了，那么a 走 b的长度，b 走 a的长度
 * 如下：
 * a = 4   1 8 4 5 | 5 0 1 8 4 5
 * b = 5 0 1 8 4 5 | 4   1 8 4 5
 * 那么a b 走的路径长度之和一样。最后知道知道a b 链表相同的即可，记住不是val值相同。
 */
ListNode *getIntersectionNode3(ListNode *headA, ListNode *headB)
{
	if (!headA || !headB)
		return NULL; // 边界条件给忘了？
	ListNode *a = headA, *b = headB;
	while (a != b)
	{
		a = a ? a->next : headB;
		b = b ? b->next : headA;

		// 等价的写法
		// if(a) a = a->next;
		// else a = headB;
		// if(b) b = b->next ;
		// else b = headA;
	}
	return a;
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
	cout << getIntersectionNode2_1(p1, p2)->val << endl;
	return 0;
}
