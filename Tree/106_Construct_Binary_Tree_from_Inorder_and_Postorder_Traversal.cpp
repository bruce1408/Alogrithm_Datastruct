#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

/**
 * 106
 * Given preorder and inorder traversal of a tree, construct the binary tree.
 * Note:
 * You may assume that duplicates do not exist in the tree.
 * For example, given
 * posterder = [3,9,20,15,7]
 * inorder = [9,3,15,20,7]
 * Return the following binary tree:
 * 
 *   3
 *  / \
 *  9  20
 *  /  \
 *  15   7
 * 重构一颗二叉树
 * 给定中序遍历和后序遍历，然后重构一颗二叉树
*/

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
 * 方法 1，就是使用递归来做，然后按照后序的最后一位就是根节点来做，把中序分成两部分，左子树和右子树，然后继续递归求解，
 * 左子树分成中序和后序，右子树分成中序和后序，知道递归终止条件为止
*/
TreeNode *create1(vector<int> &inorder, vector<int> &postorder, int postL, int postR, int inL, int inR)
{
    if (postL > postR)
        return nullptr;
    TreeNode *root = new TreeNode;
    root->val = postorder[postR];
    int k;
    for (k = inL; k <= inR; k++)
    {
        if (root->val == inorder[k])
        {
            break;
        }
    }
    int numLeft = k - inL;
    root->left = create1(inorder, postorder, postL, postL + numLeft - 1, inL, k - 1);
    root->right = create1(inorder, postorder, postL + numLeft, postR - 1, k + 1, inR);
    return root;
}

TreeNode *buildTree(vector<int> inorder, vector<int> &postorder)
{
    int postL = 0, postR = postorder.size() - 1;
    int inL = 0, inR = inorder.size() - 1;
    return create1(inorder, postorder, postL, postR, inL, inR);
}

// 先序遍历打印二叉树
void precout(TreeNode *root)
{
    if (root == nullptr)
        return;
    precout(root->left);
    precout(root->right);
    cout << root->val << " ";
}

int main()
{
    vector<int> posterder = {9, 15, 7, 20, 3};
    vector<int> inorder = {9, 3, 15, 20, 7};
    precout(buildTree(inorder, posterder));
}