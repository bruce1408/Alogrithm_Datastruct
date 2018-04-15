/*110 和 104 很类似，不过这个是判断平衡二叉树，还有判断最小二叉树的题目。判断是否是平衡二叉树。从树的深度来入手判断这个题目*/

#include<iostream>
#include<vector>
using namespace std;

struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x):val(x),left(NULL),right(NULL) {}
};



/*  depthTree  函数是判断树的深度的函数*/
int depthTree(TreeNode* root)
{
	int depth=0;
	if(!root)
		return 0;
	return max(depthTree(root->left)+1,depthTree(root->right)+1);
}

bool isBalanced(TreeNode*root)
{
	if(!root)
		return true;
	if(abs(depthTree(root->left) - depthTree(root->right)) >1)
		return false;
	return isBalanced(root->left) && isBalanced(root->right); // 非常重要的一个环节！左子树和右子树必须同时满足才可以！
}


int main()
{
	
	TreeNode *head1 = new TreeNode(22);
	TreeNode *head = new TreeNode(3);
	TreeNode *h1 = new TreeNode(9);
	TreeNode *h2 = new TreeNode(20);
	TreeNode *h3 = new TreeNode(15);
	TreeNode *h4 = new TreeNode(7);
	head->left = h1;
	head->right = h2;
	h2->left = h3;
	h2->right = h4;
	
	// cout<<depthTree(head1)<<endl;
	cout<<isBalanced(head1);
	return 0;
	
	
}




























