#include<iostream>
#include<vector>
#include<queue>
using namespace std;


struct TreeNode 
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x):val(x),left(NULL),right(NULL) {}
};



int levelOrder(TreeNode* root)
{
	int res = 0;
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
			if(i==0) res = q->val;
			if(q->left) Q.push(q->left);
			if(q->right) Q.push(q->right);
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
	
	int n = levelOrder(head);
	cout<<n;
	
	return 0;
}







































































