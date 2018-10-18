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


TreeNode *buildTree1(vector<int> &inorder, int iLeft, int iRight, vector<int> &postorder, int pLeft, int pRight) 
{
	if (iLeft > iRight || pLeft > pRight) return NULL;
	TreeNode *cur = new TreeNode(postorder[pRight]);
	int i = 0;
	for (i = iLeft; i < inorder.size(); ++i) 
	{
		if (inorder[i] == cur->val) break;
	}
	cur->left = buildTree1(inorder, iLeft, i - 1, postorder, pLeft, pLeft + i - iLeft - 1);
	cur->right = buildTree1(inorder, i + 1, iRight, postorder, pLeft + i - iLeft, pRight - 1);
	return cur;
}

TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) 
{
	return buildTree1(inorder, 0, inorder.size()-1, postorder, 0, postorder.size()-1);
}








int main()
{
	vector<int> inorder = {1,3,4,5,6};
	vector<int> postorder = {1,4,6,5,3};
	TreeNode*head;
	head = buildTree(inorder,postorder);
	
	return 0;
}