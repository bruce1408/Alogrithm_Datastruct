#include <iostream>
#include <vector>
using namespace std;

/**
  * 给定一颗树，然后返回这棵树是否是二叉搜索树
  * Input:
  *     2
  *    / \
  *   1   3
  * Output: true
  * 左边节点的值都要小于根节点的值，右边节点的值都要大于根节点的值
  **/

/**
  * 方法 1，使用深度优先搜索来做，一棵树，判断是否是二叉搜索树，根据定义来判断
  * 左边子树的最大值小于根节点，右边子树的最小值大于根节点
 */
bool isValidBST(TreeNode *root)
{
    if (!root)
        return true;
    return dfs(root)[0]; // 设置一个数组，记录当前的三个状态，分别表示当前节点是否是二叉树，左子树最大的值，右子树最小的值
}

vector<int> dfs(TreeNode *root)
{
    vector<int> res = {1, root->val, root->val}; // 初始化设置这个二叉树状态数组
    if (root->left)                              // 该节点的左子树存在
    {
        auto lt = dfs(root->left);        // 递归左子树，返回其状态数组
        if (!lt[0] || lt[2] >= root->val) // 如果左子树不满足二叉树，或者是最大值比父节点要大，那么该节点不满足，状态置0
            res[0] = 0;
        res[1] = min(res[1], lt[1]); // 更新该节点的最小值
        res[2] = max(res[2], lt[2]); // 更新该节点的最大值
    }

    // 右子树同理
    if (root->right)
    {
        auto rt = dfs(root->right);
        if (!rt[0] || rt[1] <= root->val)
            res[0] = 0;
        res[1] = min(res[1], rt[1]);
        res[2] = max(res[2], rt[2]);
    }
    return res;
}

/**
 * 方法 2，和上面的思路一样，使用dfs来做，写法略有不同
*/
bool isValidBST(TreeNode *root)
{
    if (!root)
        return true;
    return dfs(root, LONG_MIN, LONG_MAX); // 设置两个数，分别是系统最小值和最大值
}

bool dfs(TreeNode *root, int ln, int rn)
{
    if (!root)
        return true;
    if (ln <= root->val || root->val >= rn)
        return false;
    return dfs(root->left, ln, roo->val) && dfs(root->right, root->val, rn);
}

/**
 * 方法 3，使用Mirrors树遍历，属于非递归不用栈的遍历方法
*/
bool isValidBST(TreeNode *root)
{
    if (!root)
        return true;
    TreeNode *cur = root, *pre, *parent = NULL;
    bool res = true;
    while (cur) // cur不为空
    {
        if (!cur->left) // 没有左子树，将cur指向右子节点
        {
            if (parent && parent->val >= cur->val)
                res = false;
            parent = cur;
            cur = cur->right;
        }
        else // 将pre指向cur的左子树中的最右子节点
        {
            pre = cur->left;
            while (pre->right && pre->right != cur)
                pre = pre->right;
            if (!pre->right) // 如果pre不存在右子节点
            {
                pre->right = cur; // 右子节点指回cur
                cur = cur->left;  // cur指向其左子节点
            }
            else
            {
                pre->right = NULL; // pre右子节点置空
                if (parent->val >= cur->val)
                    res = false;
                parent = cur;
                cur = cur->right; // cur指向右子节点
            }
        }
    }
    return res;
}