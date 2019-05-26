#include<iostream>
#include<vector>
#include<stack>
using namespace std;


//用两个栈，然后一个先从左子树进栈，一个是从右子树进栈，然后才能打印出z的顺序(画图解决)
struct TreeNode
{
	int val;
	TreeNode*left;
	TreeNode*right;
	TreeNode(int x):val(x),left(NULL),right(NULL) {}
};


void levelOrder(TreeNode*root)
{
	vector<vector<int>>res;
	stack<TreeNode*>s1;
	stack<TreeNode*>s2;
	vector<int> temp;
	s1.push(root);
	if(!root) return ;
	while(!s1.empty() ||!s2.empty())
	{
		while(!s1.empty())
		{
			TreeNode*cur = s1.top();
			s1.pop();
			cout<<cur->val<<" ";
			if(cur->left) s2.push(cur->left);
			if(cur->right) s2.push(cur->right);
		}
		cout<<endl;
		if(!temp.empty()) res.push_back(temp);
		
		while(!s2.empty())
		{
			TreeNode*cur = s2.top();
			cout<<cur->val<<" ";
			s2.pop();
			if(cur->right) s1.push(cur->right);
			if(cur->left) s1.push(cur->left);
		}
		cout<<endl;
		
	}

}


int main()
{
	TreeNode *head = new TreeNode(8);
	TreeNode *h1 = new TreeNode(6);
	TreeNode *h2 = new TreeNode(10);
	TreeNode *h3 = new TreeNode(5);
	TreeNode *h4 = new TreeNode(7);
	TreeNode *h5 = new TreeNode(9);
	TreeNode *h6 = new TreeNode(11);
	head->left = h1;
	head->right = h2;
	h1->left = h3;
	h1->right = h4;
	h2->left = h5;
	h2->right = h6;
	
	levelOrder(head);
	
}