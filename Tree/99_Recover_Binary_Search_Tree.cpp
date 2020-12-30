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
  * 参考98
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
 * 在Mirror遍历的基础上加上3个指针，first，second, parent，cur永远指向的是当前节点
 * first 表示第一个逆序数，second表示二个逆序数，parent表示当前节点的父节点；
 * 首先Morris遍历
 * 1、如果当前节点的左孩子时空，那么就把其右孩子当做当前节点，同时判断是否存在父节点且父节点的值大于当前节点的值，那么就找到了逆序对；
 *   然后看是否first之前存在，如果不存在，first 和 second 分别保存父节点和当前节点作为一对逆序对，如果first存在，那么就保存当前节点作为第二个
 *   逆序数即可
 * 2、如果当前节点左孩子不是空，那么就在左子树中找到他的前驱节点；左子树一路沿着右孩子遍历即可
 *    2-1、如果当前前驱节点的右孩子是空的，那么就把右孩子设置为当前节点，同时当前节点更新为当前节点的左孩子
 *    2-2、如果当前前驱节点的右孩子不是空，且他是当前节点，那么右孩子重新设置为空，然后看父节点是不是大于当前节点的值，如果父节点大于当前节点的值；那么
 *         就找到第二对逆序数，同时判断之前first是否存在，如果存在的话就second为当前节点，否则，first，second分别为父节点和当前节点即可
*/
void recoverTree2(TreeNode *root)
{
    TreeNode *cur = root, *first = NULL, *second = NULL, *pre = NULL, *parent = nullptr; // parent保存的是父节点
    while (cur)
    {
        if (!cur->left)
        {
            if (parent && parent->val > cur->val)
            {
                if (!first)
                    first = parent, second = cur;
                else
                    second = cur;
            }
            parent = cur;
            cur = cur->right;
        }
        else
        {
            pre = cur->left;
            while (pre->right && pre->right != cur)
                pre = pre->right;
            if (!pre->right)
            {
                pre->right = cur;
                cur = cur->left;
            }
            else if (pre->right == cur)
            {
                pre->right = NULL;
                if (parent && parent->val > cur->val)
                {
                    if (!first)
                        first = parent, second = cur;
                    else
                        second = cur;
                }
                parent = cur;
                cur = cur->right;
            }
        }
    }
    swap(first->val, second->val);
}
