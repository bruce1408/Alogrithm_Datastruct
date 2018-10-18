/*257. Binary Tree Paths

   1
 /   \
2     3
 \
  5
  
All root-to-leaf paths are:

["1->2->5", "1->3"]


*/
#include<iostream>
#include<stack>
#include<string>
#include<vector>

using namespace std;

struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x):val(x),left(NULL),right(NULL) {}
};


void strpath(TreeNode* root,string temp,vector<string> &res)
{
	if(!root) return ;
	temp +=to_string(root->val);
	if(!root->left && !root->right)
		res.push_back(temp);
	/*有if判断和没有if判断都一样的。*/
	// if(root->left)  
		// strpath(root->left,temp+"->",res);
	// if(root->right)
		// strpath(root->right,temp+"->",res);
	strpath(root->left,temp+"->",res);
	strpath(root->right,temp+"->",res);
		
	
	
}

vector<string> binaryTreePaths(TreeNode* root)
{
	string temp;
	vector<string>res;
	strpath(root,"",res);
	return res;
}


int main()
{
	
	TreeNode* head = new TreeNode(1);
	TreeNode* h1 = new TreeNode(2);
	TreeNode* h2 = new TreeNode(3);
	TreeNode* h3 = new TreeNode(5);
	head->left = h1;
	head->right = h2;
	h1->right = h3;
	vector<string>res;
	res = binaryTreePaths(head);
	for(auto i:res)
		cout<<i<<" ";
	
	return 0;
}

































































