// 求二叉树的坡度,这个题目和124很想
//563. Binary Tree Tilt

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
	int findTilt(TreeNode* root)
	{
		int num=0;
		postTrav(root,num);
		return num;
	}



	int postTrav(TreeNode* root,int &num)
	{
		if(!root) return 0;
		int leftnum = postTrav(root->left,num);
		int rightnum = postTrav(root->right,num);
		num += abs(leftnum -rightnum);
		return leftnum + rightnum + root->val;
	}	
};



int main()
{
	
	TreeNode *head = new TreeNode(3);
	TreeNode *h1 = new TreeNode(9);
	TreeNode *h2 = new TreeNode(20);
	// TreeNode *h3 = new TreeNode(15);
	// TreeNode *h4 = new TreeNode(7);
	head->left = h1;
	head->right = h2;
	// h2->left = h3;
	// h2->right = h4;
	
	Solution ss;
	cout<<ss.findTilt(head);
	return 0;
	
	
}