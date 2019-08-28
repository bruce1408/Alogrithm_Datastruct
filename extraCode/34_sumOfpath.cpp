/*113 112  129 都是很像的类型题目

Given the below binary tree and sum = 22,
              5
             / \
            4   8
           /   / \
          11  13  4
         /  \    / \
        7    2  5   1
return
[[5,4,11,2],[5,8,4,5]]

*/


#include<iostream>
#include<stack>
#include<vector>

using namespace std;

struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x):val(x),left(NULL),right(NULL) {}
};


class Solution

{
	public:
	vector<vector<int>> pathSum(TreeNode* root, int sum)
	{
			vector<int>temp;
			vector<vector<int>>res;
			helper(root,sum,temp,res);
			return res;

	}
	void helper(TreeNode*root,int sum,vector<int>& temp,vector<vector<int>>& res)
	{
		if(!root) return ;

		temp.push_back(root->val);
		if(root->val==sum && !root->left &&!root->right) res.push_back(temp);
		helper(root->left,sum-root->val,temp,res);
		helper(root->right,sum-root->val,temp,res);
		temp.pop_back();// 删除上一个不符合的节点
	}
};


//方法2 书上的思路是利用栈的先进后出性质来做
class Solution2
{
	public:
	void pathSumStack(TreeNode*root,int sum)
	{
		if(root==nullptr) return ;
		vector<int> temp;
		int currentSum = 0;

		findPath(root,sum,temp,currentSum);
	}

	void findPath(TreeNode*root,int sum,vector<int>&temp,int currentSum)
	{
		currentSum += root->val;
		temp.push_back(root->val);
		bool isLeaf=root->left==nullptr &&root->right==nullptr;
		if(currentSum==sum &&isLeaf)


		if(root->val==sum &&! root->left &&! root->right)

		{
			cout<<"path is found"<<endl;
			for(auto i:temp)
			{
				cout<<i<<" ";
			}
			cout<<endl;
		}

		if(root->left!=nullptr) findPath(root->left,sum,temp,currentSum);
		if(root->right!=nullptr) findPath(root->right,sum,temp,currentSum);
		temp.pop_back();
	}
};




int main()
{

	TreeNode* head = new TreeNode(10);
	TreeNode* h1 = new TreeNode(5);
	TreeNode* h2 = new TreeNode(12);
	TreeNode* h3 = new TreeNode(4);
	TreeNode* h4 = new TreeNode(7);
	head->left = h1;
	head->right = h2;
	h1->left = h3;
	h1->right = h4;


	// Solution ss;
  // vector<vector<int>>res = ss.pathSum(head,22);
	// for(int i=0;i<res.size();i++)
	// {
	// 	for(int j=0;j<res[i].size();j++)
	// 	{
	// 		cout<<res[i][j]<<" ";
	// 	}
	// 	cout<<endl;
	// }
Solution2 ss;
ss.pathSumStack(head,22);
	return 0;
}
