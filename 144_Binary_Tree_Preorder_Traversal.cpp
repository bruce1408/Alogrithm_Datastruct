/*
144. Binary Tree Preorder Traversal
二叉树的前序遍历方法

*/


#include<iostream>
#include<vector>
#include<stack>
using namespace std;

struct TreeNode 
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

//方法1：前序遍历递归算法
void qianxu(TreeNode* root,vector<int> &res)
{
	if(!root) return;
	else
	{
		res.push_back(root->val);
		qianxu(root->left,res);
		qianxu(root->right,res);
	}
}

vector<int> preorderTraversal(TreeNode* root)
{
	vector<int>res;
	qianxu(root,res);
	return res;
}


//方法2.1：非递归算法，利用栈的思想
vector<int> preorderTraversal(TreeNode* root)
{
	stack<TreeNode*>Q;
	TreeNode* p;
	vector<int>res;
	if(!root) return {};
	p = root;
	while(!Q.empty() || p)
	{
		while(p)
		{
			res.push_back(p->val);
			Q.push(p);
			p = p->left;
		}
		if(!Q.empty())
		{
			p = Q.top();
			Q.pop();
			p = p->right;
		}
	}
	return res;
}

//方法2.2 非递归算法，没有while，只用了判断语句。
class Solution 
{
	public:
    vector<int> preorderTraversal(TreeNode* root) 
	{
        vector<int> res;
        stack<TreeNode*> s;
        TreeNode *p = root;
        while (!s.empty() || p) 
		{
            if (p) 
			{
                s.push(p);
                res.push_back(p->val);
                p = p->left;
            } 
			else 
			{
                TreeNode *t = s.top(); s.pop();
                p = t->right;
            }
        }
        return res;
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
	vector<int> rest;
	Solution ss;
	
	rest = ss.preorderTraversal(head);
	for(auto i:rest)
		cout<<i<<" ";
	
	
	return 0;
}
















