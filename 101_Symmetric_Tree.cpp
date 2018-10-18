/*101. Symmetric Tree 判断是否是对称的二叉树
	思路是用中序遍历方法
*/

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



/*我自己的思路是利用中序遍历，然后得到一个数组，判断数组是否是对称数组即可，但是这个问题就在于你数组的形成，要把空考虑进去
  这个方法不是很好。*/
// void helper(TreeNode*root,vector<int> &res)
// {
	// if(!root)
		// return ;
	// else
	// {
		// helper(root->left,res);
		// res.push_back(root->val);
		// helper(root->right,res);
	// }
	
	
// }

// bool isSymmetric(TreeNode* root)
// {
	// vector<int> res;
	// bool verit = true;
	// helper(root,res);
	// // cout<<"the elements is:"<<endl;
	// // for(auto i:res)
		// // cout<<i<<" ";
	// // cout<<endl;
	// int lenth = res.size();
	// for(int i =0;i<lenth/2;i++)
	// {
		// if(res[i]!=res[lenth-i-1])
		// {
			// verit = false;
			// break;
		// }		
	// }
	// return verit;
// }



/*第二种方法：也是最好的方法：*/



bool isSymmertic(TreeNode* left,TreeNode* right)
{
	if(!left && !right) return true;
	if(left && !right || !left && right || left->val != right->val)
		return false;
	return isSymmertic(left->left,right->right) && isSymmertic(left->right,right->left);
}


bool isSymmetric(TreeNode* root)
{
	if(!root) return true;
	return isSymmertic(root->left,root->right);
	
}





int main()
{
	TreeNode *head = new TreeNode(1);
	TreeNode *h1 = new TreeNode(2);
	TreeNode *h2 = new TreeNode(2);
	TreeNode *h3 = new TreeNode(3);
	TreeNode *h4 = new TreeNode(4);
	TreeNode *h5 = new TreeNode(4);
	TreeNode *h6 = new TreeNode(3);
	head->left = h1;
	head->right = h2;
	h1->left = h3;
	h1->right = h4;
	h2->left = h5;
	h2->right = h6;
	// Solution ss;
	cout<<isSymmetric(head);
	

	
	return 0;
}


























































