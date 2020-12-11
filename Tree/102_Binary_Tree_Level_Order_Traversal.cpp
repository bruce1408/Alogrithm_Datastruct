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
void levelOrder_queue1(TreeNode *root)
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
 * 方法 2，使用两个队列来做，核心就是BFS宽度有限搜索；这里用了两个空间，可以继续优化
*/
vector<vector<int>> levelorder_queue2(TreeNode *root)
{
	vector<vector<int>> t;
	queue<TreeNode *> q;
	queue<TreeNode *> h;
	if (root == nullptr)
		return {};
	q.push(root);
	while (!q.empty())
	{
		vector<int> res;
		while (!q.empty())
		{
			TreeNode *temp = q.front();
			res.push_back(temp->val);
			q.pop();
			if (temp->left)
				h.push(temp->left);
			if (temp->right)
				h.push(temp->right);
		}
		t.push_back(res);
		while (!h.empty())
		{
			TreeNode *temp1 = h.front();
			q.push(temp1);
			h.pop();
		}
	}
	return t;
}

/**
 * 方法1：就是层序遍历的思想，用到的是队列，注意，两个循环，一个是判断是否为空，一个是对每一层的个数遍历；
 * */
vector<vector<int>> levelOrder(TreeNode *root)
{
	vector<vector<int>> res;
	queue<TreeNode *> Q;
	TreeNode *q;

	if (!root)
		return {};
	Q.push(root);
	while (!Q.empty())
	{
		vector<int> temp;
		int n = Q.size();
		while (n--)
		{
			q = Q.front();
			Q.pop();
			temp.push_back(q->val);
			if (q->left)
				Q.push(q->left);
			if (q->right)
				Q.push(q->right);
		}
		res.push_back(temp);
	}
	return res;
}

/**
 * 使用dfs来优化
*/
class Solution3
{
public:
	vector<vector<int>> ans;

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
	vector<vector<int>> levelOrder(TreeNode *root)
	{
		dfs(root, 0);

		return ans;
	}
};

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
	for (auto i : levelorder_queue(head))
	{
		for (auto j : i)
		{
			cout << j << " ";
		}
		cout << endl;
	}

	return 0;
}
