/*98. Validate Binary Search Tree 


   2
   / \
  1   3
Binary tree [2,1,3], return true.


Example 2:
    1
   / \
  2   3
Binary tree [1,2,3], return false.


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
	TreeNode(int x):val(x),left(NULL),right(NULL) {}
};



bool isValidBST(TreeNode* root)
{
	vector<int>res;
	TreeNode* p;
	stack<TreeNode*>Q;
	p = root;
	bool flag = true;
	while(p || !Q.empty())
	{
		while(p && flag)
		{
			Q.push(p);
			p = p->left;
		}
		if(!Q.empty())
		{
			p = Q.top();
			Q.pop();
			res.push_back(p->val);
			p = p->right;
			if(res.back()>Q.top()->val)
			{
				flag = false;
			}
		}
	}
	return flag;
}







int main()
{
	TreeNode* head = new TreeNode(2);
	TreeNode* h1 = new TreeNode(1);
	TreeNode* h2 = new TreeNode(3);
	head->left = h1;
	head->right = h2;
	cout<<isValidBST(head);
	return 0;
}






















































