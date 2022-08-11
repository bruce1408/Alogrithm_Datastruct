#include <iostream>
#include <vector>
#include <unordered_map>
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
 *    3
 *   / \
 *  9  20
 *    /  \
 *   15   7
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
    // 这里是为了在中序遍历中找到前序遍历的根节点的位置
    int k;
    for (k = inL; k <= inR; k++)
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

TreeNode *buildTree1(vector<int> &preorder, vector<int> &inorder)
{
    int preL = 0, preR = preorder.size() - 1;
    int inL = 0, inR = inorder.size() - 1;
    return create(preorder, inorder, preL, preR, inL, inR);
}

/**
 * 方法 2，使用中序遍历和后序遍历重建一颗二叉树
*/
TreeNode *create1(vector<int> &postorder, vector<int> &inorder, int postL, int postR, int inL, int inR)
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
    root->left = create1(postorder, inorder, postL, postL + numLeft - 1, inL, k - 1);
    root->right = create1(postorder, inorder, postL + numLeft, postR - 1, k + 1, inR);
    return root;
}

TreeNode *buildTree2(vector<int> postorder, vector<int> &inorder)
{
    int postL = 0, postR = postorder.size() - 1;
    int inL = 0, inR = inorder.size() - 1;
    return create1(postorder, inorder, postL, postR, inL, inR);
}

/**
 * 方法 3，使用unordered_map来节省计算，但是本质思路都是一样的
*/
TreeNode *helper(vector<int> &preorder, vector<int> &inorder, int prestart, int instart, int inend, unordered_map<int, int> &m)
{
    if (instart > inend)
        return NULL;
    TreeNode *root = new TreeNode(preorder[prestart]);
    int index = m[preorder[prestart]]; // 这个就是根节点

    root->left = helper(preorder, inorder, prestart + 1, instart, index - 1, m);
    root->right = helper(preorder, inorder, prestart + 1 + (index - instart), index + 1, inend, m); // 括号这一项可以看成是左子树节点的个数

    return root;
}

TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
{
    unordered_map<int, int> m;
    for (int i = 0; i < inorder.size(); i++)
        m[inorder[i]] = i;
    return helper(preorder, inorder, 0, 0, inorder.size() - 1, m);
}

/**
 * 方法 4，使用哈希表来记录中序遍历每一个数的位置，把O(n)时间降到O(1)
 * 所以哈希保存的是中序的值对应的下标
*/
class Solution
{
public:
    unordered_map<int, int> pos;
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        for (int i = 0; i < inorder.size(); i++)
            pos[inorder[i]] = i;
        return build(preorder, inorder, 0, preorder.size() - 1, 0, inorder.size() - 1);
    }

    TreeNode *build(vector<int> &preorder, vector<int> &inorder, int pl, int pr, int il, int ir)
    {
        if (pl > pr)
            return nullptr;
        auto root = new TreeNode(preorder[pl]);
        int k = pos[root->val]; // 画图最好解释
        root->left = build(preorder, inorder, pl + 1, pl + 1 + k - 1 - il, il, k - 1);
        root->right = build(preorder, inorder, pl + 1 + k - 1 - il + 1, pr, k + 1, ir);
        return root;
    }
};

int main()
{
    vector<int> preorder = {3, 9, 20, 15, 7};
    vector<int> inorder = {9, 3, 15, 20, 7};
    precout(buildTree1(preorder, inorder));
}