/*129. Sum Root to Leaf Numbers 和112题目非常类似
	
从根结点到叶子求和

	1
   / \
  2   3
The root-to-leaf path 1->2 represents the number 12.
The root-to-leaf path 1->3 represents the number 13.

Return the sum = 12 + 13 = 25.
	
*/


#include<iostream>
#include<stack>
using namespace std;

struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x):val(x),left(NULL),right(NULL) {}
};



int pathsum(TreeNode*root,int sum)
{
	if(!root) return 0;
	sum = sum*10 + root->val;
	if(!root->left && !root->right) return sum;
	return pathsum(root->left,sum) + pathsum(root->right,sum);
	
}

int sumNumbers(TreeNode* root)
{
	
	return pathsum(root,0);
	
}



int main()
{
	TreeNode *p;
	TreeNode* head = new TreeNode(2);
	TreeNode* h1 = new TreeNode(1);
	TreeNode* h2 = new TreeNode(3);
	head->left = h1;
	head->right = h2;
	cout<<sumNumbers(p);
	
	return 0;
}















































































































