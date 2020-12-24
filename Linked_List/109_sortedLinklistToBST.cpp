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
*/
TreeNode *sortedListToBST1(ListNode *head)
{
    
    


}