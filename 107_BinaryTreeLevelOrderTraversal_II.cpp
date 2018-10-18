#include<iostream>
using namespace std;

struct TreeNode 
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<vector<int>> levelOrderBottom(TreeNode* root)
{
	vector<int> count;
	if(root->left && root->right)
	{
		count.push_back(root->val);
		return count;
	}
	else if(root->left || root->right)
		
	
}






int main()
{
	TreeNode* p = new TreeNode(3);
	TreeNode* head = new TreeNode(3);
	TreeNode* h1 = new TreeNode(9);
	TreeNode* h2 = new TreeNode(20);
	TreeNode* h3 = new TreeNode(15);
	TreeNode* h4 = new TreeNode(7);
	head->left = h1;
	head->right = h2;
	h2->left = h3;
	h2->right = h4;
	
	
	return 0;
}
