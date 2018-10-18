#include<iostream>
#include<vector>
using namespace std;
struct ListNode
{
	int val;
	ListNode *next;
	ListNode (int x):val(x),next(NULL){}
};
void print_list(ListNode *head);
class Solution {
public:
    void reorderList(ListNode *head) {
        if (!head || !head->next || !head->next->next) return;
        ListNode *fast = head;
        ListNode *slow = head;
        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode *mid = slow->next;
        slow->next = NULL;
        ListNode *last = mid;
        ListNode *pre = NULL;
        while (last) {
            ListNode *next = last->next;
            last->next = pre;
            pre = last;
            last = next;
        }
        while (head && pre) {
            ListNode *next = head->next;
            head->next = pre;
            pre = pre->next;
            head->next->next = next;
            head = next;
        }
    }
};
int main()
{
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
	Solution s;
    s.reorderList(a1);
	print_list(a1);
return 0;	
}

//打印部分：	
void print_list(struct ListNode *head)
{
	while(head)
	{
		cout<<head->val<<"->";
		head = head->next;
	}
	cout<<"end"<<endl;
}















