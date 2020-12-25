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
 * 方法 1
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

int main()
{
	TreeNode *head = new TreeNode(2);
	TreeNode *h1 = new TreeNode(1);
	TreeNode *h2 = new TreeNode(3);
	head->left = h1;
	head->right = h2;
	cout << isValidBST2(head) << endl;
	return 0;
}
