/*
Binary Tree Maximum Path Sum 求二叉树的最大路径和
For example:
Given the below binary tree,

       1
      / \
     2   3
 

Return 6.


*/


#include<iostream>
#include<vector>


using namespace std;

struct TreeNode 
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x):val(x), left(NULL), right(NULL) {}
};


class Solution
{
	public:
	int helper(TreeNode*root,int &sum)
	{
		if(!root)
			return 0;
		int left = max(helper(root->left,sum),0);
		int right = max(helper(root->right,sum),0);
		sum = max(left+right+root->val,sum);
		return max(left,right) + root->val;
	}



	int maxPathSum(TreeNode* root)
	{
		int sum=0;
		helper(root,sum);
		return sum;
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
	
	Solution ss;
	cout<<ss.maxPathSum(head);
	return 0;
	
	
}
	
	

	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	