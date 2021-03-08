#include <iostream>
#include <vector>
#include <stack>
using namespace std;
/**
 * 144. Binary Tree Preorder Traversal
 * 二叉树的前序遍历方法
*/

struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/**
 * 方法 1，使用递归来做
*/
void dfs(TreeNode *root, vector<int> &res)
{
	if (!root)
		return;
	else
	{
		res.push_back(root->val);
		dfs(root->left, res);
		dfs(root->right, res);
	}
}

vector<int> preorderTraversal(TreeNode *root)
{
	vector<int> res;
	dfs(root, res);
	return res;
}

/**
 * 方法 2，使用迭代来做，用栈
 * 先把左子树全部放到栈里面，然后拿出栈顶元素，
 * 找到栈顶元素的右子树开始遍历即可
*/
vector<int> preorderTraversal2(TreeNode *root)
{
	vector<int> res;
	stack<TreeNode *> stk;
	// 是否根节点不是空或者栈不是空
	while (root || stk.size())
	{
		// 根节点不是空
		while (root)
		{
			res.push_back(root->val); // 先把所有的根节点存到res
			stk.push(root);			  // 栈保存该节点
			root = root->left;		  // 继续遍历下一个节点即可
		}
		root = stk.top()->right; // 找到栈顶元素的右节点
		stk.pop();				 // 同时栈顶元素删除
	}
	return res;
}

int main()
{
	TreeNode *head = new TreeNode(3);
	TreeNode *h1 = new TreeNode(9);
	TreeNode *h2 = new TreeNode(20);
	TreeNode *h3 = new TreeNode(15);
	TreeNode *h4 = new TreeNode(7);
	head->left = h1;
	head->right = h2;
	h2->left = h3;
	h2->right = h4;
	vector<int> rest;
	rest = preorderTraversal(head);
	for (auto i : rest)
		cout << i << " ";

	return 0;
}
