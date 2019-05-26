#include<iostream>
#include<vector>
using namespace std;

/**
 * 题目：重建二叉树，给定二叉树的前序和中序结果，然后重建二叉树
 * 方法1 前序遍历的算法是DLR(根左右)，中序遍历LDR(左根右)，后序遍历LRD(左右根)
 * 思路：
 * 思路就是利用各种遍历算法的原理分析，写出代码
 * 
*/
struct TreeNode 
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* buildNode(vector<int>& preorder,int pleft,int pright,vector<int>& inorder, int ileft, int iright)
{
	if(pleft>pright || ileft >iright) return NULL;
	TreeNode*cur = new TreeNode(preorder[pleft]);
	int i=0;
	for(i=ileft;i<=iright;i++)
	{
		if(inorder[i]==cur->val) break;
	}
	
	cur->left = buildNode(preorder,pleft+1,pleft+i-ileft, inorder,ileft,i-1);
	cur->right = buildNode(preorder,pleft-ileft+i+1,pright,inorder,i+1,iright);
	return cur;
}

TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder)
{
	return buildNode(preorder,0,preorder.size()-1,inorder,0,inorder.size()-1);
}


int main()
{
	vector<int> inorder = {1,3,4,5,6};
	vector<int> postorder = {1,4,6,5,3};
	TreeNode* head;
	head = buildTree(inorder,postorder);
	return 0;
}

// TreeNode* buildNode1(vector<int>&ind, vector<int>&pos, int ileft, int iright, int pleft, int pright)
// {
// 	if(ileft>iright || pleft > pright) return nullptr;
// 	TreeNode* t = new TreeNode(pos[pleft]);
// 	for(int i=0;i<iright;i++)
// 	{
// 		if(t->val == ind[i])
// 		{
// 			break;
// 		}
// 		t->left = buildNode1(ind, pos, ileft, i-1, pleft+1,pleft-ileft+i);
// 		t->right = buildNode1(ind, pos, i+1, iright, pleft-ileft+i+1, pright);
// 	}
// 	return t;
// }

// TreeNode* buildTree1(vector<int> &ind, vector<int>&pos)
// {
// 	return buildNode1(ind, pos, 0, ind.size()-1, 0, pos.size()-1);
// }




























