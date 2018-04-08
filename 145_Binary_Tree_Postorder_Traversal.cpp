/*145. Binary Tree Postorder Traversal
	二叉树的后序遍历
	
	
*/
	
	
	
#include<iostream>
#include<vector>
#include<stack>
using namespace std;

struct TreeNode 
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


//方法1；递归法
// void postTrave(TreeNode* root,vector<int> &res)
// {
	// if(!root)
		// return ;
	// else
	// {
		// postTrave(root->left,res);
		// postTrave(root->right,res);
		// res.push_back(root->val);
	// }
// }

// vector<int> postorderTraversal(TreeNode* root)
// {
	// vector<int>res;
	// postTrave(root,res);
	// return res;
// }

//方法2：非递归算法，最符合思路后序遍历的思路。
vector<int> postorderTraversal(TreeNode* root)
{
	vector<int> res;
	TreeNode* curNode;
	TreeNode* lastNode=NULL;
	stack<TreeNode*> Q;
	
	curNode = root;
	while(!Q.empty() || curNode)
	{
		if(curNode)  //所有的左节点入栈
		{
			Q.push(curNode);
			curNode = curNode->left;
		}
		else
		{
			TreeNode* topNode  = Q.top();  //对最后一个左节点判断是否有右节点
			if(topNode->right && topNode->right!=lastNode) 
				curNode = topNode->right;
			else  //没有的话输出，
			{
				res.push_back(topNode ->val);
				lastNode = topNode ;
				Q.pop();
			}
		}
	}
	return res;	
}




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
	vector<int> rest;
	rest = postorderTraversal(head);
	for(auto i:rest)
		cout<<i<<" ";
	
	
	return 0;
}


























