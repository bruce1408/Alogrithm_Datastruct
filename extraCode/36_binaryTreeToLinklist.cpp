
#include<iostream>
using namespace std;

struct TreeNode
{
	int val;
	TreeNode*left;
	TreeNode*right;
	TreeNode(int x):val(x),left(NULL),right(NULL) {}
};


void convertNode(TreeNode *head,TreeNode *listlast)
{
	if(head==nullptr) return ;
	TreeNode *cur = head;
	if(cur->left!=nullptr) convertNode(cur->left,listlast);
	cur->left = listlast;
	if(listlast!=nullptr) listlast->right = cur;
	listlast = cur;
	if(cur->right!=nullptr) convertNode(cur->right,listlast);

}
//inorder print binarytree
TreeNode *inorderTrave(TreeNode *head)
{
  TreeNode* listlast = nullptr ;
	convertNode(head,listlast);

	TreeNode *listfirst = listlast;
	while(listfirst!=nullptr && listfirst->left!=nullptr)
	{
		listfirst = listfirst->left;
	}

	return listfirst;

}



int main()
{
  // create a binary tree
  TreeNode *head = new TreeNode(10);
	TreeNode *h1 = new TreeNode(6);
	TreeNode *h2 = new TreeNode(14);
	TreeNode *h3 = new TreeNode(4);
	TreeNode *h4 = new TreeNode(8);
	TreeNode *h5 = new TreeNode(12);
	TreeNode *h6 = new TreeNode(16);
	head->left = h1;
	head->right = h2;
	h1->left = h3;
	h1->right = h4;
	h2->left = h5;
	h2->right = h6;
	TreeNode * tmp;
  tmp = inorderTrave(head);
}
