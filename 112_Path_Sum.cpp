/*112. Path Sum  和 129非常类似，思路一样的
	Given the below binary tree and sum = 22,
	给你一个二叉树，然后看是否满足给定值是22的路径的和、

              5
             / \
            4   8
           /   / \
          11  13  4
         /  \      \
        7    2      1
return true, as there exist a root-to-leaf path 5->4->11->2 which sum is 22.

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

bool hasPathSum(TreeNode* root, int sum)
{
	if(!root) return false;
	if(root->val ==sum && root->left ==NULL && root-> right==NULL) return true;
	return hasPathSum(root->left,sum-root->val) || hasPathSum(root->right,sum-root->val);
	
}



int main()
{
	TreeNode* head = new TreeNode(2);
	TreeNode* h1 = new TreeNode(1);
	TreeNode* h2 = new TreeNode(3);
	head->left = h1;
	head->right = h2;
	cout<<hasPathSum(head,5);
	return 0;
}
















































