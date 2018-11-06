/*
这道题目和637思路一样，和107只是输出的时候有区别，其他都是一样的。 
关联题目是637 ，107

Given binary tree [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7
return its level order traversal as:
对树进行层序遍历，然后输出。
output [[3],[9,20],[15,7]]

*/


#include<iostream>
#include<vector>
#include<queue>
using namespace std;

struct TreeNode 
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


//方法1：就是层序遍历的思想，用到的是队列
//注意，两个循环，一个是判断是否为空，一个是对每一层的个数遍历；
vector<vector<int>> levelOrder(TreeNode* root)
{
	vector<vector<int>> res;
	queue<TreeNode*> Q;
	TreeNode* q;

	if(!root) return {};
	Q.push(root);
	while(!Q.empty())
	{
		vector<int> temp;
		int n = Q.size();
		for(int i=0;i<n;i++)
		{
			q = Q.front();
			Q.pop();
			temp.push_back(q->val);
			if(q->left) Q.push(q->left);
			if(q->right) Q.push(q->right);
		}
		res.push_back(temp);	
	}
	return res;	
}



// 方法2：递归。
class Solution 
{
	public:
    vector<vector<int>> levelOrder(TreeNode* root) 
	{
        vector<vector<int> > res;
        levelorder(root, 0, res);
        return res;
    }
    void levelorder(TreeNode *root, int level, vector<vector<int> > &res) 
	{
        if (!root) return;
        if (res.size() == level) res.push_back({});
        res[level].push_back(root->val);
        if (root->left) levelorder(root->left, level + 1, res);
        if (root->right) levelorder(root->right, level + 1, res);
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
	vector<vector<int>> rest;
	rest = levelOrder(head);
	int n = rest.size();
	cout<<n<<endl;
	
	
	return 0;
}









































































