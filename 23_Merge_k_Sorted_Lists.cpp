#include<iostream>
#include<vector>
using namespace std;

struct ListNode{
    int val;
    ListNode * next;
    ListNode(int x):val(x),next(NULL){}
};

// 两个链表的合并
ListNode* mergeListNode(ListNode *l1,ListNode *l2)
{
    ListNode *res = new ListNode(-1);
    ListNode * cur = res;
    while(l1&&l2)
    {
        if(l1->val<l2->val)
        {
            cur->next = l1;
            l1=l1->next;
        }
        else
        {
            cur->next = l2;
            l2 = l2->next;
        }
        cur = cur->next;
    }
    cur->next = l1?l1:l2;
    return res->next;
}

// 分治法，k个链表的合并的方式
// 用5举例 0和3构成0，1和4构成1，那么正好2没有参与合并，就是2，所以下面k+1 就是给这个做铺垫
ListNode* mergeKLists(vector<ListNode*> &lists)
{
    if(lists.size()==0) return nullptr;
    int n = lists.size();
    while(n>1)
    {
        int k = (n+1)/2; // 考虑到n如果是奇数的话，如果不加1，那么处理起来会很麻烦
        for(int i=0;i<n;i++)
        {
            lists[i] = mergeListNode(lists[i],lists[i+k]); 
        }
        n = k;
    }
    return lists[0];
}
int main()
{
    ListNode *a = new ListNode(-1);
    return 0;
}