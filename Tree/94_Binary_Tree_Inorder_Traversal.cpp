#include <iostream>
#include <vector>
#include <stack>
using namespace std;
/**
 * 94. Binary Tree Inorder Traversal
 * 二叉树的中序遍历
*/

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
vector<int> res;

vector<int> inorderTraversal1(TreeNode *root)
{
	if (!root)
		return {};
	else
	{
		inorderTraversal1(root->left);
		res.push_back(root->val);
		inorderTraversal1(root->right);
	}
	return res;
}

/**
 * 方法 2，不用静态变量
 **/
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

vector<int> inorderTraversal2(TreeNode *root)
{
	vector<int> res; //这个作用是传res
	midTraversal(root, res);
	return res;
}

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
				Q[++top] = p;
				p = p->left;
			}
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
 * 方法 3.2, 中序遍历二叉树，用栈的方法stack,思路和上面的一摸一样
 * */
vector<int> inorderTraversal3_2(TreeNode *root)
{
	vector<int> res;
	stack<TreeNode *> Q;
	TreeNode *p;
	if (!root)
		return {};
	p = root;
	while (!Q.empty() || p != NULL)
	{
		while (p != nullptr)
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

/**
 * 方法 4，使用Mirrors遍历来做，如果要求的空间复杂度要求是常数，那么Mirrors算法可以是最好的解决方式
 * 空间复杂度是O(1)常数，为什么是O(1)复杂度，递归或者是非递归版本使用的是栈来保存前驱或者是后继节点
 * Morris方法中不需要为每个节点额外分配指针指向其前驱（predecessor）和后继节点（successor），
 * 只需要利用叶子节点中的左右空指针指向某种顺序遍历下的前驱节点或后继节点就可以了。
*/
vector<int> inorderTraversal4(TreeNode *root)
{
	vector<int> res;
	if (!root)
		return res;
	TreeNode *cur, *pre;
	cur = root;
	while (cur)
	{
		if (!cur->left)
		{
			res.push_back(cur->val);
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
				res.push_back(cur->val);
				cur = cur->right;
			}
		}
	}
	return res;
}

/**
 * 方法 5，使用Mirrors中序遍历来做，只用O(1)空间
 * 参考链接：https://www.cnblogs.com/anniekim/archive/2013/06/15/morristraversal.html
 * 1、判断当前节点的左孩子是不是为空，如果是空的话就输出当前节点并更新当前节点为右孩子节点
 * 2、如果当前节点的左孩子不是空节点，那么就找到当前节点的前驱节点
 * 		2-1、如果前驱节点的右子树是空，把前驱节点的右孩子设置为当前节点；当前节点更新为当前节点的左子节点
 * 		2-2、如果前驱节点的右子树是当前节点，那么把右子树设置为空，同时输出当前节点，当前节点更新为当前节点右孩子节点
 * 3、重复上面1-2步骤
*/
void inorderTraversal5(TreeNode *root)
{
	TreeNode *cur = root, *pre = NULL;
	while (cur) // 当前节点是否存在
	{
		if (!cur->left)
		{
			cout << cur->val << endl;
			cur = cur->right;
		}
		else
		{
			// TreeNode *pre = cur->left; // 当前节点的左子树
			pre = cur->left;

			while (pre->right && pre->right != cur)
				pre = pre->right;
			if (pre->right == NULL)
			{
				pre->right = cur;
				cur = cur->left;
			}
			else
			{
				pre->right = NULL;
				cout << cur->val << endl;
				cur = cur->right;
			}
		}
	}
}

/**
 * 深度优先遍历包括前序，中序，后续
*/
// 前序遍历
void preorder_s(TreeNode *root)
{
	if (root == nullptr)
		return;
	cout << root->val << " ";
	preorder_s(root->left);
	preorder_s(root->right);
}

// 中序遍历
void inorder_s(TreeNode *root)
{
	if (root == nullptr)
		return;

	inorder_s(root->left);
	cout << root->val << " ";
	inorder_s(root->right);
}

// 后序遍历
void postorder_s(TreeNode *root)
{
	if (root == nullptr)
		return;
	postorder_s(root->left);
	postorder_s(root->right);
	cout << root->val << " ";
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
	// rest = inorderTraversal3_2(head);
	// for (auto i : rest)
	// 	cout << i << " ";
	// return 0;

	// preorder_s(head);
	cout << endl;
	// inorder_s(head);
	cout << endl;
	// postorder_s(head);
	// for (auto i : inorderTraversal4(head))
	// {
	// 	cout << i << " ";
	// }
	inorderTraversal5(head);
}