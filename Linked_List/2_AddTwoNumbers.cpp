#include <iostream>
#include <cmath>
using namespace std;
/**
 * Example:
 * Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
 * Output: 7 -> 0 -> 8
 * Explanation: 342 + 465 = 807.
 * 
 * 两个链表，然后相加，得到一个新的链表；
 * 我自己的这种方法不好，越做越复杂，网上的思路是对的，
 * 我这种思路有问题。
 */

struct ListNode
{
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

void print_list(struct ListNode *head);

/**
 * 方法 1，逐位相加即可
*/
ListNode *addTwoNumbers5(ListNode *l1, ListNode *l2)
{
	ListNode *p1 = l1, *p2 = l2;
	ListNode *head = p1, *current1 = p1, *current2 = p2;
	int preNum = 0;
	int sumBit = 0;
	while (p1 and p2)
	{
		current1 = p1;
		current2 = p2;
		int sum = p1->val + p2->val + sumBit;
		if (sum >= 10)
		{
			sumBit = sum / 10;
			sum = sum % 10;
		}
		preNum = p1->val;
		p1->val = sum;
		p1 = p1->next;
		p2 = p2->next;
	}
	if (p2)
	{
		current1->next = p2;
		p2->val += sumBit;
	}
	else if (p1)
	{
		p1->val += sumBit;
	}
	else if (sumBit != 0 && p1 == nullptr && p2 == nullptr)
	{

		if (preNum + current2->val >= 10)
		{
			ListNode *rear = new ListNode(sumBit);
			current1->next = rear;
		}
	}
	return head;
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

/*leetcode标准参考答案*/
/**
 * 方法 2
*/
ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
{
	int carry = 0;
	ListNode *res = new ListNode(0);
	ListNode *head = res;
	while (l1 && l2)
	{
		res->next = new ListNode((l1->val + l2->val + carry) % 10);
		carry = (l1->val + l2->val + carry) / 10;
		l1 = l1->next;
		l2 = l2->next;
		res = res->next;
	}
	while (l1)
	{
		res->next = new ListNode((l1->val + carry) % 10);
		carry = (l1->val + carry) / 10;
		l1 = l1->next;
		res = res->next;
	}
	while (l2)
	{
		res->next = new ListNode((l2->val + carry) % 10);
		carry = (l2->val + carry) / 10;
		l2 = l2->next;
		res = res->next;
	}
	// 最后考虑 carray 是否还有进位，如果有，就再增加一位；
	if (carry > 0)
	{
		res->next = new ListNode(carry);
	}
	return head->next;
}
/**
 * 方法 3，
*/
ListNode *addTwoNum(ListNode *l1, ListNode *l2)
{
	ListNode *result = new ListNode(0);
	ListNode *res = result;
	if (l1 == nullptr && l2 == nullptr)
		return nullptr;
	// if(l1==nullptr && l2!=nullptr) return l2;
	// else return l1;
	int carray = 0;
	while (l1 && l2)
	{
		int x = l1->val + l2->val + carray;
		carray = x / 10;
		ListNode *p = new ListNode(x % 10);
		result->next = p;
		result = p;
		l1 = l1->next;
		l2 = l2->next;
	}
	while (l1)
	{
		int x = l1->val + carray;
		carray = x / 10;
		ListNode *p = new ListNode(x % 10);
		result->next = p;
		result = p;
		l1 = l1->next;
	}
	return res->next;
}

int main()
{
	// ListNode *c1 = new ListNode(3);
	// ListNode *b1 = new ListNode(4);
	ListNode *a1 = new ListNode(0);
	ListNode *head1 = a1;
	// a1->next = b1;
	// b1->next = c1;

	// ListNode *c2 = new ListNode(4);
	ListNode *b2 = new ListNode(3);
	ListNode *a2 = new ListNode(7);
	ListNode *head2 = a2;
	a2->next = b2;
	// b2->next = c2;

	ListNode *before = NULL;
	print_list(head1);
	print_list(head2);

	// Solution s;
	// before = s.addTwoNumbers(head1,head2);
	// before = addTwoNum(head1,head2);
	before = addTwoNumbers5(head1, head2);
	print_list(before);
	return 0;
}
