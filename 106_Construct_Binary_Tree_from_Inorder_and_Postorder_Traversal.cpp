//后序和中序来构建一个二叉树
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
	TreeNode *cur = new TreeNode(postorder[pRight]);//设一个节点存后序的最后一个值，也就是根节点的值
	int i = 0;
	for (i = iLeft; i < inorder.size(); ++i)        // 在中序中找到这个根节点的数。
	{
		if (inorder[i] == cur->val) break;
	}
	//从根节点分成两段，左边在递归找到根节点是左子树，右边递归找根节点是右子树。不断递归，下标的起始位置要注意
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