#include<iostream>
#include<vector>
#include<queue>
using namespace std;

struct TreeNode
{
	int val;
	TreeNode*left;
	TreeNode*right;
	TreeNode(int x):val(x),left(NULL),right(NULL) {}
};


/*
层序遍历，符合先进先出的性质，利用队列。
建立一个queue，然后先把根节点放进去，这时候找根节点的左右两个子节点，
这时候去掉根节点，此时queue里的元素就是下一层的所有节点，用一个for循环遍历它们，
然后存到一个一维向量里，遍历完之后再把这个一维向量存到二维向量里，以此类推，可以完成层序遍历
*/
void levelOrder(TreeNode*root)
{
	queue<TreeNode *> Q;
	TreeNode* q;
	if(!root)
		return ;
	Q.push(root);
	while(!Q.empty())
	{
		int n = Q.size();
		for(int i=0;i<n;i++)
		{			
			q = Q.front();
			Q.pop();
			cout<<q->val<<" ";
			if(q->left) Q.push(q->left);
			if(q->right) Q.push(q->right);
		}
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
	
	
	// vector<vector<int>> rest;
	levelOrder(head);
	// int n = rest.size();
	// cout<<n<<endl;
}