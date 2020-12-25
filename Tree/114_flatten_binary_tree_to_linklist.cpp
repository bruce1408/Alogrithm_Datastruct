#include <iostream>
#include <vector>
using namespace std;

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
 * 把一可二叉树转换成链表类型结构
 * 不是转换成链表，而是让树没有左子树，
 * 
 * 
 * 
    1
   / \
  2   5
 / \   \
3   4   6

上面的树转换成下面的结果；
 1
 \
  2
   \
    3
     \
      4
       \
        5
         \
          6
* 如果是这个节点有左子树，那么遍历左子树的最右节点，
* 然后把这个最右节点连到root->right,root->right连接到左子树的开头，然后在让root = root->right 继续向右遍历
* 参考如下：
https://leetcode.com/problems/flatten-binary-tree-to-linked-list/discuss/36977/My-short-post-order-traversal-Java-solution-for-share
*/

class Solution
{
public:
    void flatten(TreeNode *root)
    {
        while (root)
        {
            TreeNode *p = root->left;
            if (p)
            {
                while (p->right)
                    p = p->right;
                p->right = root->right;
                root->right = root->left;
                root->left = nullptr;
            }
            root = root->right;
        }
    }
};
