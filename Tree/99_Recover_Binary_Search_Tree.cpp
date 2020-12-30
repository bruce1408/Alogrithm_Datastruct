#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

/**
  * 99_给定一颗二叉树搜索树的根节点root ，该树中的两个节点被错误地交换。请在不改变其结构的情况下，恢复这棵树。
  * 
*/

/**
 * 方法 1，中序遍历，并将所有节点存到一个一维向量中，把所有节点值存到另一个一维向量中，然后对存节点值的一维向量排序，在将排好的数组按顺序赋给节点
 * 但是使用了O(n)的空间，不满足题目要求
*/
void inorder(TreeNode *root, vector<int> &vals, vector<TreeNode *> &newTree)
{
    if (!root)
        return;
    inorder(root->left, vals, newTree);
    newTree.push_back(root);
    vals.push_back(root->val);
    inorder(root->right, vals, newTree);
}

void recoverTree(TreeNode *root)
{
    vector<TreeNode *> newTree;
    vector<int> vals;
    inorder(root, vals, newTree);
    sort(vals.begin(), vals.end());
    for (int i = 0; i < vals.size(); i++)
    {
        newTree[i]->val = vals[i];
    }
}

/**
 * 方法 2，使用中序遍历来做，但是要满足常数空间，只能是用Mirrors遍历来做
 * 在Mirror遍历的基础上加上3个指针，first， parent，second；
*/
void recoverTree2(TreeNode *root)
{
    TreeNode *cur = root, *pre = NULL, *first = NULL;
    while (cur)
    {
        if (!cur->left) 
        {
            cout<<cur->val;
            cur = cur->right;
        }
        else
        {
            pre = cur->left;
            while (pre && pre->right)
                pre = pre->right;
            if (!pre->right)
            {
                pre->right = cur;
                cur = cur->right;
            }
            else if (pre->right == cur)
            {
                pre->right = NULL;
                cur = cur->right;
            }
        }
    }
}
