#include <iostream>
#include <vector>
#include <queue>
using namespace std;
/**
 * 对二叉树使用层序遍历
 * 这道题目和637思路一样，和107只是输出的时候有区别，其他都是一样的。 
 * 关联题目是637 ，107
 * 
 * Given binary tree [3,9,20,null,null,15,7],
 *   3
 *  / \
 * 9  20
 *   /  \
 *  15   7
 * return its level order traversal as 
 * 对树进行层序遍历，然后输出。
 * output [[3],[9,20],[15,7]]
*/
struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/**
 * 方法 1，单纯打印，不要两层循环，层序遍历使用BFS的思路来做即可
 * 使用队列来实现二叉树的层序遍历，对于这道题来说，打印出来的写法显然不够
 * 还需要装进容器中输出出来
*/
void levelOrder1(TreeNode *root)
{
	if (root == nullptr)
		return;
	queue<TreeNode *> q;
	q.push(root);
	while (!q.empty())
	{
		TreeNode *temp = q.front();
		q.pop();
		cout << temp->val << " ";
		if (temp->left)
			q.push(temp->left);
		if (temp->right)
			q.push(temp->right);
	}
}

/**
 * 方法 2，BFS来做，用到的是队列实现，推荐做法;
 */
vector<vector<int> > levelOrder3(TreeNode *root)
{
	vector<vector<int> > res;
	queue<TreeNode *> q;
	if (root)
		q.push(root);
	while (q.size())
	{
		vector<int> level;
		int len = q.size();
		while (len--)
		{
			auto t = q.front();
			q.pop();
			level.push_back(t->val);
			if (t->left)
				q.push(t->left);
			if (t->right)
				q.push(t->right);
		}
		res.push_back(level);
	}
	return res;
}

/**
 * 方法 3，使用dfs来优化
*/
vector<vector<int> > ans;
void dfs(TreeNode *root, int level)
{
	if (!root)
		return;
	if (level == ans.size())
	{
		ans.push_back({});
	}
	ans[level].push_back(root->val);
	dfs(root->left, level + 1);
	dfs(root->right, level + 1);
}

vector<vector<int> > levelOrder4(TreeNode *root)
{
	dfs(root, 0);
	return ans;
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
	// vector<vector<int>> rest;
	// rest = levelOrder(head);
	// int n = rest.size();
	// cout << n << endl;
	// levelOrder_stack(head);
	for (auto i : levelOrder3(head))
	{
		for (auto j : i)
		{
			cout << j << " ";
		}
		cout << endl;
	}

	return 0;
}
