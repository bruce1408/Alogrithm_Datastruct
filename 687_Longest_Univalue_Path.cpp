/*

Input:

              5
             / \
            4   5
           / \   \
          1   1   5

Output:2


Example 2:

			Input:

              1
             / \
            4   5
           / \   \
          4   4   5
		  
		  
Output:2

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


class Solution 
{
	public:
    int longestUnivaluePath(TreeNode* root) 
	{
        if (!root) return 0;
        int sub = max(longestUnivaluePath(root->left), longestUnivaluePath(root->right));
        return max(sub, helper(root->left, root->val) + helper(root->right, root->val));
    }
    int helper(TreeNode* node, int parent) 
	{
        if (!node || node->val != parent) return 0;
        return 1 + max(helper(node->left, node->val), helper(node->right, node->val));
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
	cout<<ss.longestUnivaluePath(head);
	
	
	return 0;
}