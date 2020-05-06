#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

/**
 * Given head which is a reference node to a singly-linked list. 
 * The value of each node in the linked list is either 0 or 1. 
 * The linked list holds the binary representation of a number.
*/
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

/**
 * 方法 1，使用的是一个数组，把这些数字都放进数组中，然后开始遍历
 * 时间复杂度和空间复杂度都是O(n)
*/
int getDecimalValue(ListNode *head)
{
    vector<int> res;
    int sumValue = 0;
    ListNode *cur = head;
    while (cur)
    {
        res.push_back(cur->val);
        cur = cur->next;
    }
    int n = res.size();
    for (int i = 0; i < n; i++)
    {
        int temp = pow(2, i);
        cout << "temp is: " << temp << endl;
        sumValue += res[n - i - 1] * temp;
    }
    return sumValue;
}

/**
 * 方法 2，时间复杂度是O(n)，空间不用新的数组了，其实和十进制是一样的；
*/
int getDecimalValue2(ListNode *head)
{
    if (head == NULL)
    {
        return 0;
    }
    int s = 0;
    while (head != NULL)
    {
        s = 2 * s + head->val;
        head = head->next;
    }
    return s;
}
int main()
{
    ListNode *c1 = new ListNode(0);
    ListNode *b1 = new ListNode(1);
    ListNode *a1 = new ListNode(1);
    a1->next = b1;
    b1->next = c1;
    ListNode *head1 = a1;
    cout << getDecimalValue2(head1) << endl;
}