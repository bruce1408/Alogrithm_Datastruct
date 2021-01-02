#include <iostream>
#include <vector>
#include <stack>
using namespace std;
/*
层序遍历，输出每一层的节点的值，但是是之字形的，中间不是9，20，而是20，9
Given binary tree [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7
return its zigzag level order traversal as:
输出的结果[[3],[20,9],[15,7]]

*/

struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<vector<int>> zigzagLevelOrder(TreeNode *root)
{
	vector<vector<int>> res;
	stack<TreeNode *> s1;
	stack<TreeNode *> s2;
	vector<int> temp;
	s1.push(root);
	if (!root)
		return res;
	while (!s1.empty() || !s2.empty())
	{
		while (!s1.empty())
		{
			TreeNode *cur = s1.top();
			s1.pop();
			temp.push_back(cur->val);
			if (cur->left)
				s2.push(cur->left);
			if (cur->right)
				s2.push(cur->right);
		}
		if (!temp.empty())
			res.push_back(temp);
		temp.clear();
		while (!s2.empty())
		{
			TreeNode *cur = s2.top();
			temp.push_back(cur->val);
			s2.pop();
			if (cur->right)
				s1.push(cur->right);
			if (cur->left)
				s1.push(cur->left);
		}
		if (!temp.empty())
			res.push_back(temp);
		temp.clear();
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
	vector<vector<int>> rest;
	rest = zigzagLevelOrder(head);

	return 0;
}
