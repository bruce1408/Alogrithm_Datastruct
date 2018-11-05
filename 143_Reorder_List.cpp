#include<iostream>
#include<vector>
using namespace std;
/**
 * 这一道题是重新排列链表，
 * Given a singly linked list L: L0→L1→…→Ln-1→Ln,
 * reorder it to: L0→Ln→L1→Ln-1→L2→Ln-2→…
 * 思路就是中间截成两断，然后后面那一段倒排序，再一次插入到第一段相应的节点
 * */
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


ListNode* reorder(ListNode * head)
{
    if(!head) return nullptr;
    ListNode *slow = head;
    ListNode *fast = head;
    // 寻找中间的节点 
    while(fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    ListNode *aft = slow->next;
    slow->next = nullptr;

    ListNode *aftcur = aft;
    ListNode *aftrear = nullptr;
    ListNode *aftpre =aft;
    // 反转后一半的节点
    while(aftcur)
    {
        aftpre = aftcur;
        aftcur = aftcur->next;
        aftpre->next = aftrear;
        aftrear = aftpre;
    }
    slow = head;
    print_list(slow);
    print_list(aftrear);
    // 开始合并了
    while(slow && aftrear)
    {
        ListNode * cur = slow->next;
        slow->next = aftrear;
        aftrear = aftrear->next;
        slow->next->next = cur;
        slow = cur;
    }
    print_list(head);
    return head;

}


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
	// Solution s;
    // s.reorderList(a1);
	// print_list(a1);
    reorder(a1);
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















