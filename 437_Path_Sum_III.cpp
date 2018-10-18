/*437. Path Sum III
root = [10,5,-3,3,2,null,11,3,-2,null,1], sum = 8

      10
     /  \
    5   -3
   / \    \
  3   2   11
 / \   \
3  -2   1

Return 3. The paths that sum to 8 are:

1.  5 -> 3
2.  5 -> 2 -> 1
3. -3 -> 11

返回的是一个数的路径和满足要求的路径个数；

*/

#include<iostream>
#include<stack>
#include<vector>

using namespace std;

struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x):val(x),left(NULL),right(NULL) {}
};


class Solution
{
	public:
	int pathSum(TreeNode* root, int sum)
	{
		if(!root) return 0;
		return pathSum(root->left,sum)+pathSum(root->right,sum)+curpath(root,sum,0);
	}
	
	int curpath(TreeNode *root,int &sum,int p)
	{
		if(!root) return 0;
		p+=root->val;
		return (p==sum)+curpath(root->left,sum,p)+curpath(root->right,sum,p);	
	}
};



int main()
{
	
	TreeNode* head = new TreeNode(10);
	TreeNode* h1 = new TreeNode(5);
	TreeNode* h2 = new TreeNode(-3);
	TreeNode* h3 = new TreeNode(3);
	TreeNode* h4 = new TreeNode(2);
	TreeNode* h5 = new TreeNode(11);
	TreeNode* h6 = new TreeNode(3);
	TreeNode* h7 = new TreeNode(-2);
	TreeNode* h8 = new TreeNode(1);
	head->left = h1;
	head->right = h2;
	h1->left = h3;
	h1->right = h4;
	h2->right = h5;
	h3->left = h6;
	h3->right = h7;
	h4->right = h8;
	Solution ss;
	cout<<ss.pathSum(head,8);
	
	return 0;
}
























