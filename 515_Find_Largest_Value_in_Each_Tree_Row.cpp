/*515. Find Largest Value in Each Tree Row
	寻找二叉树每一层的最大的节点，思路就是层序遍历方法：
*/



#include<iostream>
#include<vector>
#include<queue>
using namespace std;


struct TreeNode 
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x):val(x),left(NULL),right(NULL) {}
};



vector<int> largestValues(TreeNode* root)
{	
	queue<TreeNode*> Q;
	TreeNode* q;
	vector<int> res;
	

	if(!root) return {};
	Q.push(root);
	while(!Q.empty())
	{
		int max_num  = INT_MIN;
		vector<int> temp;
		int n = Q.size();
		for(int i=0;i<n;i++)
		{
			q = Q.front();
			if(q->val > max_num)
				max_num = q->val;
			Q.pop();
			if(q->left) Q.push(q->left);
			if(q->right) Q.push(q->right);
		}
		res.push_back(max_num);
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
	vector<int> res;
	res = largestValues(head);
	for(auto i:res)
		cout<<i<<" ";
	
	return 0;
}

























































































































