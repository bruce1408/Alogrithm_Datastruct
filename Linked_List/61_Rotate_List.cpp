#include<iostream>
using namespace std;
// 思路就是构成环，不用加一个哑结点，直接循环技术即可。
struct ListNode
{
    int val;
    ListNode *next;
    ListNode (int x):val(x),next(NULL) {}
} ;

ListNode *rotateRight(ListNode *head, int k) {
    if (!head) return NULL;
    int n = 1;
    ListNode *cur = head;
    while (cur->next) {
        ++n;
        cur = cur->next;
    }
    cur->next = head;
    int m = n - k % n;
    for (int i = 0; i < m; ++i) {
        cur = cur->next;
    }
    ListNode *newhead = cur->next;
    cur->next = NULL; // 其实是前一位的数字变成nullptr；这个没有指向其他的关系，就是当前next域为空 
    return newhead;
}


void print_list(struct ListNode *head)
{
	while(head)
	{
		cout<<head->val<<"->";
		head = head->next;
	}
	cout<<"end"<<endl;
}

int main()
{

    ListNode *a1 = new ListNode(1);   
    ListNode *a2 = new ListNode(2);   
    ListNode *a3 = new ListNode(3);   
    ListNode *a4 = new ListNode(4);   
    ListNode *a5 = new ListNode(5);
    ListNode *head = a1;
    a1->next = a2;   
    a2->next = a3;   
    a3->next = a4;   
    a4->next = a5;   
    print_list(rotateRight(a1,2));
    return 0;
}



ListNode* rotateRight(ListNode*head, int k)
{
    if(!head) return nullptr;
    ListNode * cur = head;
    int n=1;
    while(cur->next)
    {
        ++n;
        cur = cur->next;
    }
    cur->next = head;
    int m = n-k%n;
    for(int i = 0;i<m;i++)
    {
        cur = cur->next;
    }
    ListNode *newhead = cur->next;
    cur->next = nullptr;
    return newhead;
}