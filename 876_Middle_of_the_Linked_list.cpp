#include<iostream>
#include<vector>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x):val(x),next(NULL) {}
};

// 方法一；基本的思路，就是遍历连表，然后长度len/2 得到中间的那个节点，但是忘记了用快慢指针！
int middleNode(ListNode* node)
{
    int count=0;
    if(!node) return 0;
    ListNode *p;
    p = node;
    while(p)
    {
        p = p->next;
        count++;
    }
    p = node;
    count = count/2;
    while(count--)
    {
        p = p->next;
    }
    return p->val;
}

// 方法二，利用快慢指针，快指针两步，慢指针一步。最终慢指针的地方就是中点！
int middleNode2(ListNode*node)
{
    ListNode* slow = node;
    ListNode* fast=node;
    while(fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow->val;
}
int main()
{
    ListNode* head = new ListNode(1);
    ListNode* node2 = new ListNode(2);
    ListNode* node3 = new ListNode(3);
    ListNode* node4 = new ListNode(4);
    ListNode* node5 = new ListNode(3);
    ListNode* node6 = new ListNode(2);
    ListNode* node7 = new ListNode(1);
    head->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;
    node5->next = node6;
    node6->next = node7;
    cout<<middleNode2(head)<<endl;

}



