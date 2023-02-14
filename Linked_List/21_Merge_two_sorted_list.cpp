#include <iostream>
#include <vector>
using namespace std;

/**
 * Merge two sorted linked lists and return it as a new list.
 * The new list should be made by splicing together the nodes of the first two lists.
 * 
 * Example:
 * Input: 1->2->4, 1->3->4
 * Output: 1->1->2->3->4->4
 * 
 * 给定两个升序排列的链表，然后他们合并成一个新的升序排列的链表即可；
*/
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

/**
 * 打印链表函数
*/
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
 * 方法 1，两个链表直接进行合并
 * */
ListNode *mergeTwoLists0(ListNode *l1, ListNode *l2)
{
    if(!l1 || !l2){
        return l1==nullptr? l2:l1;
    }

    ListNode* head = new ListNode(-1);
    ListNode* cur = head;

    while(l1 && l2){
        if(l1->val < l2->val){
            cur->next = l1;
            l1 = l1->next;        
        }
        else {
            cur->next = l2;
            l2 = l2->next;
        }
        cur = cur->next;
    }

    // 最后这里因为是有序链表，直接合并即可
    cur->next = l1? l1 : l2;
    
    return head->next;
}

ListNode *mergeTwoLists1(ListNode *l1, ListNode *l2)
{
    if (!l1 || !l2)
        return l1 ? l1 : l2;
    if (l1->val < l2->val)
    {
        l1->next = mergeTwoLists1(l1->next, l2);
        return l1;
    }
    else
    {
        l2->next = mergeTwoLists1(l1, l2->next);
        return l2;
    }
}

ListNode *mergeTwoLists3(ListNode *l1, ListNode *l2)
{
    if(l1==nullptr) return l2;
    if(l2==nullptr) return l1;

    ListNode *dummy = new ListNode(-1);
    ListNode *cur = dummy;
    while(l1 && l2){
        // l1 小
        if(l1->val <= l2->val){
            cur->next = new ListNode(l1->val);
            l1 = l1->next;
        }
        else{
            cur->next = new ListNode(l2->val);
            l2 = l2->next;
        }
    }

    cur->next = l1==nullptr?l2:l1;
    return dummy->next;
}


/**
 * 方法 3，二路归并递归算法。
*/
// ListNode *mergeTwoLists3(ListNode *l1, ListNode *l2)
// {
//     if (!l1)
//         return l2;
//     if (!l2)
//         return l1;
//     ListNode *head = l1->val < l2->val ? l1 : l2;
//     ListNode *nonhead = l1->val < l2->val ? l2 : l1;
//     head->next = mergeTwoLists3(head->next, nonhead);
//     return head;
// }

int main()
{
    // 链表 1生成过程
    ListNode *c1 = new ListNode(4);
    ListNode *b1 = new ListNode(3);
    ListNode *a1 = new ListNode(1);
    ListNode *head1 = a1;
    a1->next = b1;
    b1->next = c1;

    // 链表 2生成过程
    ListNode *c2 = new ListNode(4);
    ListNode *b2 = new ListNode(2);
    ListNode *a2 = new ListNode(1);
    ListNode *head2 = a2;
    a2->next = b2;
    b2->next = c2;

    print_list(head1);
    print_list(head2);

    ListNode *before = mergeTwoLists0(head1, head2);
    print_list(before);
    return 0;
}
