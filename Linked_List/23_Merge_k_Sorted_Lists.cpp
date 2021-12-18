#include <iostream>
#include <vector>
#include <queue>
using namespace std;

/**
 * Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.
 * Example:
 * 
 * Input:
 * [
 *   1->4->5,
 *   1->3->4,
 *   2->6
 * ]
 * Output: 1->1->2->3->4->4->5->6
 * 
 * 把k个有序链表合并成一个链表即可；
*/
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

/**
 * 方法 1，使用分治法来做这道题，k个链表的合并的方式。
 * 可以使用两两合并的方式，但是时间复杂度太高，无法通过，可以使用对半合并，
 * 和幂次计算一样，使用对半来做分治法。比如先对k/2个链表进行合并，再不停的往下划分。
 * 直到最后只有一个或者两个链表的时候合并即可。
 * 举例子来说比如合并6个链表，那么按照分治法，
 * 首先分别合并0和3，1和4，2和5。这样下一次只需合并3个链表，再合并1和3，最后和2合并就可以了。
 * 代码中的k是通过 (n+1)/2 计算的，这里为啥要加1呢，这是为了当n为奇数的时候，k能始终从后半段开始，
 * 比如当 n=5 时，那么此时 k=3，则0和3合并，1和4合并，最中间的2空出来。当n是偶数的时候，加1也不会有影响，
 * 比如当 n=4 时，此时 k=2，那么0和2合并，1和3合并
 */

ListNode *mergeListNode(ListNode *l1, ListNode *l2)
{
    ListNode *res = new ListNode(-1);
    ListNode *cur = res;
    while (l1 && l2)
    {
        if (l1->val < l2->val)
        {
            cur->next = l1;
            l1 = l1->next;
        }
        else
        {
            cur->next = l2;
            l2 = l2->next;
        }
        cur = cur->next;
    }
    cur->next = l1 ? l1 : l2;
    return res->next;
}

ListNode *mergeKLists(vector<ListNode *> &lists)
{
    if (lists.size() == 0)
        return nullptr;
    int n = lists.size();
    while (n > 1)
    {
        int k = (n + 1) / 2; // 参考归并排序的方法。
        for (int i = 0; i < n && i + k < n; i++)
        {
            lists[i] = mergeListNode(lists[i], lists[i + k]);
        }
        n = k;
    }
    return lists[0];
}

/**
 * 方法 2，使用最小堆来解决问题，首先把k个链表的首元素都加入最小堆中,
 * 会自动排好序,然后每次取出最小的那个元素加入最终结果的链表中，
 * 然后把取出元素的下一个元素再加入堆中，下次仍从堆中取出最小的元素做相同的操作，
 * 以此类推，直到堆中没有元素了，此时k个链表也合并为了一个链表，返回首节点即可。
 * 最小堆参考堆相关知识
*/
ListNode *mergeKLists2(vector<ListNode *> &lists)
{
    // 构建小根堆的一种方法
    // auto cmp = [](ListNode *&a, ListNode *&b) {
    //     return a->val > b->val;
    // };
    // priority_queue<ListNode *, vector<ListNode *>, decltype(cmp)> q(cmp); // 构成一个链表的最小堆

    struct cmp
    {
        bool operator()(ListNode *a, ListNode *b) // 重载运算符
        {
            return a->val > b->val;
        }
    };

    priority_queue<ListNode *, vector<ListNode *>, cmp> q; // 构成一个链表的最小堆

    for (auto node : lists)
    {
        if (node)
            q.push(node);
    }
    ListNode *dummy = new ListNode(-1), *cur = dummy;
    while (!q.empty())
    {
        auto t = q.top();
        q.pop();
        cur->next = t;
        cur = cur->next;
        if (cur->next)
            q.push(cur->next);
    }
    return dummy->next;
}

int main()
{
    ListNode *head1 = new ListNode(1);
    ListNode *a1 = new ListNode(2);
    ListNode *b1 = new ListNode(4);
    ListNode *c1 = new ListNode(6);
    head1->next = a1;
    a1->next = b1;
    b1->next = c1;

    ListNode *head2 = new ListNode(1);
    ListNode *a2 = new ListNode(3);
    ListNode *b2 = new ListNode(4);
    head2->next = a2;
    a2->next = b2;

    ListNode *head3 = new ListNode(2);
    ListNode *a3 = new ListNode(6);
    head3->next = a3;
    vector<ListNode *> res = {head1, head2, head3};
    ListNode *cur = mergeKLists2(res);
    while (cur)
    {
        cout << cur->val << " ";
        cur = cur->next;
    }
}