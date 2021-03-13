#include <iostream>
#include <vector>
using namespace std;

/**
 * 297 序列化二叉树
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution
{
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode *root)
    {
        string str = "";
        dfs(root, str);
        return str;
    }

    void dfs(TreeNode *root, string &str)
    {
        if (!root)
        {
            str += "#,";
            return;
        }
        str += to_string(root->val) + ',';
        dfs(root->left, str);
        dfs(root->right, str);
    }

    // Decodes your encoded data to tree.
    TreeNode *deserialize(string data)
    {
        int u = 0;
        return dfs_t(data, u);
    }

    TreeNode *dfs_t(string &data, int &u)
    {
        if (data[u] == '#')
        {
            u += 2;
            return nullptr;
        }
        else
        {
            int k = u;
            while (data[u] != ',')
                u++;
            auto root = new TreeNode(stoi(data.substr(k, u - k)));
            u++;
            root->left = dfs_t(data, u);
            root->right = dfs_t(data, u);
            return root;
        }
    }
};