/*617. Merge Two Binary Trees

这两种方法都很好，第一种是按照逻辑思路加递归的方法来做，第二个解法是按照递归方法。

Example 1:

Input: 

	Tree 1                     Tree 2                  
          1                         2                             
         / \                       / \                            
        3   2                     1   3                        
       /                           \   \                      
      5                             4   7                  
Output: 

Merged tree:
	     3
	    / \
	   4   5
	  / \   \ 
	 5   4   7
*/

/*94. Binary Tree Inorder Traversal
二叉树的中序遍历


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
void mergeT(TreeNode*t1,TreeNode*t2,TreeNode*&head)
{
	
	if(!t1&&!t2)
		return;
	else if(t1 && !t2)
	{
		head = new TreeNode(t1->val);
		mergeT(t1->left,NULL,head->left);
		mergeT(t1->right,NULL,head->right);
	}
	else if(t2 && !t1)
	{
		head = new TreeNode(t2->val);
		mergeT(t2->left,NULL,head->left);
		mergeT(t2->right,NULL,head->right);
	}
	else
	{
		head = new TreeNode(t2->val+t1->val);
		mergeT(t1->left,t2->left,head->left);
		mergeT(t1->right,t2->right,head->right);
	}
		
	
}

TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2)
{
	TreeNode *head ;
	
	mergeT(t1,t2,head);
	return head;
}

void print_tree(TreeNode* root)
{
	if(!root)
		return ;
	cout<<root->val<<" ";
	print_tree(root->left);
	print_tree(root->right);
	
}

/*--------------------------------------------------------方法2-----------------------------------------------------*/
TreeNode* mergeTrees1(TreeNode* t1, TreeNode* t2)
{
	if(!t1)
		return t2;
	if(!t2)
		return t1;
	TreeNode* head = new TreeNode(t1->val + t2->val);
	head->left = mergeTrees(t1->left,t2->left);
	head->right = mergeTrees(t1->right,t2->right);
	return head;
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
	
	TreeNode *head2 = new TreeNode(1);
	TreeNode *h21 = new TreeNode(2);
	TreeNode *h22 = new TreeNode(3);
	head2->left = h21;
	head2->right = h22;
	
	TreeNode*head3;
	// head3 = mergeTrees(head,head2);
	// print_tree(head3);
	
	
	head3 = mergeTrees1(head,head2);
	print_tree(head3);
	
	return 0;
}



















