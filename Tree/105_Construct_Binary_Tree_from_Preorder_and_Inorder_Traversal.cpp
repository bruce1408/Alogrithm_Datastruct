#include <iostream>
#include <vector>
using namespace std;

/**
 * 
 * Given preorder and inorder traversal of a tree, construct the binary tree.
 * Note:
 * You may assume that duplicates do not exist in the tree.
 * For example, given
 * preorder = [3,9,20,15,7]
 * inorder = [9,3,15,20,7]
 * Return the following binary tree:
 * 
 *   3
 *  / \
 *  9  20
 *  /  \
 *  15   7
 * 重构一颗二叉树
 * 给定中序遍历和前序遍历，然后重构一颗二叉树
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

// 先序遍历打印二叉树
void precout(TreeNode *root)
{
    if (root == nullptr)
        return;
    precout(root->left);
    precout(root->right);
    cout << root->val << " ";
}

/**
 * 方法 1，根据前序遍历和中序遍历的结果来做
*/
TreeNode *create(vector<int> &preorder, vector<int> &inorder, int preL, int preR, int inL, int inR)
{
    // 下标都是从0开始
    if (preL > preR)
        return nullptr;
    TreeNode *root = new TreeNode;
    root->val = preorder[preL]; // preL 即是根节点
    int k;
    for (k = inL; k < inR; k++)
    {
        if (inorder[k] == preorder[preL]) // 找到了根节点
        {
            break;
        }
    }
    int numLeft = k - inL; // 左子树的节点个数
    root->left = create(preorder, inorder, preL + 1, preL + numLeft, inL, k - 1);
    root->right = create(preorder, inorder, preL + numLeft + 1, preR, k + 1, inR);
    return root;
}

TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
{
    int preL = 0, preR = preorder.size() - 1;
    int inL = 0, inR = inorder.size() - 1;
    return create(preorder, inorder, preL, preR, inL, inR);
}

/**
 * 方法 2，使用中序遍历和后序遍历重建一颗二叉树
*/
create1(vector<int>&postorder, vector<int>&inorder, int postL, int postR, int inL, int inR)
{

}

TreeNode *buildTree2(vector<int>postorder, vector<int>&inorder)
{
    int postL = 0, postR = postorder.size()-1;
    inL = 0, inR = inorder.size()-1;
    return create1(postorder, inorder, postL, postR, inL, inR);
}

int main()
{
    vector<int> preorder = {3, 9, 20, 15, 7};
    vector<int> inorder = {9, 3, 15, 20, 7};
    precout(buildTree(preorder, inorder));
}