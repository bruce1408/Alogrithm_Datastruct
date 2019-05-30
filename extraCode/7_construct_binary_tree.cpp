#include<iostream>
#include<vector>
using namespace std;

/**
 * 题目：重建二叉树，给定二叉树的前序和中序结果，然后重建二叉树
 * 方法1 前序遍历的算法是DLR(根左右)，中序遍历LDR(左根右)，后序遍历LRD(左右根)
 * 思路：
 * 利用中序遍历和前序遍历的特点，找到中序遍历的根节点root位置索引index，用递归构建根节点的
 * 左子树和右子树，重点是左子树的范围和右子树的递归范围；
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
	/**
	 * 这个区间可以这么理解，i就是中序的根节点的位置，
	 * 左子树的前序遍历的范围是从(pleft+1, pleft + 中序遍历时候的根节点的位置i-ileft)
	 * 中序遍历时候的节点位置 i 减去 ileft 表示中序遍历的长度，然后 pleft 加上这个长度；
	 * 所以左子树的前序遍历范围是从 pleft+1 到 pleft+i-ileft 
	 * 左子树的中序遍历范围比较简单，就是ileft，i-1
	 * 
	 * 右子树的前序遍历的范围是 pleft+i-ileft+1 到 pright，和左子树前序范围相差1，
	 * 右子树的中序遍历的范围是 i+1 到 iright。
	 * */ 
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




























