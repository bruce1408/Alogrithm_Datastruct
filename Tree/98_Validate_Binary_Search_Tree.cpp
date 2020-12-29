#include <iostream>
#include <vector>
#include <stack>
using namespace std;
/**98. Validate Binary Search Tree 
 *    2
 *    / \
 *   1   3
 * Binary tree [2,1,3], return true.
 * 
 * Example 2:
 *     1
 *    / \
 *   2   3
 * Binary tree [1,2,3], return false.
 * 
 * */

struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
/**
 * 方法 1，使用非递归的中序遍历，用栈来实现
*/
bool isValidBST1(TreeNode *root)
{
	vector<int> res;
	TreeNode *p;
	stack<TreeNode *> Q;
	p = root;
	bool flag = true;
	while (p || !Q.empty())
	{
		while (p && flag)
		{
			Q.push(p);
			p = p->left;
		}
		if (!Q.empty())
		{
			p = Q.top();
			Q.pop();
			res.push_back(p->val);
			p = p->right;
			if (res.back() > Q.top()->val)
			{
				flag = false;
			}
		}
	}
	return flag;
}

/**
 * 方法 2，使用一个中序遍历，然后得到数组，只要不是按照升序排列的那么就不是二叉搜索树
*/
void inorder(vector<int> &res, TreeNode *root);
bool isValidBST2(TreeNode *root)
{
	vector<int> res;
	inorder(res, root);

	for (int i = 0; i < res.size() - 1; i++)
	{
		if (res[i] >= res[i + 1])
			return false;
	}
	return true;
}

void inorder(vector<int> &res, TreeNode *root)
{
	if (!root)
		return;
	inorder(res, root->left);
	res.push_back(root->val);
	inorder(res, root->right);
}

/**
 * 方法 3，使用深度优先搜索来做
 * 找到左子树的最大值，如果最大值大于等于父节点的值，不满足
 * 找到右子树的最小值，如果最小值大于等于父节点的值，不满足
 * 然后相应更新数组的最小值和最大值
*/
vector<int> dfs(TreeNode *root);
bool isValidBST3(TreeNode *root)
{
	if (!root)
		return true;
	return dfs(root)[0];
}

vector<int> dfs(TreeNode *root)
{
	vector<int> res = {1, root->val, root->val};
	if (root->left) // 左子树存在，找到左子树里面的最大值
	{
		auto t = dfs(root->left);		// 返回左子树中的结果数组
		if (!t[0] || root->val <= t[2]) // 如果第一个元素是空，或者说左子树最大的值大于父节点的值，那么就不是二叉树
			res[0] = 0;
		res[1] = min(res[1], t[1]); // 否则更新最小值和最大值的数值
		res[2] = max(res[2], t[2]);
	}

	if (root->right) // 返回右子树的结果数组，类似于上面左子树的判断，
	{
		auto t = dfs(root->right);
		if (!t[0] || t[1] <= root->val) // 这里要判断是右子树，找到右子树的最小值，要是最小值要与小于父节点，那么不满足二叉树
			res[0] = 0;
		res[1] = min(res[1], t[1]);
		res[2] = max(res[2], t[2]);
	}
	return res;
}

/**
 * 方法 4，使用dfs深度优先遍历
 * 思路和上面的方法 3相同，但是写法略有区别
 * */
bool dfs(TreeNode *root, long ln, long rn);
bool isValidBST(TreeNode *root)
{
	return dfs(root, LONG_MIN, LONG_MAX);
}

bool dfs(TreeNode *root, long ln, long rn)
{
	if (!root)
		return true;
	if (root->val <= ln || root->val >= rn)
		return false;
	return dfs(root->left, ln, root->val) && dfs(root->right, root->val, rn);
}

/**
 * 方法 5，使用Mirrors中序遍历算法，这个算法是空间复杂度是O(1)
 * 主要加一个parent指针，用来保存当前节点的左子树如果为空的话，那么parent记录右子树的父节点
*/
bool isValidBST5(TreeNode *root)
{
	if (!root)
		return true;
	TreeNode *cur = root, *pre, *parent = NULL;
	bool res = true;
	while (cur)
	{
		if (!cur->left)
		{
			if (parent && parent->val >= cur->val)
				res = false;
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
			else
			{
				pre->right = NULL;
				if (parent->val >= cur->val)
					res = false;
				parent = cur;
				cur = cur->right;
			}
		}
	}
	return res;
}

int main()
{
	TreeNode *head = new TreeNode(2);
	TreeNode *h1 = new TreeNode(1);
	TreeNode *h2 = new TreeNode(3);
	head->left = h1;
	head->right = h2;
	cout << isValidBST5(head) << endl;
	return 0;
}
