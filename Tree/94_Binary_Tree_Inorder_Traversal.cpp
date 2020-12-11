/**
 * 94. Binary Tree Inorder Traversal
 * 二叉树的中序遍历
*/

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/**
 * 方法1：使用递归的方式，但是res每次递归的时候要重建，所以索性把
 * res变成静态变量。或者是其他方法。比如方法2
 * */
class Solution1
{
public:
	vector<int> inorderTraversal(TreeNode *root)
	{
		if (!root)
			return {};
		else
		{
			inorderTraversal(root->left);
			res.push_back(root->val);
			inorderTraversal(root->right);
		}
		return res;
	}

private: //加了静态变量，res每次都在
	vector<int> res;
};

/**
 * 方法 2，不用静态变量
 * */
class Solution2
{
public:
	void midTraversal(TreeNode *root, vector<int> &res) //res必须加上引用
	{
		if (!root)
			return;
		else
		{
			midTraversal(root->left, res);
			res.push_back(root->val);
			midTraversal(root->right, res);
		}
	}

	vector<int> inorderTraversal(TreeNode *root)
	{
		vector<int> res; //这个作用是传res
		midTraversal(root, res);
		return res;
	}
};

/**
 * 方法 3.1, 中序遍历二叉树，利用迭代的方法,而没有使用递归来遍历二叉树
 * */
vector<int> inorderTraversal3_1(TreeNode *root)
{
	vector<int> res;
	TreeNode *p;
	vector<TreeNode *> Q(20, 0);
	int top = -1;
	if (root != NULL)
	{
		p = root;
		while (top > -1 || p != NULL)
		{
			while (p != NULL)
			{
				cout << "p value: " << p->val << endl;
				Q[++top] = p;
				cout << "top: " << top << endl;
				p = p->left;
			}
			cout << top << endl;
			if (top > -1)
			{
				p = Q[top--];
				res.push_back(p->val);
				p = p->right;
			}
		}
	}
	return res;
}

/**
 * 方法 3.2, 用栈的方法stack,思路和上面的一摸一样
 * */
vector<int> inorderTraversal3_2(TreeNode *root)
{
	vector<int> res;
	stack<TreeNode *> Q;
	TreeNode *p;
	if (!root) return {};
	p = root;
	while (!Q.empty() || p!=NULL)
	{
		while (p)
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
		}
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
	rest = inorderTraversal3_2(head);
	for (auto i : rest)
		cout << i << " ";
	return 0;
}