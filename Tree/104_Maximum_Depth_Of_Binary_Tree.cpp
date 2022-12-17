
/*104. Maximum Depth of Binary Tree  和 404. Sum of Left Leaves  思路非常相似，几乎就是一道题目*/

#include<iostream>
using namespace std;
struct  TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


//前向遍历方法：
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
	int maxDepth(TreeNode* root)
	{
		//这个是少了边界条件，就是判断什么都不输入的时候，或者是空指针的时候，返回的值应该是0
		if(!root)     //增强代码的鲁棒性
			return 0; 
		if(!root->left && !root->right)
			return 1;
		if(root->left || root->right)
			return 1+max(maxDepth(root->left),maxDepth(root->right));
	
	}
	
};




int main()
{
	
	TreeNode* q = new TreeNode(1);
	TreeNode* m ;
	// TreeNode* p = new TreeNode(2);
	TreeNode* h1 = new TreeNode(2);
	TreeNode* h2 = new TreeNode(1);
	TreeNode* h3 = new TreeNode(3);
	TreeNode* h4 = new TreeNode(1);

	q->left = h1;
	q->right = h2;
	h2->left = h3;
	h2->right = h4;
	
	preThrough(q);
	cout<<"end"<<endl;
	Solution ss;
	
	cout<<ss.maxDepth(m)<<endl;
	
	
	//善后处理，释放内存，令其指向空
	delete q;
	delete h1;
	delete h2;
	delete h3;
	delete h4;
	
	q = nullptr;
	h1 = nullptr;
	h2 = nullptr;
	h3 = nullptr;
	h4 = nullptr;
	
	return 0;

}





































