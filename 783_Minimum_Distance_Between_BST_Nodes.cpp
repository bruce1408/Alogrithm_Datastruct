
/*783 和 530 是一样，完全一样。求二叉搜索树的相邻的数的差值,中序遍历就是一个升序的数组，然后再把升序的数组，两两相减求最小！*/

#include<iostream>
using namespace std;


struct TreeNode
{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x):val(x),left(NULL),right(NULL){}
};



// class Solution 
// {
	// public:
    // int getMinimumDifference(TreeNode* root) 
	// {
        // int res = INT_MAX, pre = -1;
        // inorder(root, pre, res);
        // return res;
    // }
	
    // void inorder(TreeNode* root, int& pre, int& res) 
	// {
        // if (!root) return;
        // inorder(root->left, pre, res);
        // if (pre != -1) res = min(res, root->val - pre);
        // pre = root->val;
        // inorder(root->right, pre, res);
    // }
// };

void midTra(TreeNode*root,int &pre, int &res)
{
	if(!root) return;
	midTra(root->left,pre,res);
	if(pre!=-1) res = min(root->val-pre,res);
	pre = root->val;//这个非常重要！
	midTra(root->right,pre,res);
}

int getMinimumDifference(TreeNode* root) 
{
	
	int pre = -1;
	int res = INT_MAX;
	midTra(root,pre,res);
	return res;
}

 

int main()
{
	TreeNode *head = new TreeNode(2);
	TreeNode *h1 = new TreeNode(1);
	TreeNode *h2 = new TreeNode(4);
	
	head->left = h1;
	head->right = h2;
	
	
	cout<<getMinimumDifference(head)<<endl;
	
	
	
	
	return 0;
}

































