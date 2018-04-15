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



#include<iostream>
#include<vector>
using namespace std;


struct TreeNode 
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


vector<vector<int>> zigzagLevelOrder(TreeNode* root) 
{
	vector<TreeNode*> Q;
	TreeNode* q;
	vector<int> temp;
	if(!root)
		return {};
	else
	{
		int count = 0;
		Q.push(root);
		int n = Q.size();
		while(!Q.empty())
		{
			q = Q.front();
			Q.pop();
			temp.push_back(q->val);
			count++;
			
		}
	
	}
	
	
	
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































































































