#include <iostream>
#include <vector>
using namespace std;
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

/**
 * 给定一个链表，然后顺序是从小到大，然后把链表转成一颗二叉树，
 * 二叉树题目和108题目相似，都是先找到中间点，中间点是二叉树的根节点，
 * 左边链表的部分是二叉树的左子树，右边的链表是二叉树的右子树，然后还是使用递归来做
*/

/**
 * 方法 1，使用108题目思路，把链表转化成数组，然后按照递归来做
*/
TreeNode *sortedListToBST(ListNode *head)
{

    ListNode *cur = head;
    vector<int> nums;
    while (cur)
    {
        nums.push_back(cur->val);
        cur = cur->next;
    }

    return build(nums, 0, nums.size() - 1);
}

TreeNode *build(vector<int> &nums, int l, int r)
{
    if (l > r)
        return nullptr;
    int mid = (l + r) >> 1;
    TreeNode *root = new TreeNode(nums[mid]);
    root->left = build(nums, l, mid - 1);
    root->right = build(nums, mid + 1, r);
    return root;
}

/**
 * 方法 2，直接使用链表来做，不用转化成数组。
 * 先遍历一遍链表，然后求出链表的总长度，然后再次遍历链表到中间节点的前一个节点，
 * 先写右边的节点，然后再写左边的节点，左边的末尾要指向空
 * 
 *   1->  2->  3->  4->  5
 *       cur  mid
 * 遍历的时候找的是cur，因为要找到mid的起一个节点，然后让
 * cur->next->next成为右子树的开头，cur->next=nullptr表示左子树的结尾和原来断开
 * 左子树的开头是head
*/
TreeNode *sortedListToBST(ListNode *head)
{
    int cnt = 0;
    ListNode *cur = head;
    while (cur)
    {
        cur = cur->next;
        cnt++;
    }
    cur = head;
    for (int i = 0; i < cnt / 2 - 1; i++)
        cur = cur->next;
    if (!head)
        return nullptr;
    if (cnt == 1)
        return new TreeNode(head->val);
    TreeNode *root = new TreeNode(cur->next->val);
    root->right = sortedListToBST(cur->next->next); // 右子树的区间
    cur->next = nullptr;                            // 右子树装完之后，左子树的最后一个节点设置为空
    root->left = sortedListToBST(head);             // 左子树从头开始到cur
    return root;
}
