#include<iostream>
#include<stack>
using namespace std;


struct ListNode
{
	int val;
	ListNode *next;
	ListNode(int x):val(x),next(NULL) {}
};



ListNode* reverseBetween(ListNode* root, int m, int n)
{
	int count1 = 1;
	ListNode* fir = root;
	ListNode* sec = root;
	stack<int> temp;
	while(count1<m)
	{
		count1++;
		fir = fir->next;
		sec = fir;
	}

	while(count1>=m && count1<=n)
	{
		temp.push(fir->val);
		fir = fir->next;
		count1++;
	}
	
	int flag = n-m;
	while(flag>=0)
	{
		sec->val = temp.top();
		temp.pop();
		sec = sec->next;
		flag--;
	}
	return root;
}

ListNode *reverseBetween(ListNode *head, int m, int n)
{
        ListNode *dummy = new ListNode(-1);
        dummy->next = head;
        ListNode *cur = dummy;
        ListNode *pre, *front, *last;
        for (int i = 1; i <= m - 1; ++i) cur = cur->next;
        pre = cur;
        last = cur->next;
        for (int i = m; i <= n; ++i) 
		{
            cur = pre->next;
            pre->next = cur->next;
            cur->next = front;
            front = cur;
        }
        cur = pre->next;
        pre->next = front;
        last->next = cur;
        return dummy->next;
    }



int main()
{
	int i;
	ListNode *e = new ListNode(5);
	ListNode *d = new ListNode(4);
	ListNode *c = new ListNode(3);
	ListNode *b = new ListNode(2);
	ListNode *a = new ListNode(1);
	ListNode *head = a;
	a->next = b;
	b->next = c;
	c->next = d;
	d->next = e;

	
	ListNode *p ;
	
	p = reverseBetween(head,2,4);
	while(p!=NULL)
	{
		cout<<p->val;
		cout<<" ";
		p = p->next;
	}
	
	return 0;
	
}