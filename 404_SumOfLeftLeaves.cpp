/*
	404. Sum of Left Leaves  这个题目和 104. Maximum Depth of Binary Tree  
	思路非常相似！！
	如果此题目改成判断右子树的时候应该怎么办？

  3
 / \
9  20
  /  \
 15   7
 
输出的是左边叶子的和(sum)
There are two left leaves in the binary tree, 
with values 9 and 15 respectively. Return 24.
	
*/

#include<iostream>
using namespace std;

struct TreeNode 
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void preThrough(TreeNode * head)
{
	if(head)
	{
		cout<<head->val<<"->";
		preThrough(head->left);
		preThrough(head->right);
	}
	
}



class Solution
{
	public:
	int sumOfLeftLeaves(TreeNode *root)
	{
		int leftsum = 0;
		if(!root)// 首先判断，是否是空
			return 0;
		//去掉左子树是有孩子节点的情况；
		if(root->left && !root->left->left && !root->left->right) //这一部分的逻辑非常重要，如果是右子树一样的情况
			return root->left->val + sumOfLeftLeaves(root->right);
		//如果上述都不满足的话，再以根节点的左子树和右子树再为根节点继续递归判断
		return sumOfLeftLeaves(root->left) + sumOfLeftLeaves(root->right);
		
	}
};



int main()
{
	
	TreeNode *head = new TreeNode(1);
	TreeNode* h1 = new TreeNode(2);
	TreeNode* h2 = new TreeNode(3);
	TreeNode* h3 = new TreeNode(4);
	TreeNode* h4 = new TreeNode(5);
	head->left = h1;
	head->right = h2;
	h1->left = h3;
	h1->right = h4;
	preThrough(head);
	cout<<"end"<<endl;
	Solution ss;
	
	cout<<ss.sumOfLeftLeaves(head)<<endl;
	
	//善后处理，释放内存，令其指向空
	delete head;
	delete h1;
	delete h2;
	delete h3;
	delete h4;
	head = nullptr;
	h1 = nullptr;
	h2 = nullptr;
	h3 = nullptr;
	h4 = nullptr;
	
	return 0;

}















































































