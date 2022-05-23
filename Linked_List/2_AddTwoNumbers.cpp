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
 */

struct ListNode
{
	int val;
	ListNode *next; // 定义一个指针是可以的
	ListNode(int x) : val(x), next(NULL) {}
};

void print_list(struct ListNode *head);

/**
 * 方法 1，创建一个新的链表，然后逐位相加即可，这里要注意进位，
 * 是否进位，怎么进位，进位是否传递等方法
 * 和方法 2相比，多了进位判断，就是下文注释掉的if-else语句，
 * 可以直接用carry = sumValue / 10;来代替
 * 这样写法就很简单。时间复杂度是O(n)，空间是O(max(m,n))；
 * 
 * 虚拟头结点很重要
*/
ListNode *addTwoNumbers1(ListNode *l1, ListNode *l2)
{
	int carry = 0;
	ListNode *p1 = l1, *p2 = l2;
	ListNode *head = new ListNode(0); // 开始建立一个头结点，最后返回这个头结点的下一个链表作为开头；
	ListNode *cur = head;
	while (p1 && p2)
	{
		int tempSum = p1->val + p2->val + carry;
		carry = tempSum / 10;
		ListNode *temp = new ListNode(tempSum % 10);
		head->next = temp;
		head = temp;
		p1 = p1->next;
		p2 = p2->next;
	}
	while (p1)
	{
		int p1Sum = p1->val + carry;
		p1->val = p1Sum % 10;

		carry = p1Sum / 10;
		head->next = p1;
		head = p1;
		p1 = p1->next;
	}
	while (p2)
	{
		int p2Sum = p2->val + carry;
		p2->val = p2Sum % 10;
		carry = p2Sum / 10;
		head->next = p2;
		head = p2;
		p2 = p2->next;
	}
	if (carry)
	{
		head->next = new ListNode(carry);
	}
	return cur->next;
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

/**
 * 方法 2，思路和方法 1 一样，但是写法更加简单，不用考虑进位传递问题，省略掉了if-else
*/
ListNode *addTwoNumbers2(ListNode *l1, ListNode *l2)
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
 * 方法 3，非常简洁的写法，代码优雅
*/
ListNode *addTwoNum3(ListNode *l1, ListNode *l2)
{
	ListNode *dummy = new ListNode(-1), *cur = dummy;
	int t = 0;
	while (l1 || l2 || t)
	{
		if (l1)
			t += l1->val, l1 = l1->next;
		if (l2)
			t += l2->val, l2 = l2->next;
		cur->next = new ListNode(t % 10);
		cur = cur->next;
		t /= 10;
	}
	return dummy->next;
}

ListNode *addTwoNum4(ListNode *l1, ListNode *l2)
{
    if(l1==nullptr) return l2;
    if(l2==nullptr) return l1;
    ListNode *p1 = l1, *p2 = l2;
    int carry = 0, sum = 0;
    ListNode *dummy = new ListNode(-1);
    ListNode*cur = dummy;

    while(p1 && p2){
        sum = p1->val + p2->val + carry;
        cur->next = new ListNode(sum % 10);
        carry = sum / 10;
        cur = cur->next;
        p1 = p1->next;
        p2 = p2->next;
        
    }
    while(p1){
        sum = p1->val + carry;
        cur->next = new ListNode(sum % 10);
        carry = sum / 10;
        cur = cur->next;
        p1 = p1->next;
    }

    while(p2){
        sum = p2->val + carry;
        cur->next = new ListNode(sum % 10);
        carry = sum / 10;
        cur = cur->next;
        p2 = p2->next;
    }

    if(carry != 0) {
        cur->next = new ListNode(carry);
    }
    return dummy->next;
}

int main()
{
	// 链表 1生成过程
	// ListNode *c1 = new ListNode(3);
	// ListNode *b1 = new ListNode(8);
	ListNode *a1 = new ListNode(1);
	ListNode *head1 = a1;
	// a1->next = b1;
	// b1->next = c1;

	// 链表 2生成过程
	// ListNode *c2 = new ListNode(4);
	ListNode *b2 = new ListNode(8);
	ListNode *a2 = new ListNode(9);
	ListNode *head2 = a2;
	a2->next = b2;
	// b2->next = c2;

	ListNode *before = NULL;
	print_list(head1);
	print_list(head2);

	// Solution s;
	// before = s.addTwoNumbers(head1,head2);
	// before = addTwoNum(head1,head2);
	// before = addTwoNumbers1(head1, head2);
    before = addTwoNum5(head1, head2);
	print_list(before);
	return 0;
}
