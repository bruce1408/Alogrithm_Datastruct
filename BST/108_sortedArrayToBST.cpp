#include <iostream>
using namespace std;

/**
 * 给定一个数组，然后构造一颗二叉搜索树，binarySearchTree
 * 左子节点小于根节点，右子节点大于根节点；
 * 最后还要是平衡的二叉搜索树 ，左右两个子树的高度差是1
*/

/**
 * 方法 1，
 * 因为是有序数组，所以中间的节点是二叉树的根节点，然后左边的都是他的左子树的节点，右边的数组都是右子树的节点
 * 使用递归来进行建树；主要是使用二分来做，中间节点作为根，左边和右边依次递归
*/
TreeNode *sortedArrayToBST(vector<int> &nums)
{
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
