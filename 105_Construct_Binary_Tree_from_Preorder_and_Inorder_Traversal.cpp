/*105. Construct Binary Tree from Preorder and Inorder Traversal
*/

//已知前序和中序，来构造一课二叉树
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
	cur->right = buildNode(preorder,i+1+pleft-ileft,pright,inorder,i+1,iright);
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
	TreeNode*head;
	head = buildTree(inorder,postorder);
	return 0;
}





