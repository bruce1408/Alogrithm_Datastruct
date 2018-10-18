/*230. Kth Smallest Element in a BST*/


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
    int kthSmallest(TreeNode* root, int k) 
	{
        return kthSmallestDFS(root, k);
    }
	
    int kthSmallestDFS(TreeNode* root, int &k) 
	{
        if (!root) return -1;
        int val = kthSmallestDFS(root->left, k);
        if (k == 0) return val;
        if (--k == 0) return root->val;
        return kthSmallestDFS(root->right, k);
    }
};



int main()
{
	TreeNode *head = new TreeNode(1);
	TreeNode *h1 = new TreeNode(2);
	TreeNode *h2 = new TreeNode(3);
	head->left = h1;
	head->right = h2;
	Solution ss;
	cout<<ss.kthSmallest(head,2);
	

	
	return 0;
}


















