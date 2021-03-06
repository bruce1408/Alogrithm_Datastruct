/*572. Subtree of Another Tree

这个题目是判断是否是子树。但是从剑指offer上看，exampl 2其实也是它的子树

Given tree s:

     3
    / \
   4   5
  / \
 1   2
 
Given tree t:
   4 
  / \
 1   2
 
Return true, because t has the same structure and node values with a subtree of s.

Example 2:
Given tree s:

     3
    / \
   4   5
  / \
 1   2
    /
   0
   
Given tree t:
   4
  / \
 1   2
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

/*-----------------------------------------------------------方法1-----------------------------------------------------*/
bool Dosetree(TreeNode*t1,TreeNode*t2)
{
	if(t2==nullptr)
		return true;
	if(t1==nullptr)
		return false;
	if(t1->val != t2->val)
		return false;
	return Dosetree(t1->left,t2->left) && Dosetree(t1->right,t2->right);
}

bool hasSubtree(TreeNode*t1, TreeNode*t2)
{
	bool result = false;
	if(t1 && t2)
	{
		if(t1->val==t2->val)
		{
			result = Dosetree(t1,t2);
		}
		if(!result)
		{
			result = hasSubtree(t1->left,t2);
		}
		if(!result)
		{
			result = hasSubtree(t1->right,t2);
		}
	}
	return result;
	
}




int main()
{
	TreeNode *head1 = new TreeNode(3);
	TreeNode *h1 = new TreeNode(9);
	TreeNode *h2 = new TreeNode(20);
	TreeNode *h3 = new TreeNode(15);
	TreeNode *h4 = new TreeNode(7);
	head1->left = h1;
	head1->right = h2;
	h1->left = h3;
	h1->right = h4;
	
	TreeNode *head2 = new TreeNode(9);
	TreeNode *h21 = new TreeNode(15);
	TreeNode *h22 = new TreeNode(7);
	head2->left = h21;
	head2->right = h22;
	
	cout<<hasSubtree(head1,head2);
	
	return 0;
}



















